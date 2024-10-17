/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:59:38 by tguerran          #+#    #+#             */
/*   Updated: 2024/10/17 17:14:47 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <limits>

PhoneBook::PhoneBook() : nextIndex(0)
{
}

void PhoneBook::addContact()
{
    std::string fname, lname, phone, nickname, secret;

	std::cout << "enter your First name: ";
	std::getline(std::cin, fname);
	std::cout << "enter your Last name: ";
	std::getline(std::cin, lname);
	std::cout << "enter your Phone Number: ";
	std::getline(std::cin, phone);
	std::cout << "enter your Nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "enter your darkest secret: ";
	std::getline(std::cin, secret);

	contacts[nextIndex].setContact(fname, lname, phone, nickname, secret);

	nextIndex = (nextIndex + 1) % 8;
}

void PhoneBook::searchContact() const
{
	std::cout << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << std::endl;
	for(int i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) << i << "|"
					<< std::setw(10) << truncateString(contacts[i].getFirstName()) << "|"
					<< std::setw(10) << truncateString(contacts[i].getLastName()) << "|"
					<< std::setw(10) << truncateString(contacts[i].getNickname()) << std::endl;
	}
	std::cout << "Enter the index of the contacts to display: ";
	int index;
	std::cin >> index;

	if(std::cin.fail() || index < 0 || index >= 8) 
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid index!" << std::endl;
	}
	else
	{
		contacts[index].displayContact();
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string PhoneBook::truncateString(const std::string& str) const
{
	if(str.length() > 10)
		return str.substr(0,9) + ".";
	return str;
}