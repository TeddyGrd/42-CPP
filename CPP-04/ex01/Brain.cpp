/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:38:14 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/14 00:03:05 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "brain created" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "brain copy created" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other)
{
    if(this != &other)
    {
        for(int i = 0; i < 100; i++)
        {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

void Brain::setIdea(int index, const std::string& idea)
{
    if(index >= 0 && index < 100)
    {
        ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const 
{
    if(index >= 0 && index < 100)
    {
        return ideas[index];
    }
    return "";
}

Brain::~Brain()
{
    std::cout << "Brain destroyed" << std::endl;
}