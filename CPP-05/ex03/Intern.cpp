/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:55:17 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/21 15:37:00 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern()
{
    std::cout << "Intern created" << std::endl;
}

Intern::~Intern()
{
    std::cout << "intern destroyed" << std::endl;
}

AForm* createShrubery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* createPardon(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    struct FormMapping
    {
        std::string name;
        AForm* (*constructor)(const std::string& target);
    };

    FormMapping forms[] = 
    {
        {"shrubbery creation", &createShrubery},
        {"robotomy request", &createRobotomy},    
        {"presidential pardon", &createPardon},   
    };

    for (size_t i = 0; i < 3; i++)
    {
        if(forms[i].name == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].constructor(target);
        }
    }
    std::cerr << "Intern couldn't create " << formName << " because it doesn't exist" << std::endl;
    return NULL;
}