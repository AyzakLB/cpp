/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzak <ayzak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:33:48 by ayzak             #+#    #+#             */
/*   Updated: 2025/04/16 21:46:55 by ayzak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    FragTrap fragtrap("fragtrap");
    FragTrap fragtrap2(fragtrap);
    FragTrap fragtrap3 = fragtrap;
    FragTrap fragtrap4;

    fragtrap4 = fragtrap;

    fragtrap.attack("target");
    fragtrap.takeDamage(5);
    fragtrap.beRepaired(3);
    fragtrap.highFivesGuys();
    return 0;
}