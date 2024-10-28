/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:00:39 by tguerran          #+#    #+#             */
/*   Updated: 2024/10/28 21:22:42 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


// ----------------ex00 ---------------- //
Fixed::Fixed() : value(0)
{

}

Fixed::Fixed(const Fixed& other) : value(other.value)
{
	
}

Fixed& Fixed::operator=(const Fixed&other) 
{
    if(this != &other)
    {
        this->value = other.value;
    }
    return *this;
}

Fixed::~Fixed()
{
	
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
	value = intValue << fractionBits;
}

Fixed::Fixed(const float floatValue)
{
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


// ----------------ex02 ---------------- //

bool Fixed::operator>(const Fixed& other) const 
{
	return this->value > other.value;
}

bool Fixed::operator<(const Fixed& other) const 
{
	return this->value < other.value;
}

bool Fixed::operator<=(const Fixed& other) const 
{
	return this->value <= other.value;
}

bool Fixed::operator>=(const Fixed& other) const 
{
	return this->value >= other.value;
}

bool Fixed::operator==(const Fixed& other) const 
{
	return this->value == other.value;
}

bool Fixed::operator!=(const Fixed& other) const 
{
	return this->value != other.value;
}

Fixed Fixed::operator+(const Fixed& other) const 
{
	Fixed result;
	result.setRawBits(this->value + other.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const 
{
	Fixed result;
	result.setRawBits(this->value - other.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->value * other.getRawBits() >> fractionBits);
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->value  << fractionBits / other.getRawBits());
	return result;
}

Fixed& Fixed::operator++()
{
	this->value +=1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->value += 1;
	return temp;
}

Fixed& Fixed::operator--()
{
	this->value -=1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->value -= 1;
	return temp;	
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if(a < b)
	{
		return a;
	}
	else
		return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if(a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

Fixed& Fixed::max(Fixed& a , Fixed& b)
{
	if(a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

const Fixed& Fixed::max(const Fixed& a ,const Fixed& b)
{
	if(a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}