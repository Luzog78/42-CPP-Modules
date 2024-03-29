/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 05:21:18 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/29 06:17:00 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
	AForm("ShrubberyCreationForm", 145, 137), target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
	AForm(other), target(other.target) {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getExecRequirement())
		throw AForm::GradeTooLowException();

	std::ofstream	file((target + "_shrubbery").c_str(), std::ios::out | std::ios::trunc);

	if (!file.is_open()) {
		std::cerr << "Error: can't open file" << std::endl;
		return;
	}

	file << "                                                            " << std::endl;
	file << "                                                  .         " << std::endl;
	file << "                                       .         ;          " << std::endl;
	file << "          .              .              ;%     ;;           " << std::endl;
	file << "            ,           ,                :;%  %;            " << std::endl;
	file << "             :         ;                   :;%;'     .,     " << std::endl;
	file << "    ,.        %;     %;            ;        %;'    ,;       " << std::endl;
	file << "      ;       ;%;  %%;        ,     %;    ;%;    ,%'        " << std::endl;
	file << "       %;       %;%;      ,  ;       %;  ;%;   ,%;'         " << std::endl;
	file << "        ;%;      %;        ;%;        % ;%;  ,%;'           " << std::endl;
	file << "         `%;.     ;%;     %;'         `;%%;.%;'             " << std::endl;
	file << "          `:;%.    ;%%. %@;        %; ;@%;%'                " << std::endl;
	file << "             `:%;.  :;bd%;          %;@%;'                  " << std::endl;
	file << "               `@%:.  :;%.         ;@@%;'                   " << std::endl;
	file << "                 `@%.  `;@%.      ;@@%;                     " << std::endl;
	file << "                   `@%%. `@%%    ;@@%;                      " << std::endl;
	file << "                     ;@%. :@%%  %@@%;                       " << std::endl;
	file << "                       %@bd%%%bd%%:;                        " << std::endl;
	file << "                         #@%%%%%:;;                         " << std::endl;
	file << "                         %@@%%%::;                          " << std::endl;
	file << "                         %@@@%(o);  . '                     " << std::endl;
	file << "                         %@@@o%;:(.,'                       " << std::endl;
	file << "                     `.. %@@@o%::;                          " << std::endl;
	file << "                        `)@@@o%::;                          " << std::endl;
	file << "                         %@@(o)::;                          " << std::endl;
	file << "                        .%@@@@%::;                          " << std::endl;
	file << "                        ;%@@@@%::;.                         " << std::endl;
	file << "                       ;%@@@@%%:;;;.                        " << std::endl;
	file << "                   ...;%@@@@@%%:;;;;,..    Gilo97           " << std::endl;
	file << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	file.close();
}
