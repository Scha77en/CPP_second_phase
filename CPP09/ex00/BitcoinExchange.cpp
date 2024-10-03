/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 09:08:07 by aouhbi            #+#    #+#             */
/*   Updated: 2024/09/08 23:20:06 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
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
	int i = -1;
	i++;
	std::string line;
	while(std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date, value_s;
		if (i == 0) {
			if (std::getline(ss, date, ',') && std::getline(ss, value_s)) {

				// std::cout << CYAN "Date[2] ==> " << date << RESET << std::endl;

				// std::cout << CYAN "Value[2] ==> " << value_s << RESET << std::endl;
				if (date != "date" || value_s != "exchange_rate") {
					std::string error = "Error: bad input => " + line;
					throw std::runtime_error(error);
				}
				i++;
				continue;
			}
		}
		if (std::getline(ss, date, ',') && std::getline(ss, value_s)) {
			// std::cout << "date ==> " << date << std::endl << "value_s ==> " << value_s << std::endl;
			float value_f = std::atof(value_s.c_str());
			DataBase[date] = value_f;
		}
		else 
			throw std::runtime_error("Error: Failed to read line from file."); 
	}
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
				if (date != "date" || pipe != "|" || value != "value") {
					std::string error = "Error: bad input => " + line + " --> expected: date | value";
					throw std::runtime_error(error);
				}
			}
			catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
		}
		else if (std::getline(ss, date, '|') && std::getline(ss, value)) {
			// if (date.empty()) {
			// 	std::cerr << "Error: bad input => " << line << std::endl;
			// 	continue;
			// }
			std::istringstream iss(date);
			iss >> date;
			// std::cout << CYAN "Date ==> " << date << RESET << std::endl;
			std::istringstream iss2(value);
			iss >> value;
			// std::cout << CYAN "Value ==> " << value << RESET << std::endl;
		
			try {				
				Date_Check(date);
			}
			catch (const std::exception &e) {
				std::cerr << "Error: " << e.what() << " | bad input => " << date << std::endl;
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
}

bool	Btc::Date_Check(const std::string Date) const {
	if (Date.size() != 10 || Date[4] != '-' || Date[7] != '-')
		throw std::runtime_error("bad date format");
	std::stringstream ss(Date);
	std::string year, month, day;
	if (std::getline(ss, year, '-') && std::getline(ss, month, '-') && std::getline(ss, day)) {
			// int y, m, d;
			
			// y << year;
		ss.clear();
		ss.str(year);
		int y, m, d;
		if (!(ss >> y) || !(ss >> m) || !(ss >> d))
			throw std::runtime_error("bad date format");
		std::cout << "y ==> " << y << std::endl;
		std::cout << "m ==> " << m << std::endl;
		std::cout << "d ==> " << d << std::endl;
		Check_year(y);
		Check_month(m);
		Check_day(d, m, y);
		// if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
			// leap = true;
	}
	return true;
}

float	Btc::Value_Check(const std::string Value) const {
	std::stringstream ss(Value);
	float v;
	if (!(ss >> v))
		throw std::runtime_error("not a number");
	while (ss.peek() == ' ')
		ss.ignore();
	if (ss.peek() != EOF)
		throw std::runtime_error("not a number or extra data.");
	if (v < 0)
		throw std::runtime_error("not a positive number.");
	if (v > 1000)
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
	std::cout << "y ==> ****** " << y << std::endl;
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
		if (d > 28)
			throw std::runtime_error("day out of range");
		if (d == 28 && ((y % 4 != 0) || (y % 100 == 0 && y % 400 != 0)))
			throw std::runtime_error("day out of range");
	}
	if (m == 4 || m == 6 || m == 9 || m == 11) {
		if (d > 30)
			throw std::runtime_error("day out of range");
	}
}