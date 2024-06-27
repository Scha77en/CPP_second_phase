/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:51:54 by aouhbi            #+#    #+#             */
/*   Updated: 2024/06/26 07:50:51 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void) {
	int tab[] = {0, 1, 2, 3, 4};
	iter(tab, 5, print);

	std::string tab2[] = {"Rivers", "Of", "Blood!"};
	iter(tab2, 3, print);

	float tab3[] = {0.1f, 1.1f, 2.2f, 3.3f, 4.4f};
	iter(tab3, 5, print);

	return 0;
}

