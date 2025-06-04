/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 09:37:57 by lvichi            #+#    #+#             */
/*   Updated: 2025/06/04 09:37:57 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"


uintptr_t Serializer::serialize( const Data* ptr )
{
  return reinterpret_cast<uintptr_t>( ptr );
}

Data* Serializer::deserialize( const uintptr_t raw )
{
  return reinterpret_cast<Data*>( raw );
}
