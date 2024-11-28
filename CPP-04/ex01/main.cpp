/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:46:39 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/28 03:32:49 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    const Animal* animals[10];
    for (int index = 0; index < 5; ++index)
	{
        animals[index] = new Dog();
    }
    for (int index = 5; index < 10; ++index)
	{
        animals[index] = new Cat();
    }
    for (int index = 0; index < 10; ++index) {
        delete animals[index];
    }
	Dog originalDog;
    originalDog.setIdea(0, "Play fetch");
    originalDog.setIdea(1, "Chase tail");

    Dog copiedDog = originalDog;

    std::cout << "Original Dog Idea 0: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copied Dog Idea 0: " << copiedDog.getIdea(0) << std::endl;

    originalDog.setIdea(0, "Guard the house");

    std::cout << "After modification:" << std::endl;
    std::cout << "Original Dog Idea 0: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copied Dog Idea 1: " << copiedDog.getIdea(1) << std::endl;


    return 0;
}