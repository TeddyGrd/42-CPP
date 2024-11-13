/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:37:06 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/13 15:57:42 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog created" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destroyed" << std::endl;
}