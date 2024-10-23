/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:19:51 by tguerran          #+#    #+#             */
/*   Updated: 2024/10/23 15:12:44 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAINA_HPP
#define HUMAINA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon& weapon);
		void attack() const;
	private:
		std::string name;
		Weapon& weapon;
};

#endif