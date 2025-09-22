/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzaq <amarzaq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:18:39 by amarzaq           #+#    #+#             */
/*   Updated: 2025/04/11 19:18:40 by amarzaq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _fixedPointValue = other._fixedPointValue;
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _fixedPointValue = raw;
}

////////////////////////////////////////// EX01 //////////////////////////////////////

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = (roundf(value * (1 << _fractionalBits)));
}

float Fixed::toFloat(void) const
{
    return static_cast<float>( _fixedPointValue) / ( 1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return _fixedPointValue >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
////////////////////////////////////////// EX02 //////////////////////////////////////

///////////////////////////////////////////////////// Comparaison Operators /////////////////////////////////////////////////////

bool Fixed::operator>(const Fixed &target) const
{
    return _fixedPointValue > target._fixedPointValue;
}

bool Fixed::operator<(const Fixed &target) const
{
    return _fixedPointValue < target._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &target) const
{
    return _fixedPointValue >= target._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &target) const
{
    return _fixedPointValue <= target._fixedPointValue;
}

bool Fixed::operator==(const Fixed &target) const
{
    return _fixedPointValue == target._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &target) const
{
    return _fixedPointValue != target._fixedPointValue;
}



///////////////////////////////////////////////////// Arithmetic Operators /////////////////////////////////////////////////////

Fixed Fixed::operator+(const Fixed &target) const
{
    Fixed result;

    result._fixedPointValue =  static_cast<long long>(_fixedPointValue) + static_cast<long long>(target._fixedPointValue);
    return result;
}

Fixed Fixed::operator-(const Fixed &target) const
{
    Fixed result;

    result._fixedPointValue =  static_cast<long long>(_fixedPointValue) - static_cast<long long>(target._fixedPointValue);
    return result;
}

Fixed Fixed::operator*(const Fixed &target) const
{
    Fixed result;

    result._fixedPointValue =  (static_cast<long long> (_fixedPointValue) * static_cast<long long>(target._fixedPointValue)) >> _fractionalBits;
    return result;
}

Fixed Fixed::operator/(const Fixed &target) const
{
    Fixed result;

    result._fixedPointValue =  (static_cast<long long>(_fixedPointValue )<< _fractionalBits) / target._fixedPointValue;
    return result;
}

///////////////////////////////////////////////////// Increment and Decrement Operators /////////////////////////////////////////////////////

Fixed& Fixed::operator++()
{
    ++_fixedPointValue;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed originalCopy = *this;
    ++_fixedPointValue;
    return originalCopy;
}

Fixed& Fixed::operator--()
{
    --_fixedPointValue;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed originalCopy = *this;
    --_fixedPointValue;
    return originalCopy;
}

///////////////////////////////////////////////////// Min and Max /////////////////////////////////////////////////////

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
    if (f1 < f2)
        return f1;
    return f2;
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
    if (f1 < f2)
        return f1;
    return f2;
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
    if (f1 > f2)
        return f1;
    return f2;
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
    if (f1 > f2)
        return f1;
    return f2;
}
