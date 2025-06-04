/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:22:45 by lvichi            #+#    #+#             */
/*   Updated: 2025/06/02 16:23:06 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <string>
#include <iostream>
#include <climits>    // INT_MIN INT_MAX
#include <cstdlib>    // std::strtod
#include <iomanip>    // std::fixed


class ScalarConverter
{
  private:
    ScalarConverter();
    ScalarConverter( const ScalarConverter& original );
    ScalarConverter& operator=( const ScalarConverter& original );
    ~ScalarConverter();

  public:
    static void convert( const std::string& literal );
};
