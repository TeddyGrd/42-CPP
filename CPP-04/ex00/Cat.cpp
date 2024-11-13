/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:39:12 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/13 15:59:45 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat created" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destroyed" << std::endl;
}