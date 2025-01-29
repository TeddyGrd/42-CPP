/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:26:15 by tguerran          #+#    #+#             */
/*   Updated: 2025/01/13 01:10:03 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cerr << "Usage: ./ex01 \"operation\"" << std::endl;
        return 1;
    }
    try
    {
        RPN rpn;
        int result = rpn.calculate(argv[1]);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}