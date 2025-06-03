/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:55:03 by lvichi            #+#    #+#             */
/*   Updated: 2025/06/02 13:56:29 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"
#include <iostream>
#include <exception>


int main( int argc, char** argv )
{
  if ( argc != 2 ) {
    std::cout << "Invalid number of arguments." << std::endl;
    return 1;
  }

  ScalarConverter::convert( argv[1] );

  return 0;
}
