/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:42:52 by tguerran          #+#    #+#             */
/*   Updated: 2024/10/23 14:08:38 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
    std::string strBrain = "HI THIS IS BRAIN";
    std::string *stringPTR = &strBrain;
	std::string &stringREF = strBrain;

	std::cout << "adresse de strBrain: " << &strBrain << std::endl;
    std::cout << "adresse de stringPTR: "<< stringPTR << std::endl;
	std::cout << "adresse de stringREF: " << &stringREF << std::endl;

	std::cout << "Valeur de strBrain: " << strBrain << std::endl;
    std::cout << "Valeur de stringPTR: "<< *stringPTR << std::endl;
	std::cout << "Valeur de stringREF: " << stringREF << std::endl;
    return 0;
}