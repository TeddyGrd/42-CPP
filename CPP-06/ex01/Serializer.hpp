/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 03:01:54 by tguerran          #+#    #+#             */
/*   Updated: 2025/01/17 15:12:58 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

typedef unsigned long uintptr_t;

struct Data
{
    int number;
    std::string text;
};

class Serializer
{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
        Serializer(Serializer const& obj);
        Serializer &operator=(Serializer const& obj);
        
    private:
        Serializer();
        ~Serializer();
};

#endif