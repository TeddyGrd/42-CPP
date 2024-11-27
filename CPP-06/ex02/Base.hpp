/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 01:08:07 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/27 03:03:04 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
    public:
        virtual ~Base();
    private:
        
};

class A : public Base
{
    
};

class B : public Base
{
    
};

class C : public Base
{

};

Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif