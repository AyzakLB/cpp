/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzak <ayzak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:51:03 by ayzak             #+#    #+#             */
/*   Updated: 2025/04/07 20:51:04 by ayzak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    std::string _name;
    Weapon &_weapon;
    public:
        HumanA(const std::string& name, Weapon& weapon);
        void attack();
};

#endif