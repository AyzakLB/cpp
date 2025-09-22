/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzak <ayzak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:51:32 by ayzak             #+#    #+#             */
/*   Updated: 2025/04/07 20:51:33 by ayzak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP

#include <iostream>

class Zombie 
{
    std::string _name;
    public:
        Zombie(std::string n);
        ~Zombie();
        void announce( void );
};

#endif