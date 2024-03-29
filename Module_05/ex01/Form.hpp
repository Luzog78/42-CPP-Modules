/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:01:20 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/29 06:30:13 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		const int			signRequirement;
		const int			execRequirement;
		bool				isSigned;

	public:
		Form(const std::string name, int signRequirement, int execRequirement);
		Form(const Form &src);
		~Form();
		Form	&operator=(const Form &rhs);

		const std::string	getName() const;
		int					getSignRequirement() const;
		int					getExecRequirement() const;
		bool				getIsSigned() const;
		void				beSigned(const Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, const Form &rhs);

#endif
