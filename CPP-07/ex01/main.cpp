/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:46:15 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/10 18:39:19 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void printIn(const int& x)
{
    std::cout << x << " ";
}

void toUpperCase(char& c)
{
    c = std::toupper(c);
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLength = sizeof(intArray) / sizeof(intArray[0]);
    iter(intArray, intLength, printIn);
    std::cout << std::endl;

    char charArray[] = {'a', 'b', 'c', 'd'};
    size_t charLength = sizeof(charArray) / sizeof(charArray[0]);
    iter(charArray, charLength, toUpperCase);

    for(size_t i = 0; i < charLength; i++)
    {
        std::cout << charArray[i] << " ";
    }
    std::cout << std::endl;
}