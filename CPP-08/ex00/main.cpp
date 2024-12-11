/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:26:31 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/11 22:32:52 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main( void )
{

	std::cout << "---Test Vector---" << std::endl;

	std::vector<int> vec;

	for(int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}
	try
	{
		std::cout << *easyfind(vec, 3) << std::endl;
		std::cout << *easyfind(vec, 10) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---Test List---" << std::endl;

	std::list<int> lst;
	for(int y = 0; y < 50; y++)
	{
		lst.push_back(y);
	}
	try
	{
		std::cout << *easyfind(lst, 14) << std::endl;
		std::cout << *easyfind(lst, 25) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---Test double ended queue---" << std::endl;

	std::deque<int> deq;
	for(int x = 0; x < 500; x++)
	{
		deq.push_back(x);
	}
	try
	{
		std::cout << *easyfind(deq, 245) << std::endl;
		std::cout << *easyfind(deq, 501) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}
