/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 00:47:44 by tguerran          #+#    #+#             */
/*   Updated: 2025/01/31 19:52:49 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

float toFloat(const std::string& str)
{
    std::stringstream s(str);
    float f;
    s >> f;
    if (s.fail() || !s.eof())
        throw std::invalid_argument("Error: invalid float value");
    return f;
}

int toInt(const std::string& str)
{
    std::stringstream s(str);
    int i;
    s >> i;
    if (s.fail() || !s.eof())
        throw std::invalid_argument("Error: invalid int value");
    return i;
}

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
    if (this != &obj)
    {
        _exchangeRates = obj._exchangeRates;
    }
    return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
    *this = obj;
}

BitcoinExchange::BitcoinExchange(const std::string& databaseFilename)
{
    loadDatabase(databaseFilename);
}

BitcoinExchange::~BitcoinExchange()
{

}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open datafile " << filename << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        std::string date, rateStr;
        char separator = ',';
        if (line.find('|') != std::string::npos)
            separator = '|';
        std::istringstream stream(line);
        if (!std::getline(stream, date, separator) || !std::getline(stream, rateStr))
        {
            std::cerr << "Error: invalid line in datafile " << filename << std::endl;
            continue;
        }
        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        rateStr.erase(0, rateStr.find_first_not_of(" \t"));
        rateStr.erase(rateStr.find_last_not_of(" \t") + 1);
        if (!isValidDate(date))
        {
            std::cerr << "Error: invalid date in datafile " << filename << std::endl;
            continue;
        }
        float rate;
        try
        {
            rate = toFloat(rateStr);
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error: invalid rate in datafile " << filename << std::endl;
            continue;
        }
        _exchangeRates[date] = rate;
    }
    file.close();
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    int year, month, day;
    try
    {
        year = toInt(date.substr(0, 4));
        month = toInt(date.substr(5, 2));
        day = toInt(date.substr(8, 2));
    }
    catch (const std::exception& e)
    {
        return false;
    }

    if(year < 1900 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    
    if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    
    if(month == 2)
    {
        bool leapYear = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
        if (leapYear && day > 29)
            return false;
    }
    return true;
}

float BitcoinExchange::calculateValue(const std::string& date, float value) const
{
    if(value < 0)
    {
        std::cerr << "Error: value must be positive" << std::endl;
        return 0;
    }
    std::map<std::string, float>::const_iterator it = _exchangeRates.find(date);
    if(it != _exchangeRates.end())
        return value * it->second;
    std::map<std::string, float>::const_iterator lower = _exchangeRates.lower_bound(date);
    if (lower == _exchangeRates.begin())
    {
        std::cerr << "Error: no exchange rate available for this date" << std::endl;
        return 0;
    }
    lower--;
    return value * lower->second;
}

void BitcoinExchange::printDatabase() const
{
    for (std::map<std::string, float>::const_iterator it = _exchangeRates.begin(); it != _exchangeRates.end(); it++)
        std::cout << it->first << ": " << it->second << std::endl;
}