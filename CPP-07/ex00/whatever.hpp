/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:26:41 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/10 14:41:03 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include "iostream"

template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
const T& min(const T& a, const T& b)
{
    if(a > b)
        return b;
    else if(a < b)
        return a;
    else
        return b;
}

template <typename T>
const T& max(const T& a, const T& b)
{
    if(a < b)
        return b;
    else if(a > b)
        return a;
    else
        return b;
}

#endif