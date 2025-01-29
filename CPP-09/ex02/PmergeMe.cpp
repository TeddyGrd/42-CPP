/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:16:42 by tguerran          #+#    #+#             */
/*   Updated: 2025/01/29 21:33:23 by tguerran         ###   ########.fr       */
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

void PmergeMe::fordJohnsonSort(std::vector<int>& vec) const
{
	if (vec.size() < 2)
		return;
	clock_t start = clock();
	std::vector<int> mainList;
	std::vector<int> subList;
	for (size_t i = 0; i + 1 < vec.size(); i += 2)
	{
		if (vec[i] > vec[i + 1])
			std::swap(vec[i], vec[i + 1]);
        mainList.push_back(vec[i + 1]);
        subList.push_back(vec[i]);
    }
    if (vec.size() % 2 != 0)
        subList.push_back(vec.back());
    std::sort(mainList.begin(), mainList.end());
    fordJohnsonMerge(mainList, subList);
    vec = mainList;
	clock_t end = clock();
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process " << vec.size() << " elements with FordJohnson using std::vector: " << duration << " us" << std::endl;
}

void PmergeMe::fordJohnsonSort(std::deque<int>& deq) const
{
	if (deq.size() < 2)
		return;
	clock_t start = clock();
    std::deque<int> mainList;
    std::deque<int> subList;
    for (size_t i = 0; i + 1 < deq.size(); i += 2)
    {
        if (deq[i] > deq[i + 1])
            std::swap(deq[i], deq[i + 1]);
        mainList.push_back(deq[i + 1]);
        subList.push_back(deq[i]);
    }
    if (deq.size() % 2 != 0)
        subList.push_back(deq.back());
    std::sort(mainList.begin(), mainList.end());
    fordJohnsonMerge(mainList, subList);
    deq = mainList;
	clock_t end = clock();
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process " << deq.size() << " elements with FordJohnson using std::deque: " << duration << " us" << std::endl;
}


void PmergeMe::fordJohnsonMerge(std::vector<int>& mainList, std::vector<int>& subList) const
{
    for (size_t i = 0; i < subList.size(); i++)
    {
        std::vector<int>::iterator it = std::lower_bound(mainList.begin(), mainList.end(), subList[i]);
        mainList.insert(it, subList[i]);
    }
}

void PmergeMe::fordJohnsonMerge(std::deque<int>& mainList, std::deque<int>& subList) const
{
    for (size_t i = 0; i < subList.size(); i++)
    {
        std::deque<int>::iterator it = std::lower_bound(mainList.begin(), mainList.end(), subList[i]);
        mainList.insert(it, subList[i]);
    }
}
