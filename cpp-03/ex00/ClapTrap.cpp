/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzak <ayzak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:32:58 by ayzak             #+#    #+#             */
/*   Updated: 2025/04/16 21:32:59 by ayzak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap() : _name("defaultName"), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << "ClapTrap's Default constructor called" << std::endl;
}

// Parameterized  constructor
ClapTrap::ClapTrap(const std::string &name) : _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << "ClapTrap's parameterized constructor called" << std::endl;
    _name = name;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap's Copy constructor called" << std::endl;
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    return ;
}

// Assignment operator overload
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap's Assignment operator called" << std::endl;
    
    if (this != &other)
    {
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    }
    return (*this);
}

// Destructor
ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap's Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    
    if (_hitPoints == 0)
        std::cout << "ClapTrap " << _name << " is dead x_x" << std::endl;
    else if (_energyPoints == 0)
        std::cout << "attack failed, not enough energy..." << std::endl;
    else
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints == 0)
        std::cout << "ClapTrap " << _name << " is dead x_x" << std::endl;
    else if (_energyPoints == 0)
        std::cout << "repairing failed, not enough energy..." << std::endl;
    else
    {
        std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " of hit points!" << std::endl;
        _hitPoints += amount;
        _energyPoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0)
        std::cout << "ClapTrap " << _name << " is already dead, stop beating a dead horse..." << std::endl;
    else   {
        std::cout << "ClapTrap " << _name << " takes " << amount << " of damage!" << std::endl;
        if (_hitPoints <= amount)
            _hitPoints = 0;
        else
            _hitPoints -= amount;
        }
}


