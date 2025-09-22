/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzak <ayzak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:51:24 by ayzak             #+#    #+#             */
/*   Updated: 2025/04/07 20:51:25 by ayzak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main(void)
{
    int N = 5;
    Zombie* hordeZero = zombieHorde(0, "no zombies");
    hordeZero = zombieHorde(-19, "no zombies");
    (void)hordeZero;
    Zombie* horde = zombieHorde(N, "dumbdumb");
    if (horde == NULL)
        return 1;
    for (int i = 0; i < N; i++)
        horde[i].announce();
    delete[] horde;
    return 0;
}