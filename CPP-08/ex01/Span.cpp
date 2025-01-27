/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 00:11:34 by tguerran          #+#    #+#             */
/*   Updated: 2025/01/27 01:48:00 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _numbers(),  _maxSize(N)
{
    if(N > MAX_SPAN_SIZE)
        throw std::invalid_argument("Span size is too high or too low");
}

Span::Span(Span const &obj) :  _numbers(obj._numbers), _maxSize(obj._maxSize)
{
    *this = obj;
}

Span &Span::operator=(Span const &obj)
{
    if (this != &obj)
    {
        _numbers = obj._numbers;
    }
    return *this;
}

Span::~Span()
{
    
}

void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw std::overflow_error("Span is full. Cannot add more numbers");
    _numbers.push_back(number);
}

int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to calculate span");
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    int shortest = INT_MAX;
    
    for (size_t i = 1; i < sorted.size(); i++)
    {
        int diff = sorted[i] - sorted[i - 1];
        if(diff < shortest)
            shortest = diff;
    }
    return shortest;
}

int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to calculate span");
    
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return max - min;
}