/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 03:01:19 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/27 01:01:01 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data data;
    
    data.number = 42;
    data.text = "Salut je suis un test";
    std::cout << "Original Data address: " << &data << std::endl;
    std::cout << "Original Data content: " << data.number << ", " << data.text << std::endl;

    std::cout << "------------------------------" << std::endl;
    
    uintptr_t serialized = Serializer::serialize(&data);
    std::cout << "Serialized value: " << serialized << std::endl;
    
    std::cout << "------------------------------" << std::endl;
    
    Data* deserialized = Serializer:: deserialize(serialized);
    std::cout << "Deserialized Data address: " << deserialized << std::endl;
    
    std::cout << "------------------------------" << std::endl;
    
    if(deserialized == &data)
    {
        std::cout << "Pointers match! Deserialization succeeded" << std::endl;
        std::cout << "Deserialized Data content: " << deserialized->number << ", " << deserialized->text << std::endl;
    } 
    else 
    {
        std::cout << "Error: Pointers do not match" << std::endl;
    }
    return 0;
}