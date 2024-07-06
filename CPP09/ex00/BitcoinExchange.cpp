/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 09:08:07 by aouhbi            #+#    #+#             */
/*   Updated: 2024/07/05 11:34:08 by aouhbi           ###   ########.fr       */
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
	std::ifstream file(DataF);
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
			float value_f = std::stof(value_s);
			DataBase[date] = value_f;
		}
		else 
			throw std::runtime_error("Error: Failed to read line from file.");   
	}
}


void    Btc::Check_Input(const std::string Input) const {
	std::ifstream file(Input);
	if (!file.is_open())
		throw std::runtime_error("Error: couldn't open Input file.");
	std::string line;
	int i = -1;
	i++;
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date, pipe, value;
		if (i == 0) {
			ss >> date >> pipe >> value;
			if (date != "date" || pipe != "|" || value != "value") {
				std::string error = "Error: bad input => " + line;
				throw std::runtime_error(error);
			}
			i++;
		}
		if (std::getline(ss, date, '|') && std::getline(ss, value)) {
			std::istringstream iss(date);
			iss >> date;
			// std::cout << CYAN "Date ==> " << date << RESET << std::endl;
			std::istringstream iss2(value);
			iss >> value;
			// std::cout << CYAN "Value ==> " << value << RESET << std::endl;
		
		
			if (!Date_Check(date)) {
				std::cerr << "Error: bad input => " << date << std::endl;
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
		return false;
	std::stringstream ss(Date);
	std::string year, month, day;
	if (std::getline(ss, year, '-') && std::getline(ss, month, '-') && std::getline(ss, day)) {
		try {
		int y = std::stoi(year);
		int m = std::stoi(month);
		int d = std::stoi(day);
		if (!y || !m || !d)
			return false;
		}
		catch (...) {
			return false;
		}
	}
	return true;
}

float	Btc::Value_Check(const std::string Value) const {
	float v = std::stof(Value);
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


// BitcoinExchange::BitcoinExchange(const std::string& dbFile) {
// 	loadDatabase(dbFile);
// }

// BitcoinExchange::~BitcoinExchange() {}

// void BitcoinExchange::loadDatabase(const std::string& dbFile) {
// 	std::ifstream file(dbFile);
// 	if (!file.is_open()) {
// 		throw std::runtime_error("Error: could not open Data file.");
// 	}

// 	std::string line;
// 	while (std::getline(file, line)) {
// 		std::istringstream ss(line);
// 		std::string date, valueStr;
// 		if (std::getline(ss, date, ',') && std::getline(ss, valueStr)) {
// 			float value = std::stof(valueStr);
// 			exchangeRates[date] = value;
// 		}
// 	}
// }


// float BitcoinExchange::getExchangeRate(const std::string& date) const {
// 	auto it = exchangeRates.lower_bound(date);
// 	if (it == exchangeRates.end() || (it != exchangeRates.begin() && it->first != date)) {
// 		--it;
// 	}
// 	return it->second;
// }

// void BitcoinExchange::evaluate(const std::string& inputFile) const {
// 	std::ifstream file(inputFile);
// 	if (!file.is_open()) {
// 		std::cerr << "Error: could not open file." << std::endl;
// 		return;
// 	}

// 	std::string line;
// 	while (std::getline(file, line)) {
// 		std::istringstream ss(line);
// 		std::string date, valueStr;
// 		if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
// 			date.erase(date.find_last_not_of(" \n\r\t")+1);
// 			valueStr.erase(0, valueStr.find_first_not_of(" \n\r\t"));

// 			if (!isValidDate(date)) {
// 				std::cerr << "Error: bad input => " << date << std::endl;
// 				continue;
// 			}
// 			if (!isValidValue(valueStr)) {
// 				std::cerr << "Error: not a positive number." << std::endl;
// 				continue;
// 			}

// 			float value = std::stof(valueStr);
// 			if (value > 1000) {
// 				std::cerr << "Error: too large a number." << std::endl;
// 				continue;
// 			}

// 			float rate = getExchangeRate(date);
// 			std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
// 		} else {
// 			std::cerr << "Error: bad input => " << line << std::endl;
// 		}
// 	}
// }

// bool BitcoinExchange::isValidDate(const std::string& date) const {
// 	// Basic validation for date format YYYY-MM-DD
// 	if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
// 		return false;
// 	}
// 	return true;
// }

// bool BitcoinExchange::isValidValue(const std::string& value) const {
// 	// Check if value is a float or positive integer
// 	try {
// 		float val = std::stof(value);
// 		if (val < 0) {
// 			return false;
// 		}
// 	} catch (...) {
// 		return false;
// 	}
// 	return true;
// }
