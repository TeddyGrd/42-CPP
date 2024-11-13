/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:37:06 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/13 23:50:35 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}

Dog::Dog() : brain(new Brain())
{
    type = "Dog";
    std::cout << "Dog created with its own brain" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain))
{
    std::cout << "Dog copy created with a deep copy of brain" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog assigned with a deep copy of brain" << std::endl;
    if(this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

void Dog::setIdea(int index, const std::string& idea)
{
    brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
    return brain->getIdea(index);
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destroyed along with its brain" << std::endl;
}