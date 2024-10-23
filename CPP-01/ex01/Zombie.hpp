/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:36:25 by tguerran          #+#    #+#             */
/*   Updated: 2024/10/23 02:03:42 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie 
{
    public:
		Zombie();
        Zombie(std::string name);
        void announce(void);
		void setName(std::string name);
        ~Zombie();
    private:
        std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif