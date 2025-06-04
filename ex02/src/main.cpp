/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:11:41 by lvichi            #+#    #+#             */
/*   Updated: 2025/06/04 12:12:06 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Base.hpp"
#include "functions.hpp"
#include <iostream>


int main( int argc, char** argv )
{
  ( void )argc;
  ( void )argv;

  Base* randomClass = generate();

  if ( not randomClass ) {
    std::cout << "Failed to create class" << std::endl;
    return 1;
  }

  identify( randomClass );

  identify( *randomClass );

  delete randomClass;

  return 0;
}
