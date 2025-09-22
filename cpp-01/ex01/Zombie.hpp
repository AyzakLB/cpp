/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzak <ayzak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:51:18 by ayzak             #+#    #+#             */
/*   Updated: 2025/04/07 20:51:19 by ayzak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP

#include <iostream>

class Zombie 
{
    std::string _name;
    public:
        Zombie();
        Zombie(std::string n);
        ~Zombie();
        void announce( void );
        void setName(std::string n);
};

#endif