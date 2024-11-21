/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:21:55 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/21 14:52:19 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    try
    {
        Bureaucrat president("President", 1);
        Bureaucrat hermes("Hermes", 50);

        ShrubberyCreationForm shrubbery("Home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Fry");

        std::cout << "--------" << std::endl;

        std::cout << shrubbery << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;

        std::cout << "--------" << std::endl;

        hermes.signForm(shrubbery);
        president.signForm(robot);
        president.signForm(pardon);

        std::cout << "--------" << std::endl;

        hermes.executeForm(shrubbery);
        president.executeForm(shrubbery);
        president.executeForm(robot);
        president.executeForm(pardon);

        std::cout << "--------" << std::endl;

        std::cout << shrubbery << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;
        //AForm form("TestForm", 20, 10);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception générale attrapée : " << e.what() << std::endl;
    }
    return 0;
}
