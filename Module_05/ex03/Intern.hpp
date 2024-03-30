/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 06:29:08 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/30 05:19:51 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern &src);
		~Intern();
		Intern	&operator=(const Intern &rhs);

		AForm	*makeForm(const std::string formName, const std::string target);
};

#endif
