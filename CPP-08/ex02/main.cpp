/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:26:31 by tguerran          #+#    #+#             */
/*   Updated: 2025/01/27 02:29:51 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    std::cout << "=== Test avec MutantStack ===" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(10);
        mstack.push(42);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        MutantStack<int>::iterator found = std::find(mstack.begin(), mstack.end(), 42);
        if (found != mstack.end())
        {
            std::cout << "Found value: " << *found << std::endl;
        }
        else
        {
            std::cout << "Value 42 not found in the stack." << std::endl;
        }
    }

    std::cout << "=== Test avec std::list ===" << std::endl;
    {
        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(17);
        std::cout << lst.back() << std::endl;
        lst.pop_back();
        std::cout << lst.size() << std::endl;
        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        lst.push_back(10);
        lst.push_back(42);
        lst.push_back(0);

        std::list<int>::iterator it = lst.begin();
        std::list<int>::iterator ite = lst.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::list<int>::iterator found = std::find(lst.begin(), lst.end(), 42);
        if (found != lst.end())
        {
            std::cout << "Found value: " << *found << std::endl;
        }
        else
        {
            std::cout << "Value 42 not found in the list" << std::endl;
        }
    }
    return 0;
}
