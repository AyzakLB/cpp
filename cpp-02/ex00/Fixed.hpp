/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzaq <amarzaq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:18:21 by amarzaq           #+#    #+#             */
/*   Updated: 2025/04/11 19:18:22 by amarzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed &copy);
        Fixed& operator=(const Fixed &other);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};
#endif