/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:53:19 by tguerran          #+#    #+#             */
/*   Updated: 2025/01/03 00:52:54 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        explicit BitcoinExchange(const std::string& databaseFilename);
        ~BitcoinExchange();

        void loadDatabase(const std::string& filename);
        float calculateValue(const std::string& date, float value) const;
        static bool isValidDate(const std::string& date);
        void printDatabase() const;

    private:
        std::map<std::string, float> _exchangeRates;
};

#endif