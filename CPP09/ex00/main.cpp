/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 09:07:59 by aouhbi            #+#    #+#             */
/*   Updated: 2024/09/08 22:49:37 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
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


// #include <time.h>
// std::strptime