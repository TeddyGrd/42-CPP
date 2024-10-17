/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 02:36:06 by tguerran          #+#    #+#             */
/*   Updated: 2024/10/17 16:24:33 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact() 
{
}

void Contact::setContact(std::string fname, std::string lname, std::string phone, std::string nickname, std::string secret)
{
    firstName = fname;
    lastName = lname;
    phoneNumber = phone;
    this->nickname = nickname;
    darkestSecret = secret;
}

void Contact::displayContact() const 
{
    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
    std::cout << "Nickname: " << this->nickname << std::endl;
    std::cout << "Darkest secret: " << darkestSecret << std::endl;
}

std::string Contact::getFirstName() const
{
	return firstName;
}

std::string Contact::getLastName() const
{
	return lastName;
}

std::string Contact::getNickname() const 
{
	return this->nickname;
}

std::string Contact::getSummary() const
{
    return firstName + " " + lastName + " (" + this->nickname + ")";
}
