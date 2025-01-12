/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:26:12 by tguerran          #+#    #+#             */
/*   Updated: 2025/01/09 16:32:04 by tguerran         ###   ########.fr       */
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
        ~RPN();
        int calculate(const std::string& expr);
    private:
        bool isOperator(char c) const;
        int performOperation(char op, int a, int b) const;
};

#endif