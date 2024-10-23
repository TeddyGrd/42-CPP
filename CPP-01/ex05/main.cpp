/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:15:53 by tguerran          #+#    #+#             */
/*   Updated: 2024/10/23 18:59:54 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl;

	std::cout << "Testing DEBUG:" << std::endl;
	harl.complain("DEBUG");

	std::cout << "Testing INFO:" << std::endl;
	harl.complain("INFO");
	
	std::cout << "TESTING WARNING:" << std::endl;
	harl.complain("WARNING");
	
	std::cout << "Testing ERROR:" << std::endl;
	harl.complain("ERROR");
	return 0;
}