/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:16:42 by tguerran          #+#    #+#             */
/*   Updated: 2025/02/04 01:56:36 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    
}

PmergeMe::PmergeMe(const PmergeMe& obj)
{
	*this = obj;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
	(void)obj;
	return *this;
}

PmergeMe::~PmergeMe()
{
    
}

void PmergeMe::displayResult(std::vector<int> const& v, std::deque<int> const& d) const
{
    std::cout << "vector: ";
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
    std::cout << "deque: ";
	for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::binaryInsertVector(std::vector<int>& vec, int start, int end, int value) const
{
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (vec[mid] < value)
            start = mid + 1;
        else
            end = mid;
    }
    vec.insert(vec.begin() + start, value);
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& vec) const
{
    if (vec.size() <= 1)
        return;
    std::vector<int> larger, smaller;
    for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        if (vec[i] > vec[i + 1])
            std::swap(vec[i], vec[i + 1]);
        larger.push_back(vec[i + 1]);
        smaller.push_back(vec[i]);
    }
    if (vec.size() % 2 != 0)
    {
        smaller.push_back(vec.back());
    }
    fordJohnsonSortVector(larger);
    std::vector<size_t> jacobSeq = generateJacobsthalSequenceVector(smaller.size());
    for (size_t i = 0; i < jacobSeq.size(); ++i)
    {
        if (jacobSeq[i] < smaller.size())
        {
            binaryInsertVector(larger, 0, larger.size(), smaller[jacobSeq[i]]);
        }
    }
    vec = larger;
}

std::vector<size_t> PmergeMe::generateJacobsthalSequenceVector(size_t n) const
{
    std::vector<size_t> sequence;
    sequence.push_back(0);
    size_t j1 = 1, j2 = 3;
    while (j1 < n)
    {
        sequence.push_back(j1);
        size_t temp = j2;
        j2 = j2 * 2 - 1;
        j1 = temp;
    }
    for (size_t i = 0; i < n; ++i)
    {
        if (std::find(sequence.begin(), sequence.end(), i) == sequence.end())
        {
            sequence.push_back(i);
        }
    }
    return sequence;
}

std::deque<size_t> PmergeMe::generateJacobsthalSequenceDeque(size_t n) const
{
    std::deque<size_t> sequence;
    sequence.push_back(0);
    size_t j1 = 1, j2 = 3;
    while (j1 < n)
    {
        sequence.push_back(j1);
        size_t temp = j2;
        j2 = j2 * 2 - 1;
        j1 = temp;
    }
    for (size_t i = 0; i < n; ++i)
    {
        if (std::find(sequence.begin(), sequence.end(), i) == sequence.end())
        {
            sequence.push_back(i);
        }
    }
    return sequence;
}

void PmergeMe::binaryInsertDeque(std::deque<int>& deq, int start, int end, int value) const
{
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (deq[mid] < value)
            start = mid + 1;
        else
            end = mid;
    }
    deq.insert(deq.begin() + start, value);
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& deq) const
{
    if (deq.size() <= 1)
        return;
    std::deque<int> larger, smaller;
    for (size_t i = 0; i + 1 < deq.size(); i += 2)
    {
        if (deq[i] > deq[i + 1])
            std::swap(deq[i], deq[i + 1]);
        larger.push_back(deq[i + 1]);
        smaller.push_back(deq[i]);
    }
    if (deq.size() % 2 != 0)
    {
        smaller.push_back(deq.back());
    }
    fordJohnsonSortDeque(larger);
    std::deque<size_t> jacobSeq = generateJacobsthalSequenceDeque(smaller.size());
    for (size_t i = 0; i < jacobSeq.size(); ++i)
    {
        if (jacobSeq[i] < smaller.size())
        {
            binaryInsertDeque(larger, 0, larger.size(), smaller[jacobSeq[i]]);
        }
    }
    deq = larger;
}

void PmergeMe::sortDeque(std::deque<int>& deq) const
{
    clock_t start = clock();
    fordJohnsonSortDeque(deq);
    clock_t end = clock();
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process " << deq.size() << " elements with std::deque: "
              << duration << " µs" << std::endl;
}

void PmergeMe::sortVector(std::vector<int>& vec) const
{
    clock_t start = clock();
    fordJohnsonSortVector(vec);
    clock_t end = clock();
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process " << vec.size() << " elements with std::vector: "
              << duration << " µs" << std::endl;
}
