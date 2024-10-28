/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:00:24 by tguerran          #+#    #+#             */
/*   Updated: 2024/10/28 21:22:16 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
    public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& other);
		Fixed(const int intValue);
		Fixed(const float floatValue);

		Fixed& operator=(const Fixed& other);

		bool operator<(const Fixed& other) const;
		bool operator>(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		Fixed operator++(int);
		Fixed& operator++();
		Fixed operator--(int);
		Fixed& operator--();
		
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat (void) const;
		int toInt(void) const;
    private:
		int value;
		static const int fractionBits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);




#endif