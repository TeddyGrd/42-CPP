/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 01:40:12 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/27 03:02:58 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"

Base* generate()
{
    int random = std::rand() % 3;

    if(random == 0)
    {
        return new A();
    }
    else if(random == 1)
    {
        return new B();
    }
    else
    {
        return new C();
    }
}

void identify(Base* p)
{
    if(dynamic_cast<A*>(p))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout << "B" << std::endl;
    }
    else if(dynamic_cast<C*>(p))
    {
        std::cout << "C" << std::endl;
    }
    else
    {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (...)
    {

    }
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (...)
    {
        
    }
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (...)
    {
        
    }
    std::cout << "Unknown type" << std::endl;
}