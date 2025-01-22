/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:40:56 by tguerran          #+#    #+#             */
/*   Updated: 2025/01/22 16:10:39 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}

// int main()
// {
//     try {
//         Array<int> emptyArray;
//         std::cout << "Empty array size: " << emptyArray.size() << std::endl;
//         Array<std::string> stringArray(3);
//         std::cout << "String array size: " << stringArray.size() << std::endl;
//         stringArray[0] = "Hello";
//         stringArray[1] = "World";
//         stringArray[2] = "42";
//         for (unsigned int i = 0; i < stringArray.size(); ++i)
//         {
//             std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;
//         }
//         Array<std::string> copyArray(stringArray);
//         std::cout << "Copy array: ";
//         for (unsigned int i = 0; i < copyArray.size(); ++i)
//         {
//             std::cout << copyArray[i] << " ";
//         }
//         std::cout << std::endl;
//         Array<std::string> assignedArray;
//         assignedArray = stringArray;
//         std::cout << "Assigned array: ";
//         for (unsigned int i = 0; i < assignedArray.size(); ++i)
//         {
//             std::cout << assignedArray[i] << " ";
//         }
//         std::cout << std::endl;
//         try
//         {
//             std::cout << stringArray[10] << std::endl;
//         }
//         catch (const std::exception& e)
//         {
//             std::cerr << "Exception caught: " << e.what() << std::endl;
//         }
//         Array<Array<int> > matrix(3);
//         for (unsigned int i = 0; i < 3; ++i)
//         {
//             matrix[i] = Array<int>(3);
//             for (unsigned int j = 0; j < 3; ++j)
//             {
//                 matrix[i][j] = i * 3 + j;
//             }
//         }
//         std::cout << "Matrix: " << std::endl;
//         for (unsigned int i = 0; i < 3; ++i)
//         {
//             for (unsigned int j = 0; j < 3; ++j)
//             {
//                 std::cout << matrix[i][j] << " ";
//             }
//             std::cout << std::endl;
//         }
//     }
//     catch (const std::exception& e)
//     {
//         std::cerr << "Unexpected exception: " << e.what() << std::endl;
//     }
//     return 0;
// }
