/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:21:53 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/21 02:32:44 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{
    public:
        Bureaucrat(const std::string& name, int grade);
        ~Bureaucrat();

        void incrementGrade();
        void decrementGrade();
        void signForm(AForm& form);
        void executeForm(const AForm& form) const;

        std::string getName() const;
        int getGrade() const;

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
    private:
        std::string const name;
        int grade;
};

std::ostream& operator<<(std::ostream& out ,const Bureaucrat& b);

#endif