/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:45:19 by tguerran          #+#    #+#             */
/*   Updated: 2024/10/31 17:11:03 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	EnergyPoints = 100;
	AttackDamage = 30;
	HitPoints = 100;
	std::cout << "FragTrap " << Name << " just joined the fight" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << Name << " explose" << std::endl; 
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << Name << " is asking for a high five!" << std::endl;
}