/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:48:56 by tguerran          #+#    #+#             */
/*   Updated: 2025/01/03 02:23:46 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main()
{
    BitcoinExchange exchange("data.csv");

    try
    {
        std::cout << exchange.calculateValue("2022-01-01", 1) << std::endl;
        std::cout << exchange.calculateValue("2022-01-02", 10) << std::endl;
        std::cout << exchange.calculateValue("2022-01-03", 100) << std::endl;
    } catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    exchange.printDatabase();

    return 0;
}