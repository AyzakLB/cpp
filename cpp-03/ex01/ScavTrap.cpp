/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzak <ayzak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:33:29 by ayzak             #+#    #+#             */
/*   Updated: 2025/04/16 21:33:30 by ayzak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap's Default constructor called" << std::endl;
} 
// Parameterized constructor
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "ScavTrap's Parameterized constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    return ;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap's Copy constructor called" << std::endl;
}

// Assignment operator overload
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap's Assignment operator called" << std::endl;
    ClapTrap::operator=(other);
    return (*this);
}

// Destructor
ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap's Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    
    if (_hitPoints == 0)
        std::cout << "ScavTrap " << _name << " is dead x_x" << std::endl;
    else if (_energyPoints == 0)
        std::cout << "attack failed, not enough energy..." << std::endl;
    else
    {
        std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
}

void ScavTrap::guardGate()
{
        std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}