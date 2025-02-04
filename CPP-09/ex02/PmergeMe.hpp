/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:16:47 by tguerran          #+#    #+#             */
/*   Updated: 2025/02/04 01:55:45 by tguerran         ###   ########.fr       */
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

        void displayResult(const std::vector<int>& v, const std::deque<int>& d) const;

        void sortVector(std::vector<int>& deq) const;
        void sortDeque(std::deque<int>& deq) const;
        void fordJohnsonSortVector(std::vector<int>& vec) const;
        void fordJohnsonSortDeque(std::deque<int>& deq) const;
        std::deque<size_t> generateJacobsthalSequenceDeque(size_t n) const;
        std::vector<size_t> generateJacobsthalSequenceVector(size_t n) const;
        void binaryInsertVector(std::vector<int>& vec, int start, int end, int value) const;
        void binaryInsertDeque(std::deque<int>& deq, int start, int end, int value) const;

    private:
        void fordJohnsonMergeVector(std::vector<int>& main, std::vector<int>& subList) const;
        void fordJohnsonMergeDeque(std::deque<int>& main, std::deque<int>& subList) const;
};

#endif
