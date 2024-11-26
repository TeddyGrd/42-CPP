/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:45:17 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/26 02:18:33 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <climits>
#include <cctype>
#include <cstdlib>
#include <cmath>

class ScalarConverter
{
    public:
        static void convert(const std::string &litteral);
    private:
        ScalarConverter();
        ~ScalarConverter();
};

bool isCharLiteral(const std::string& literal);
bool isIntLiteral(const std::string& literal);
bool isFloatLiteral(const std::string& literal);
bool isDoubleLiteral(const std::string& literal);

#endif