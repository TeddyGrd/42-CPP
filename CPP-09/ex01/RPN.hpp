/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:26:12 by tguerran          #+#    #+#             */
/*   Updated: 2025/01/29 17:28:47 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class RPN
{
    public:
        RPN();
        RPN(const RPN& obj);
        RPN& operator=(const RPN& obj);
        ~RPN();
        int calculate(const std::string& expr);
    private:
        bool isOperator(char c) const;
        int performOperation(char op, int a, int b) const;
};

#endif