/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzak <ayzak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:50:03 by ayzak             #+#    #+#             */
/*   Updated: 2025/04/07 20:50:04 by ayzak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{

    Harl Harl;
    Harl.complain("DEBUG");
    Harl.complain("INFO");
    Harl.complain("WARNING");
    Harl.complain("ERROR");
    return 0;
}