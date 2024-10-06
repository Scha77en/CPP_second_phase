/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 09:08:07 by aouhbi            #+#    #+#             */
/*   Updated: 2024/10/06 06:43:03 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstddef>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdexcept>

Btc::Btc(const std::string DataF) {
	loadData(DataF);
}

Btc::~Btc() {}

void Btc::loadData(const std::string DataF) {
	std::ifstream file(DataF.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	int i = 0;
	std::string line;
	while(std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date, value_s;
		if (i == 0) {
			if (std::getline(ss, date, ',') && std::getline(ss, value_s)) {
				if (date != "date" || value_s != "exchange_rate") {
					std::string error = "Error: bad input => " + line;
					throw std::runtime_error(error);
				}
				i++;
				continue;
			}
		}
		if (std::getline(ss, date, ',') && std::getline(ss, value_s)) {
			double value_f = std::atof(value_s.c_str());
			DataBase[date] = value_f;
		}
		else 
			throw std::runtime_error("Error: Failed to read line from file."); 
	}
}

std::string Trim(std::string &s) {
	std::string::size_type start = s.find_first_not_of("\r\n\t\v\f ");
	std::string::size_type end = s.find_last_not_of("\r\n\t\v\f ");
	if (start == std::string::npos)
		return "";
	return (s.substr(start, end - start + 1));
}

void    Btc::Check_Input(const std::string Input) const {
	std::ifstream file(Input.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: couldn't open Input file.");
	std::string line;
	int i = 0;
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date, pipe, value;
		if (i == 0) {
			i++;
			try {
				ss >> date >> pipe >> value;
				if (date != "date" || pipe != "|" || value != "value" || ss.peek() != EOF) {
					std::string error = "Error: bad input => [" + line + "] --> expected: [date | value]";
					throw std::runtime_error(error);
				}
			}
			catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
		}
		else if (std::getline(ss, date, '|') && std::getline(ss, value)) {
			date = Trim(date);
			value = Trim(value);
			try {
				Date_Check(date);
			}
			catch (const std::exception &e) {
				std::cerr << "Error: " << e.what() << " | bad input [3]=> " << ss.str() << std::endl;
				continue;
			}
			float value_f = 0;
			try {
				value_f = Value_Check(value);
			}
			catch (const std::exception &e) {
				std::cerr << "Error: " << e.what() << std::endl;
				continue;
			}
			float exch = Get_Exch_Rate(date);
			std::cout << date << " => " << exch << " = " << (exch * value_f) << std::endl;
		}
		else {
			std::cerr << "Error: bad input => " << line << std::endl;
		}
	}
	if (i == 0)
		throw std::runtime_error("Error: empty file.");
}

bool	Btc::Date_Check(const std::string Date) const {
	if (Date.size() != 10 || Date[4] != '-' || Date[7] != '-')
		throw std::runtime_error("bad date format");
	std::string year  = Date.substr(0, 4);
	std::string month = Date.substr(5, 2);
	std::string day   = Date.substr(8, 2);
	if (year.find_first_not_of("0123456789") != std::string::npos || year[0] != '2')
		throw std::runtime_error("bad year input");
	if (month.find_first_not_of("0123456789") != std::string::npos)
		throw std::runtime_error("bad month input");
	if (day.find_first_not_of("0123456789") != std::string::npos)
		throw std::runtime_error("bad day input");
	int y = std::atoi(year.c_str()); int m = std::atoi(month.c_str()); int d = std::atoi(day.c_str());
	Check_year(y);
	Check_month(m);
	Check_day(d, m, y);
	return true;
}

float	Btc::Value_Check(const std::string Value) const {
	std::stringstream ss(Value);
	float v;
	if (!(ss >> v))
		throw std::runtime_error("not a number");
	if (ss.peek() != EOF)
		throw std::runtime_error("not a number or extra data.");
	if (v < 0.0f)
		throw std::runtime_error("not a positive number.");
	if (v > 1000.0f)
		throw std::runtime_error("too large a number.");
	return v;
}

float Btc::Get_Exch_Rate(const std::string date) const {
	std::map<std::string, float>::const_iterator it = DataBase.lower_bound(date);
	if (it == DataBase.begin())
		return it->second;
	if (it->first != date || it == DataBase.end())
		it--;
	return it->second;
}

void Btc::Check_year(int y) const {
	if (y < 2000 || y > 2024)
		throw std::runtime_error("year out of range");
}

void Btc::Check_month(int m) const {
	if (m < 1 || m > 12)
		throw std::runtime_error("month out of range");
}

void Btc::Check_day(int d, int m, int y) const {
	if (d < 1 || d > 31)
		throw std::runtime_error("day out of range");
	if (m == 2) {
		if (d > 29)
			throw std::runtime_error("day out of range");
		if (d == 29 && ((y % 4 != 0) || (y % 100 == 0 && y % 400 != 0)))
			throw std::runtime_error("day out of range");
	}
	if (m == 4 || m == 6 || m == 9 || m == 11) {
		if (d > 30)
			throw std::runtime_error("day out of range");
	}
}