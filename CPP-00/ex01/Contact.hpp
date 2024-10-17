/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 00:35:32 by tguerran          #+#    #+#             */
/*   Updated: 2024/10/17 16:15:17 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iomanip>

class Contact
{
    public:
        Contact();
        void setContact(std::string fname, std::string lname, std::string phone, std::string nickname, std::string secret);
        void displayContact() const;
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getSummary() const;

    private:
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    std::string nickname;
    std::string darkestSecret;
};

#endif