/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 09:08:04 by aouhbi            #+#    #+#             */
/*   Updated: 2024/10/06 04:28:39 by aouhbi           ###   ########.fr       */
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
		~Btc();

		void	loadData(const std::string DataF);
		void	Check_Input(const std::string Input) const;
		bool	Date_Check(const std::string Date) const;
		float	Value_Check(const std::string Value) const;
		float	Get_Exch_Rate(const std::string date) const;

		// void	Trim(std::string &s);
		void	Check_year(int y) const;
		void	Check_month(int m) const;
		void	Check_day(int d, int m, int y) const;
};

#endif
