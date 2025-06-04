/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:22:45 by lvichi            #+#    #+#             */
/*   Updated: 2025/06/02 17:29:32 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"


std::string sanitizeLiteral( const std::string& literal );
double stringToDouble( const std::string& literal, char*& end );
void printChar( double number );
void printInt( double number );
void printFloat( double number );
void printDouble( double number );
void printNan();


void ScalarConverter::convert( const std::string& literal )
{
  std::string literal_clean = sanitizeLiteral( literal );

  // std::cout << '"' << literal_clean << '"' << std::endl;

  char* end  = 0;
  double number = stringToDouble( literal_clean, end);

  if ( *end != 0 || literal_clean.length() == 0 ||
       literal_clean == "nan" || literal_clean == "-nan") {
    printNan();
    return;
  }

  printChar( number );
  printInt( number );
  printFloat( number );
  printDouble( number );
}


std::string sanitizeLiteral( const std::string& literal )
{
  int start = 0;
  int end   = literal.length() - 1;

  if ( literal.length() <= 1 )
    return literal;

  while ( start < end && literal[start] == ' ' )
    start++;

  while ( end >= start && literal[end] == ' ' )
    end--;

  std::string literal_clean = literal.substr(start, end - start + 1);

  if ( literal_clean[( literal_clean.length() - 1)] == 'f' ) {
	char* end  = 0;
    std::string literal_test;
	literal_test = literal_clean.substr(0, literal_clean.length() - 1);
    (void)std::strtod( literal_test.c_str(), &end );
	if ( *end == 0 )
		literal_clean = literal_clean.substr(0, literal_clean.length() - 1);
  }

  return literal_clean;
}


double stringToDouble( const std::string& literal, char*& end )
{
  if ( literal.length() == 1 &&
       ( literal[0] < '0' || literal[0] > '9' ) ) {
    static char dummy = '\0';
    end = &dummy;
    return static_cast<double>( literal[0] );
  }

  double number = std::strtod( literal.c_str(), &end );

  return number;
}


void printChar( double number )
{
  if ( number >= 32 && number <= 126 &&
       number == static_cast<int>( number ) )
    std::cout << "char: " << static_cast<char>( number ) << std::endl;
  else if ( number >= 0 && number <= 127 &&
            number == static_cast<int>( number ) )
    std::cout << "char: Non displayable" << std::endl;
  else
    std::cout << "char: Impossible" << std::endl;
}


void printInt( double number )
{
  if ( number >= INT_MIN && number <= INT_MAX )
    std::cout << "int: " << static_cast<int>( number ) << std::endl;
  else
    std::cout << "int: Impossible" << std::endl;
}


void printFloat( double number )
{
  bool isScientific = number < 0.0001 || number > 1000000;

  if (isScientific || number != static_cast<int>( number ))
    std::cout << "float: " << static_cast<float>( number ) << "f" << std::endl;
  else
    std::cout << "float: "
              << static_cast<float>( number ) << ".0f" << std::endl;
}


void printDouble( double number )
{
  bool isScientific = number < 0.0001 || number > 1000000;

  if ( isScientific || number != static_cast<int>( number ) )
    std::cout << "double: " << number << std::endl;
  else
    std::cout << "double: " << number << ".0" << std::endl;
}


void printNan()
{
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: nanf" << std::endl;
  std::cout << "double: nan" << std::endl;
}
