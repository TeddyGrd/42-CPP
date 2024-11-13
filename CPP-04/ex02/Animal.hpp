/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:15:56 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/14 00:51:16 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "iostream"

class Animal
{
    public:
        Animal();
        virtual ~Animal();
        virtual void makeSound() const = 0;
        std::string getType() const;
    protected:
        std::string type;
};

#endif