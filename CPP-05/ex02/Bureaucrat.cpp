/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:21:50 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/21 02:33:08 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)
{
    if(grade < 1)
        throw GradeTooHighException();
    if(grade > 150)
        throw GradeTooLowException();
    std::cout << "Bureaucrat " << name << " created with grade " << grade << "." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << name << " is destroyed" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    if(grade <= 1)
    {
        throw GradeTooHighException();
    }
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if(grade >= 150)
    {
        throw GradeTooLowException();
    }
    grade++;
}

void Bureaucrat::signForm(AForm& form)
{
    if(form.getIsSigned())
    {
        std::cout << name << " couldn't sign " << form.getName() << " because it's already signed" << std::endl;
        return;
    }
    try
    {
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.getName() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm& form) const
{
    try
    {
        form.execute(*this);
        std::cout << getName() << " executed " << form.getName() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return out;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}