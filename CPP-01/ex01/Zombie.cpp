/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:36:46 by tguerran          #+#    #+#             */
/*   Updated: 2024/10/23 02:23:25 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    name = "unnamed Zombie";
}

Zombie::Zombie(std::string z_name) : name(z_name)
{
    
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string z_name)
{
    name = z_name;
}

Zombie::~Zombie()
{
    std::cout << name << " is destroyed" << std::endl;
}
