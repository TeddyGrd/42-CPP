/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:46:37 by tguerran          #+#    #+#             */
/*   Updated: 2024/12/10 15:12:36 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include "iostream"

template <typename T, typename F>
void iter(T* array, size_t length, F function)
{
    for(size_t i = 0; i < length; ++i)
    {
        function(array[i]);
    }
}

#endif