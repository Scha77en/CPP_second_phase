/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 09:08:04 by aouhbi            #+#    #+#             */
/*   Updated: 2024/09/08 23:01:10 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

#define BLUE "\033[0;34m"
#define GREEN "\033[0;32m"
#define CYAN "\033[0;36m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"

class Btc {
	private:

		Btc();
		std::map<std::string, float> DataBase;
	public:

		Btc(const std::string DataF);
		// Btc(const Btc& copy);
		// Btc &operator=(const Btc& copy);
		~Btc();

		void	loadData(const std::string DataF);
		void	Check_Input(const std::string Input) const;
		bool	Date_Check(const std::string Date) const;
		float	Value_Check(const std::string Value) const;
		float	Get_Exch_Rate(const std::string date) const;

		void	Check_year(int y) const;
		void	Check_month(int m) const;
		void	Check_day(int d, int m, int y) const;
};

#endif

// #ifndef BITCOINEXCHANGE_HPP
// #define BITCOINEXCHANGE_HPP

// #include <iostream>
// #include <map>
// #include <string>

// class BitcoinExchange {
// public:
//     BitcoinExchange(const std::string& dbFile);
//     ~BitcoinExchange();

//     float getExchangeRate(const std::string& date) const;
//     void evaluate(const std::string& inputFile) const;

// private:
//     void loadDatabase(const std::string& dbFile);
//     std::map<std::string, float> exchangeRates;

//     bool isValidDate(const std::string& date) const;
//     bool isValidValue(const std::string& value) const;
// };

// #endif

















// class BitcoinExchange {
// 	private:
// 		unsigned int _amount;
// 		std::vector<unsigned int> _prices;
// 		unsigned int _maxProfit;
// 		unsigned int _buy;
// 		unsigned int _sell;
// 		BitcoinExchange();
// 		void _findMaxProfit();
// 		void _findBuySell();
// 	public:
// 		BitcoinExchange(unsigned int amount, std::vector<unsigned int> prices);
// 		BitcoinExchange(const BitcoinExchange &copy);
// 		BitcoinExchange &operator=(const BitcoinExchange &copy);
// 		~BitcoinExchange();
// 		void print();
// };