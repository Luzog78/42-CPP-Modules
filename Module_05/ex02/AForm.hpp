/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:01:20 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/29 07:09:06 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		const int			signRequirement;
		const int			execRequirement;
		bool				isSigned;

	public:
		AForm(const std::string name, int signRequirement, int execRequirement);
		AForm(const AForm &src);
		virtual ~AForm();
		AForm	&operator=(const AForm &rhs);

		const std::string	getName() const;
		int					getSignRequirement() const;
		int					getExecRequirement() const;
		bool				getIsSigned() const;
		void				beSigned(const Bureaucrat &bureaucrat);
		virtual void		execute(const Bureaucrat &executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		class FormAlreadySignedException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, const AForm &rhs);

#endif
