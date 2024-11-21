/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:42:02 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/21 02:02:43 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5), target(target)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{
    
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if(!getIsSigned())
    {
        throw AForm::GradeTooLowException();
    }
    if(executor.getGrade() > getGradeToExecute())
    {
        throw AForm::GradeTooLowException();
    }

    std::cout << "has been pardonned by Zaphod Beeblebrox" << std::endl;
}