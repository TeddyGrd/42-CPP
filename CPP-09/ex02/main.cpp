/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:16:44 by tguerran          #+#    #+#             */
/*   Updated: 2025/01/29 21:48:53 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <iostream>
#include <cstdlib>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: No numbers provided" << std::endl;
        return 1;
    }
    std::vector<int> vec;
    std::deque<int> deq;
    try
    {
        for (int i = 1; i < argc; ++i)
        {
            std::string input = argv[i];
            for (size_t j = 0; j < input.size(); ++j)
            {
                if (!std::isdigit(input[j]) && !(j == 0 && input[j] == '-'))
                {
                    throw std::runtime_error("Error: Non-numeric input detected: " + input);
                }
            }
            int value = std::atoi(argv[i]);
            if (value < 0)
            {
                throw std::runtime_error("Error: Negative numbers are not allowed: " + input);
            }

            vec.push_back(value);
            deq.push_back(value);
        }
        PmergeMe sorter;
        std::cout << "Before sorting:" << std::endl;
        sorter.displayResult(vec, deq);
        sorter.fordJohnsonSort(vec);
        sorter.fordJohnsonSort(deq);
        std::cout << "After sorting:" << std::endl;
        sorter.displayResult(vec, deq);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
