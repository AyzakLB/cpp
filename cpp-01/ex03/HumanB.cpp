/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzak <ayzak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:51:00 by ayzak             #+#    #+#             */
/*   Updated: 2025/04/07 20:51:01 by ayzak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : _name(name){
    _weapon = NULL;
}

void HumanB::attack() {
    if (!_weapon)
        std::cout << _name << " attacks with their fists" << std::endl;
    else
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
    _weapon = &weapon;
};