/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:29:23 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/25 19:33:41 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


// ----------------ex00 ---------------- //

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}


Fixed& Fixed::operator=(const Fixed&other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
    {
        this->setRawBits(other.getRawBits());
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const 
{
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

// ----------------ex01 ---------------- //

Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	value = intValue << fractionBits;
}

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	value = roundf(floatValue * (1 << fractionBits));
}

float Fixed::toFloat(void) const
{
	return (float)value / (1 << fractionBits);
}

int Fixed::toInt(void) const
{
	return value >> fractionBits;	
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}
