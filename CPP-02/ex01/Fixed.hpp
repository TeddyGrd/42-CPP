/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:29:09 by tguerran          #+#    #+#             */
/*   Updated: 2024/10/28 18:29:38 by tguerran         ###   ########.fr       */
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