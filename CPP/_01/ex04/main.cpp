/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:29:42 by gpanico           #+#    #+#             */
/*   Updated: 2023/05/17 08:44:18 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int	main(int argc, char *argv[])
{
	std::fstream	fs;
	std::string		filename;
	std::string		text;
	std::string		line;
	std::string		s1, s2;
	size_t			pos;

	if (argc != 4)
	{
		std::cout << "Usage error: ./replace [filename]";
		std::cout <<" [string1] [string2]" << std::endl;
		return (1);
	}
	filename = argv[1];
	fs.open(filename.c_str(), std::fstream::in);
	if (!fs.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return (1);
	}
	while (std::getline(fs, line))
		text += line + "\n";
	fs.close();
	//text.pop_back();
	s1 = argv[2];
	s2 = argv[3];
	filename += ".replace";
	fs.open(filename.c_str(), std::fstream::out);
	if (!fs.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return (1);
	}
	pos = 0;
	while (text.size())
	{
		pos = text.find(s1);
		if (pos == std::string::npos)
		{
			fs << text.substr(0, pos);
			text = "";
		}
		else
		{
			fs << text.substr(0, pos);
			fs << s2;
			text = text.substr(pos + s1.size(), std::string::npos);
		}
	}
	fs.close();
	return (1);
}
