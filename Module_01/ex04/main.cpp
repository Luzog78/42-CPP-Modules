/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 07:09:04 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 07:28:22 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Wrong number of arguments" << std::endl;
		return 1;
	}

	std::string		filename = argv[1];
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	if (filename.empty() || s1.empty() || s2.empty()) {
		std::cerr << "Empty string" << std::endl;
		return 1;
	}

	std::ifstream	ifs(filename.c_str());
	if (!ifs || !ifs.is_open()) {
		std::cerr << "Can't open file: " << filename << std::endl;
		return 1;
	}

	std::ofstream	ofs((filename + ".replace").c_str());
	if (!ofs || !ofs.is_open()) {
		std::cerr << "Can't open file: " << filename + ".replace" << std::endl;
		return 1;
	}

	std::string		content;
	std::getline(ifs, content, '\0');
	if (content.empty()) {
		std::cerr << "Empty file" << std::endl;
		return 0;
	}

	ifs.close();

	size_t			pos;
	while ((pos = content.find(s1)) != std::string::npos) {
		content.erase(pos, s1.length());
		content.insert(pos, s2);
	}

	ofs << content;
	ofs.close();

	return 0;
}
