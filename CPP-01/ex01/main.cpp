/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:36:14 by tguerran          #+#    #+#             */
/*   Updated: 2024/10/23 02:40:46 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 3;

    Zombie* horde = zombieHorde(N,"Zombie man");
    for(int i = 0; i < N ; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
	return 0;
}