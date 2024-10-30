/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:46:39 by tguerran          #+#    #+#             */
/*   Updated: 2024/10/30 03:04:54 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap("Teddy");

	clap.attack("Target1");
	clap.attack("Target2");

	clap.takeDamage(4);
	clap.takeDamage(2);

	clap.beRepaired(1);
	clap.beRepaired(1);

	for(int i = 0; i < 10; i++)
	{
		clap.attack("Energy drain Target");
	}
	clap.beRepaired(2);

	return 0;
}