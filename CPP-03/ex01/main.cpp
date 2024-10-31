/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:46:39 by tguerran          #+#    #+#             */
/*   Updated: 2024/10/31 16:21:53 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap clap("Teddy");
	ScavTrap scav("Ego");

    for (int i = 0; i < 9; ++i)
	{
        clap.attack("Target");
        scav.attack("Target");
    }
	clap.takeDamage(1);
	scav.takeDamage(11);

    for (int i = 0; i < 6; ++i)
	{
        clap.beRepaired(1);
        scav.beRepaired(1);
    }

	clap.attack("Target1");
	scav.attack("Target2");

	scav.guardGate();

	// clap.beRepaired(2);
	// scav.beRepaired(2);
	return 0;
}