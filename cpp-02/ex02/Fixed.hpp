/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzaq <amarzaq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:18:42 by amarzaq           #+#    #+#             */
/*   Updated: 2025/04/11 19:18:43 by amarzaq          ###   ########.fr       */
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
        Fixed& operator=(const Fixed &copy);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        Fixed(const int value);
        Fixed(const float value);
        float toFloat(void) const;
        int toInt(void) const;

        // Comparaison Operaators
        bool operator>(const Fixed &target) const;
        bool operator<(const Fixed &target) const;
        bool operator>=(const Fixed &target) const;
        bool operator<=(const Fixed &target) const;
        bool operator==(const Fixed &target) const;
        bool operator!=(const Fixed &target) const;

        // Arithmetic Operators
        Fixed operator+(const Fixed &target) const;
        Fixed operator-(const Fixed &target) const;
        Fixed operator*(const Fixed &target) const;
        Fixed operator/(const Fixed &target) const;

        // Increment and Decrement Operators
        Fixed& operator++(); 
        Fixed operator++(int); 
        Fixed& operator--(); 
        Fixed operator--(int); 

        // Min and Max
        static Fixed &min(Fixed &f1, Fixed &f2);
        static const Fixed &min(const Fixed &f1, const Fixed &f2);
        static Fixed &max(Fixed &f1, Fixed &f2);
        static const Fixed &max(const Fixed &f1, const Fixed &f2);
        
};

////////////////////////////////////////// EX01 //////////////////////////////////////
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif