/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:21:55 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/20 16:38:43 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat hermes("Hermes", 42);
        std::cout << hermes << std::endl;

        hermes.decrementGrade();
        std::cout << hermes << std::endl;

        hermes.incrementGrade();
        std::cout << hermes << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "execption caught: " << e.what() << std::endl;
    }
}