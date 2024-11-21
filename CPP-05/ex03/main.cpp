/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:21:55 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/21 16:02:19 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"


int main() {
    try {
        Intern intern;

        Bureaucrat highLevel("HighLevel", 1); 
        Bureaucrat midLevel("MidLevel", 72);
        Bureaucrat lowLevel("LowLevel", 150);

        std::cout << "-------- Form Creation --------" << std::endl;

        AForm* shrubbery = intern.makeForm("shrubbery creation", "Garden");
        AForm* robotomy = intern.makeForm("robotomy request", "Bender");
        AForm* pardon = intern.makeForm("presidential pardon", "Fry");

        std::cout << "-------- Signing Forms --------" << std::endl;

        if (shrubbery) midLevel.signForm(*shrubbery); 
        if (robotomy) midLevel.signForm(*robotomy);
        if (pardon) lowLevel.signForm(*pardon);

        std::cout << "-------- Executing Forms --------" << std::endl;

        if (shrubbery) {
            lowLevel.executeForm(*shrubbery);
            midLevel.executeForm(*shrubbery);
        }

        if (robotomy) {
            lowLevel.executeForm(*robotomy);
            midLevel.executeForm(*robotomy);
            highLevel.executeForm(*robotomy);
        }

        if (pardon) {
            midLevel.executeForm(*pardon);
            highLevel.executeForm(*pardon);
        }

        std::cout << "-------- Final State --------" << std::endl;

        if (shrubbery) std::cout << *shrubbery << std::endl;
        if (robotomy) std::cout << *robotomy << std::endl;
        if (pardon) std::cout << *pardon << std::endl;

        std::cout << "-------- Cleaning Up --------" << std::endl;

        delete shrubbery;
        delete robotomy;
        delete pardon;

    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}