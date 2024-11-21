/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:42:15 by tguerran          #+#    #+#             */
/*   Updated: 2024/11/21 02:42:10 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "fstream"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm(const std::string& target);
        ~ShrubberyCreationForm();

        void execute(const Bureaucrat& executor) const;
    
    private:
        std::string target;
};

#endif