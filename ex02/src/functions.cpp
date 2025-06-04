/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:18:35 by lvichi            #+#    #+#             */
/*   Updated: 2025/06/04 12:18:35 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "functions.hpp"


Base* generate( void )
{
  std::srand( std::time(0) );

  int random = std::rand() % 3;

  switch ( random ) {
    case 0: return new A;
    case 1: return new B;
    case 2: return new C;
    default: return 0;
  }
}


void identify( Base& p )
{
  try {
    ( void )dynamic_cast<A&>( p );
    std::cout << "Class A" << std::endl;
    return;
  } catch (...) { }

  try {
    ( void )dynamic_cast<B&>( p );
    std::cout << "Class B" << std::endl;
    return;
  } catch (...) { }

  try {
    ( void )dynamic_cast<C&>( p );
    std::cout << "Class C" << std::endl;
    return;
  } catch (...) { }

  std::cout << "Unindentified Clas" << std::endl;
}


void identify( Base* p )
{
  if ( dynamic_cast<A*>( p ) )
    std::cout << "Class A" << std::endl;
  else if ( dynamic_cast<B*>( p ) )
    std::cout << "Class B" << std::endl;
  else if ( dynamic_cast<C*>( p ) )
    std::cout << "Class C" << std::endl;
  else
    std::cout << "Unindentified Clas" << std::endl;
}
