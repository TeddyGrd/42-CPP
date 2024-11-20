/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:21:55 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/21 00:35:25 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        Bureaucrat hermes("Hermes", 1);
        Bureaucrat fry("Fry", 100);
        Form importantForm("ImportantForm", 20, 10);
        Form trivialForm("TrivialForm", 120, 100);

        std::cout << importantForm << std::endl;
        std::cout << trivialForm << std::endl;

        try {
            fry.signForm(importantForm);
        } catch (const std::exception& e) {
            std::cerr << "Exception 1: " << e.what() << std::endl;
        }
        hermes.signForm(importantForm);

        fry.signForm(trivialForm);

        try {
            hermes.signForm(importantForm);
        } catch (const std::exception& e) {
            std::cerr << "Exception 2: " << e.what() << std::endl;
        }

        std::cout << importantForm << std::endl;
        std::cout << trivialForm << std::endl;

        try {
            Form invalidForm("InvalidForm", 0, 150);
        } catch (const std::exception& e) {
            std::cerr << "Exception 3: " << e.what() << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception générale attrapée : " << e.what() << std::endl;
    }

    return 0;
}
