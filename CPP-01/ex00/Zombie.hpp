/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:25:19 by tguerran          #+#    #+#             */
/*   Updated: 2024/10/18 16:29:51 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    public:
        Zombie(std::string name);
        void announce(void);
        ~Zombie();
    private:
        std::string name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif