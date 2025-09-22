/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzak <ayzak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:33:06 by ayzak             #+#    #+#             */
/*   Updated: 2025/04/16 21:40:29 by ayzak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap claptrap("ClapTrap");
    ClapTrap claptrap2(claptrap);
    ClapTrap claptrap3 = claptrap;
    ClapTrap claptrap4;

    claptrap4 = claptrap;

    claptrap.attack("target");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);
    return 0;
}