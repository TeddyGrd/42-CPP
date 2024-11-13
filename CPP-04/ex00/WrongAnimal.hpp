/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:31:25 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/13 16:09:38 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "iostream"

class WrongAnimal
{
    public:
        WrongAnimal();
        ~WrongAnimal();
        void makeSound() const;
    protected:
        std::string type;
};

#endif