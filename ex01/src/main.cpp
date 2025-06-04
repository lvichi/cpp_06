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


#include "Serializer.hpp"
#include <string>
#include <iostream>


struct Data {
  int           number;
  std::string   str;
};


int main( int argv, char** argc)
{
  (void)argv;
  (void)argc;

  Data* myData = new Data;
  myData->number = 1;
  myData->str = "Leo";

  std::cout << "Struct myData:"               << std::endl
            << "  number: " << myData->number << std::endl
            << "  str: "    << myData->str    << std::endl << std::endl;

  uintptr_t intAddress = Serializer::serialize( myData );

  std::cout << "myData Address: " << myData
            << std::endl << std::endl;

  std::cout << "intAddress: " << intAddress
            << std::endl << std::endl;

  Data* deserializedData = Serializer::deserialize( intAddress );

  std::cout << "Struct deserializedData:"               << std::endl
            << "  number: " << deserializedData->number << std::endl
            << "  str: "    << deserializedData->str
            << std::endl << std::endl;

  std::cout << "deserializedData Address: " << deserializedData
            << std::endl << std::endl;

  delete myData;

  return 0;
}
