/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:11:03 by tguerran          #+#    #+#             */
/*   Updated: 2024/10/31 16:04:28 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << "ScavTrap " << Name << " constructed!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << Name << " destroyed" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if(EnergyPoints > 0 && HitPoints > 0)
	{
		std::cout << "ScavTrap " << Name << " ferociously attacks " << target
			<< ", causing " << AttackDamage << " points of damage!" << std::endl;
		EnergyPoints--;
	}
	else if(EnergyPoints <= 0)
	{
		std::cout << "ScavTrap " << Name << " has no energy left to attack!" << std::endl;
	}
	else if(HitPoints <= 0)
	{
		std::cout << "ScavTrap " << Name << " has no hits points left and cannot attack!" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << Name << " is now in Gate keepermode" << std::endl;
}
