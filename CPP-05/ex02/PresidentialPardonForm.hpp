/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:42:05 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/21 02:41:53 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "fstream"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(const std::string& target);
        ~PresidentialPardonForm();

        void execute(const Bureaucrat& executor) const;
    
    private:
        std::string target;
};

#endif