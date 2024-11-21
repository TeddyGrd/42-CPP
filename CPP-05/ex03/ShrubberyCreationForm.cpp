/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:42:13 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/21 02:46:10 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    
}

void ShrubberyCreationForm::execute( const Bureaucrat& executor) const
{
    if(!getIsSigned())
    {
        throw AForm::GradeTooLowException();
    }
    if(executor.getGrade() > getGradeToExecute())
    {
        throw AForm::GradeTooLowException();
    }

    std::ofstream outFile((target + "_schrubbery").c_str());
    if(!outFile)
    {
        std::cerr << "Failed to create file " << target + "_schrubbery" << std::endl;
        return;
    }

    outFile << "          &&& &&  & &&" << std::endl;
    outFile << "      && &'/&'|& ()|/ @, &&" << std::endl;
    outFile << "      &'/(/&/&||/& /_/)_&/_&" << std::endl;
    outFile << "   &() &'|&|()|/&'/ '%' & ()" << std::endl;
    outFile << "  &_|_&&_' |& |&&/&__%_/_& &&" << std::endl;
    outFile << "&&   && & &| &| /& & % ()& /&&" << std::endl;
    outFile << " ()&_---()&'&||&&-&&--%---()~" << std::endl;
    outFile << "     &&     '|||" << std::endl;
    outFile << "             |||" << std::endl;
    outFile << "             |||" << std::endl;
    outFile << "             |||" << std::endl;
    outFile << "       , -=-~  .-^- _" << std::endl;

    outFile.close();

    std::cout << "Shrubbery created at " << target + "_shrubbery" << std::endl;
}