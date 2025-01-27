/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 00:08:40 by tguerran          #+#    #+#             */
/*   Updated: 2025/01/27 01:51:11 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack &operator=(MutantStack const &other);
        ~MutantStack();

        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
    private:

};

#include "MutantStack.tpp"

#endif