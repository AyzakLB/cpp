/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzak <ayzak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:50:52 by ayzak             #+#    #+#             */
/*   Updated: 2025/04/07 20:50:53 by ayzak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"


Weapon::Weapon(const std::string& weaponType) : _type(weaponType){}

const std::string& Weapon::getType(void) const
{
    return _type;
}

void Weapon::setType(const std::string &WeaponType)
{
    _type = WeaponType;
}