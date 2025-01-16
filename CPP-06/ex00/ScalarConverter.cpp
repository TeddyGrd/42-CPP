/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:01:02 by tguerran          #+#    #+#             */
/*   Updated: 2025/01/16 00:37:14 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    
}

ScalarConverter::~ScalarConverter()
{
    
}

void ScalarConverter::convert(const std::string &literal)
{
    if(literal == "nan" || literal == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    if(literal == "+inf" || literal == "+inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return;
    }
    if(literal == "-inf" || literal == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }
    if(isCharLiteral(literal))
    {
        char c;
        if (literal.length() == 1)
        {
            c = literal[0];
        }
        std::cout << "char: " << c << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }
    if(isIntLiteral(literal))
    {
        int value = std::atoi(literal.c_str());
        std::cout << "char: ";
        if(value >= 0 && value <= 127 && std::isprint(value))
        {
            std::cout << static_cast<char>(value) << std::endl;
        } 
        else 
        {
            std::cout << "Non displayable" << std::endl;
        }
        std::cout << "int: " << value << std::endl;
        std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
        return;
    }
    if (isFloatLiteral(literal))
    {
        float value = std::strtof(literal.c_str(), NULL);

        std::cout << "char: impossible" << std::endl;
        std::cout << "int: " << static_cast<int>(value) << std::endl;
        if (std::floor(value) == value)
        {
            std::cout << "float: " << value << ".0f" << std::endl;
        }
        else
        {
            std::cout << "float: " << value << "f" << std::endl;
        }
        std::cout << "double: " << static_cast<double>(value) << std::endl;
        return;
    }
    if(isDoubleLiteral(literal))
    {
        double value = std::strtod(literal.c_str(), NULL);
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: " << static_cast<int>(value) << std::endl;
        if (std::floor(value) == value)
        {
            std::cout << "float: " << value << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
        }
        else
        {
            std::cout << "float: " << value << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(value) << std::endl;
        }
        return;
    }
    std::cout << "Conversion impossible pour : " << literal << std::endl;
}

bool isDoubleLiteral(const std::string& literal)
{
    if(literal.empty() || literal.find('.') == std::string::npos || literal[literal.size() -1] == 'f')
    {
        return false;
    }
    char *endptr = NULL;
    std::strtod(literal.c_str(), &endptr);
    return (*endptr == '\0');
}

bool isFloatLiteral(const std::string& literal)
{
    if(literal.empty() || literal[literal.size() -1] != 'f')
    {
        return false;
    }
    char *endptr = NULL;
    std::strtof(literal.c_str(), &endptr);
    return (endptr == &literal[literal.size() -1]);
}

bool isIntLiteral(const std::string& literal)
{
    if(literal.empty())
    {
        return false;
    }
    char *endptr = NULL;
    long value = std::strtol(literal.c_str(), &endptr, 10);

    if(*endptr != '\0')
    {
        return false;
    }
    if(value < INT_MIN || value > INT_MAX)
    {
        return false;
    }
    return true;
}

bool isCharLiteral(const std::string& literal)
{
    if(literal.length() == 1 && std::isprint(literal[1]) )
    {
        return false;
    }
    if(literal.length() >= 2)
    {
        return false;
    }
    return true;
}