/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzak <ayzak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:50:57 by ayzak             #+#    #+#             */
/*   Updated: 2025/04/07 20:50:58 by ayzak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    std::string _name;
    Weapon *_weapon;
public:
    HumanB(const std::string& name);
    void attack();
    void setWeapon(Weapon& weapon);
};

#endif