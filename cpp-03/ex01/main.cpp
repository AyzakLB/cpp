/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzak <ayzak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:33:26 by ayzak             #+#    #+#             */
/*   Updated: 2025/04/17 16:27:23 by ayzak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    // ScavTrap scavtrap("scavtrap");
    // ScavTrap scavtrap2(scavtrap);
    // ScavTrap scavtrap3 = scavtrap;
    // ScavTrap scavtrap4;

    // scavtrap4 = scavtrap;
    ClapTrap *scavtrap = new ScavTrap("scavtrap");
    scavtrap->attack("target");
    scavtrap->takeDamage(5);
    scavtrap->beRepaired(3);
    return 0;
}