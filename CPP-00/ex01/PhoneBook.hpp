/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:34:43 by tguerran          #+#    #+#             */
/*   Updated: 2024/10/17 16:20:09 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook 
{
    public:
        PhoneBook();
        void addContact();
        void searchContact() const;

    private:
        Contact contacts[8];
        int nextIndex;
        std::string truncateString(const std::string& str) const;
};

#endif