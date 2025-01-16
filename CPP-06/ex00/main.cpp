/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:41:17 by tguerran          #+#    #+#             */
/*   Updated: 2025/01/16 02:14:57 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        std::cout << "Usage: ./ex00 <value>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}

// int main()
// {
//     ScalarConverter::convert("'A'");
//     std::cout << "---------------" << std::endl;
//     ScalarConverter::convert("66");
//     std::cout << "---------------" << std::endl;
//     ScalarConverter::convert("67.0f");
//     std::cout << "---------------" << std::endl;
//     ScalarConverter::convert("68.0");
//     std::cout << "---------------" << std::endl;
//     ScalarConverter::convert("coucou");
//     std::cout << "---------------" << std::endl;
//     ScalarConverter::convert("nan");
//     std::cout << "---------------" << std::endl;
//     ScalarConverter::convert("+inf");
//     std::cout << "---------------" << std::endl;
//     ScalarConverter::convert("-inf");
//     std::cout << "---------------" << std::endl;
//     return 0;    
// }