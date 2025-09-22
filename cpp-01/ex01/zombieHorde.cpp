/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzak <ayzak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:51:16 by ayzak             #+#    #+#             */
/*   Updated: 2025/04/07 20:51:17 by ayzak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{   
    Zombie* horde;
    
    if (N <= 0)
    {
        std::cerr << "you need a positive number to create a horde" << std::endl;
        return NULL;
    }
    try 
    {
        horde = new Zombie[N];
    }
    catch (const std::bad_alloc& e) 
    {
        std::cerr << "couldn't allocate memory for the horde" << std::endl;
        return NULL;
    }
    for (int i = 0; i < N; i++)
        horde[i].setName(name);
    return horde;
}