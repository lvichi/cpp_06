/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 09:33:45 by lvichi            #+#    #+#             */
/*   Updated: 2025/06/04 09:34:08 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <stdint.h>


struct Data;


class Serializer
{
  private:
    Serializer();
    Serializer( const Serializer& original );
    Serializer& operator=( const Serializer& original );
    ~Serializer();

  public:
    static uintptr_t serialize( const Data* ptr );
    static Data* deserialize( const uintptr_t raw );
};
