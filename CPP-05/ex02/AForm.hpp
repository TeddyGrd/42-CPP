/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:41:56 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/21 00:57:54 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
    public:
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        virtual ~AForm();
        int getGradeToSign() const;
        int getGradeToExecute() const;
        std::string getName() const;
        bool getIsSigned() const;
        void beSigned(const Bureaucrat& bureaucrat);

        virtual void execute(const Bureaucrat& executor) const = 0;
        
    protected:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;

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
};

std::ostream& operator<<(std::ostream& out, const AForm& aform);

#endif