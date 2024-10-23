/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:42:52 by tguerran          #+#    #+#             */
/*   Updated: 2024/10/23 03:32:09 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
    std::string strBrain = "HI THIS IS BRAIN";
    std::string *strPtr = &strBrain;
	std::string &strRef = strBrain;

	std::cout << "adresse de strBrain: " << &strBrain << std::endl;
    std::cout << "adresse de strPtr: "<< strPtr << std::endl;
	std::cout << "adresse de strRef: " << &strRef << std::endl;

	std::cout << "Valeur de strBrain: " << strBrain << std::endl;
    std::cout << "Valeur de strPtr: "<< *strPtr << std::endl;
	std::cout << "Valeur de strRef: " << strRef << std::endl;
    return 0;
}