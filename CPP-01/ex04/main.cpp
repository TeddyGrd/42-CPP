/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:56:20 by tguerran          #+#    #+#             */
/*   Updated: 2024/10/23 17:21:58 by tguerran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

int main(int argc, char **argv)
{

	if(argc != 4)
	{
		std::cerr << "erreur : rappel usage : ./replace <fichier> <string_1> <string_2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream inputFile(filename.c_str());
	if(!inputFile.is_open())
	{
		std::cerr << "Erreur : Impossible d ouvrir le fichier !" << std::endl;
		return 1;
	}

	std::ofstream outputFile((filename + ".replace").c_str());
	if(!outputFile.is_open())
	{
		std::cerr << "Erreur : Impossible d ouvrir le fichier" << std::endl;
		return 1;
	}

	std::string content;
	while(std::getline(inputFile,content))
	{
		size_t pos = 0;
		while((pos = content.find(s1,pos)) != std::string::npos)
		{
			content.replace(pos,s1.length(),s2);
			pos += s2.length();
		}
		outputFile << content << std::endl;
		std::cout << content << std::endl;
	}
	inputFile.close();
	outputFile.close();
	return 0;
}