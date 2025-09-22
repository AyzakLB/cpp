/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzak <ayzak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:33:43 by ayzak             #+#    #+#             */
/*   Updated: 2025/04/16 21:33:44 by ayzak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap's Default constructor called" << std::endl;
}

// Parameterized constructor
FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "FragTrap's  Parameterized constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap's Copy constructor called" << std::endl;
}

// Assignment operator overload
FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap's Assignment operator called" << std::endl;
    ClapTrap::operator=(other);
    return (*this);
}

// Destructor
FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap's Destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    
    if (_hitPoints == 0)
        std::cout << "FragTrap " << _name << " is dead x_x" << std::endl;
    else if (_energyPoints == 0)
        std::cout << "attack failed, not enough energy..." << std::endl;
    else
    {
        std::cout << "FragTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap says: " << _name << " high fiiive everyone" << std::endl;
}
