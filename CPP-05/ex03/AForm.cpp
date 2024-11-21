/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:41:53 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/21 03:17:47 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string& name, int gradeToSign , int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if(gradeToSign < 1 || gradeToExecute < 1)
    {
        throw GradeTooHighException();
    }
    if(gradeToSign > 150 || gradeToExecute > 150)
    {
        throw GradeTooLowException();
    }
    std::cout << "Form " << name << " created with sign grade " << gradeToSign
            << " and execution grade " << gradeToExecute << std::endl;
}

AForm::~AForm()
{
    std::cout << "Form " << name << " destroyed" << std::endl; 
}

std::string AForm::getName() const
{
    return name;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if(bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    if (isSigned)
    {
        return;
    }
    isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream& out, const AForm& aform)
{
    out << "Form " << aform.getName() << " (sign grade: " << aform.getGradeToSign()
        << ", execute grade: " << aform.getGradeToExecute()
        << ", signed: ";
    if(aform.getIsSigned())
    {
        out << "yes";
    }
    else
    {
        out << "no";
    }
    out << ")";
    return out;
}