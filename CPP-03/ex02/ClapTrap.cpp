/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:47:16 by tguerran          #+#    #+#             */
/*   Updated: 2024/10/31 16:02:20 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "ClapTrap " << Name << " created!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << Name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if(EnergyPoints > 0 && HitPoints > 0)
	{
		std::cout << "ClapTrap " << Name << " attacks " << target
			<< ", causing " << AttackDamage << " points of damage!" << std::endl;
			EnergyPoints--;
	}
	else if(EnergyPoints <= 0)
	{
		std::cout << "ClapTrap " << Name << " has no energy left to attack!" << std::endl;
	}
	else if(HitPoints <= 0)
	{
		std::cout << "ClapTrap " << Name << " has no hits points left and cannot attack!" << std::endl;
	}
}

void ClapTrap::beRepaired( unsigned int amount)
{
	if(EnergyPoints > 0 && HitPoints > 0)
	{
		HitPoints += amount;
		EnergyPoints--;
		std::cout << "ClapTrap " << Name << " repairs itself, restoring "
			<< amount << " hit points!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << Name << " can't repair itself due to lack of energy or Hitpoints!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(amount >= HitPoints)
	{
		HitPoints = 0;
	}
	else
	{
		HitPoints -= amount;
	}
	std::cout << "ClapTrap " << Name << " takes " << amount << " points of damage!" << std::endl;
}