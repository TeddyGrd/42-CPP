/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:39:12 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/13 22:51:49 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}

Cat::Cat() : brain(new Brain())
{
    type = "Cat";
    std::cout << "Cat created with its own brain" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain))
{
    std::cout << "Cat copy created with a deep copy of Brain" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat assigned with a deep copy of Brain" << std::endl;
    if(this!= &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destroyed along with its Brain" << std::endl;
}