/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzak <ayzak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:51:40 by ayzak             #+#    #+#             */
/*   Updated: 2025/04/07 20:51:41 by ayzak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    try {
        Zombie* zom = new Zombie(name);
        return zom;
    } catch(const std::bad_alloc& e){
        std::cerr << "couldn't allocate memory for a Zombie class with the name: " << name << std::endl;
        return NULL;
    }
}