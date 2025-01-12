/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:26:10 by tguerran          #+#    #+#             */
/*   Updated: 2025/01/13 00:02:42 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <stdexcept>

RPN::RPN()
{
    
}
RPN::~RPN()
{
    
}

bool RPN::isOperator(char c) const
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::calculate(std::string const& expression)
{
    std::stack<int> stack;
    std::istringstream stream(expression);
    std::string token;
    while (stream >> token)
    {
        if (token.size() == 1 && isOperator(token[0]))
        {
            if (stack.size() < 2)
                throw std::runtime_error("Error: Not enough operands for operation");
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            int result = performOperation( token[0], a, b);
            stack.push(result);
        }
        else
        {
            int number;
            std::stringstream ss(token);
            ss >> number;

            if (ss.fail() || !ss.eof())
            {
                throw std::runtime_error("Error: Number expected");
            }
            if (number >= 10)
            {
                throw std::runtime_error("Error: Number must be less than 10 and greater than 0");
            }
            stack.push(number);
        }
    }
    if (stack.size() != 1)
        throw std::runtime_error("Error: invalid expression");
    return stack.top();
}

int RPN::performOperation( char op,int a, int b) const
{
    switch (op)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error: Division by zero");
            return a / b;
        default:
            throw std::runtime_error("Error: Invalid operator");
    }
}