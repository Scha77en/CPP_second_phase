/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 09:07:59 by aouhbi            #+#    #+#             */
/*   Updated: 2024/10/06 05:24:37 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <type_traits>


int main(int argc, char** argv)
{
	if (argc != 2) {
		std::cerr << "Error: no file provided." << std::endl;
		return 1;
	}
	try {
		Btc btc("data.csv");
		btc.Check_Input(argv[1]);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
