/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:23:55 by tguerran          #+#    #+#             */
/*   Updated: 2024/10/28 14:47:15 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
    public:
		Fixed();
		Fixed(const Fixed& other);
		~Fixed();

		Fixed& operator=(const Fixed& other);

		int getRawBits(void) const;
		void setRawBits(int const raw);
    private:
		int value;
		static const int fractionBits = 8;
};

#endif