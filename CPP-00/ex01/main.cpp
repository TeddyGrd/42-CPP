/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:23:24 by tguerran          #+#    #+#             */
/*   Updated: 2024/10/17 16:39:08 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while(true)
    {
		std::cout << "enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin,command);

		if(command == "ADD")
		{
			phoneBook.addContact();
		}
		else if(command == "SEARCH")
		{
			phoneBook.searchContact();
		}
		else if(command == "EXIT")
		{
			break;
		}
		else
		{
			std::cout << "unknow command. please enter ADD, SEARCH or EXIT" << std::endl;
		}
    }
	std::cout << "exiting programm" << std::endl;
	return 0;
}