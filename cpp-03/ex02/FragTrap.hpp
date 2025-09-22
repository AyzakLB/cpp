/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzak <ayzak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:33:46 by ayzak             #+#    #+#             */
/*   Updated: 2025/04/16 21:33:47 by ayzak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"


class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const std::string &name);
        FragTrap(const FragTrap& other);
        FragTrap &operator=(const FragTrap &other);
        ~FragTrap();
        
        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif

