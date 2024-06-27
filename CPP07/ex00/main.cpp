/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhbi <aouhbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:35:34 by aouhbi            #+#    #+#             */
/*   Updated: 2024/06/26 07:51:24 by aouhbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>


int main(void) {
  int a = 2;
  int b = 3;

  ::swap(a, b);
  std::cout << YELLOW "a = " << a << CYAN ", b = " << b << RESET " || &a = " << YELLOW << &a << RESET " &b = " CYAN << &b << RESET << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << " || &min( a, b ) = " GREEN << &::min(a, b) << RESET << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << " || &max( a, b ) = " BLUE << &::max(a, b) << RESET << std::endl;
  
  b = 3;
  
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << " || &min( a, b ) = " GREEN << &::min(a, b) << RESET << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << " || &max( a, b ) = " BLUE << &::max(a, b) << RESET << std::endl;
  
  std::string c = "chaine1";
  std::string d = "chaine2";
  
  ::swap(c, d);
  std::cout << YELLOW "c = " << c << CYAN ", d = " << d << RESET " || &c = " YELLOW << &c << RESET " &d = " CYAN << &d << RESET << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << "|| &min( c, d ) = " GREEN << &::min(c, d) << RESET << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << "|| &max( c, d ) = " BLUE << &::max(c, d) << RESET << std::endl;
  return 0;
}
