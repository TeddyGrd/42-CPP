/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:19:56 by tguerran          #+#    #+#             */
/*   Updated: 2024/10/23 15:15:42 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAINB_HPP
#define HUMAINB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		void attack() const;
		void setWeapon(Weapon& weapon);
	private:
		std::string name;
		Weapon* weapon;
};

#endif