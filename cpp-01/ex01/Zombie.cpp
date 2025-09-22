/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzak <ayzak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:51:21 by ayzak             #+#    #+#             */
/*   Updated: 2025/04/07 20:51:22 by ayzak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie::Zombie() : _name("nameless"){}

Zombie::Zombie(std::string n)
{
    _name = n;
}

Zombie::~Zombie()
{
    std::cout << _name << " is dead, for real this time." << std::endl;
}

void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string n)
{
    _name = n;
}
