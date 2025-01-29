/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:16:47 by tguerran          #+#    #+#             */
/*   Updated: 2025/01/29 21:25:31 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <algorithm>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& obj);
        PmergeMe& operator=(const PmergeMe& obj);
        ~PmergeMe();
        void displayResult(std::vector<int> const& v, std::deque<int> const& d) const;
        void fordJohnsonSort(std::vector<int>& vec) const;
        void fordJohnsonSort(std::deque<int>& deq) const;
    
    private:
        void fordJohnsonMerge(std::vector<int>& main, std::vector<int>& subList) const;
        void fordJohnsonMerge(std::deque<int>& main, std::deque<int>& subList) const;
};

#endif