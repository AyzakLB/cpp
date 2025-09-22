/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzak <ayzak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:50:49 by ayzak             #+#    #+#             */
/*   Updated: 2025/04/07 20:50:50 by ayzak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
    std::string _type;
public:
    Weapon(const std::string &weaponType);
    const std::string& getType(void) const;
    void setType(const std::string &weaponType);
};

#endif