/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:34:19 by tguerran          #+#    #+#             */
/*   Updated: 2024/10/16 18:31:59 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    if(argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for(int i = 1; i < argc; i++)
        {
            for(int y = 0; argv[i][y] ;y++)
            {
                std::cout << (char)std::toupper(argv[i][y]);
            }
			if (i != argc - 1)
				std::cout << " ";
        }
		std::cout << std::endl;
    }
    return 0;
}