/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 01:07:41 by tguerran          #+#    #+#             */
/*   Updated: 2025/01/16 02:31:42 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
    std::srand(std::time(0));

    for (int i = 0; i < 10; ++i)
    {
        Base* obj = generate();

        std::cout << "Identification par pointeur : ";
        identify(obj);

        std::cout << "Identification par référence : ";
        identify(*obj);

        delete obj;
        std::cout << "---------------" << std::endl;
    }
    return 0;
}