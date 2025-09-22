/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzak <ayzak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:51:44 by ayzak             #+#    #+#             */
/*   Updated: 2025/04/07 20:51:45 by ayzak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main(void)
{
    Zombie *zombieOnHeap;
    
    zombieOnHeap = newZombie("heap_zombie");
    if (zombieOnHeap != NULL)
    {
        zombieOnHeap->announce();
        delete zombieOnHeap;
    }
    randomChump("stack_zombie");
    return 0;
}