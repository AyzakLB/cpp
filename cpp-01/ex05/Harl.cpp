/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzak <ayzak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:50:18 by ayzak             #+#    #+#             */
/*   Updated: 2025/04/07 20:50:19 by ayzak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "[DEBUG] instructions unclear, patient is dying" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[INFO] did you know that bungee gum has the properties of both rubber and gum" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARNING] be careful what you wish for..." << std::endl;
}

void Harl::error(void)  
{
    std::cout << "[ERROR] braincells not found!" << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*harlActions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*harlActions[i])();
            return;
        }
    }
}
