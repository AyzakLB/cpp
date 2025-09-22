/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzak <ayzak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:50:15 by ayzak             #+#    #+#             */
/*   Updated: 2025/04/07 20:50:16 by ayzak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>

class Harl
{
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
    public:
        void complain( std::string level );
};

#endif