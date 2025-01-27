/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 00:08:40 by tguerran          #+#    #+#             */
/*   Updated: 2025/01/27 01:43:07 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define MAX_SPAN_SIZE 1000000

class Span
{
    public:
        Span(unsigned int N);
        Span(Span const &obj);
        Span &operator=(Span const &obj);
        ~Span();

        void addNumber(int number);

        template <typename Iterator>
        void addRange(Iterator begin, Iterator end);

        int shortestSpan() const;
        int longestSpan() const;

    private:
        std::vector<int> _numbers;
        const unsigned int _maxSize;
};

#include "Span.tpp"

#endif