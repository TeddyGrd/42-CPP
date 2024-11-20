/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:19:33 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/21 00:32:47 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& name, int gradeToSign , int gradeToExecute)
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

Form::~Form()
{
    std::cout << "Form " << name << " destroyed" << std::endl; 
}

std::string Form::getName() const
{
    return name;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if(bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    if (isSigned)
    {
        return;
    }
    isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << "Form " << form.getName() << " (sign grade: " << form.getGradeToSign()
        << ", execute grade: " << form.getGradeToExecute()
        << ", signed: ";
    if(form.getIsSigned())
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