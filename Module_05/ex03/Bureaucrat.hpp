/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:49:07 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/29 06:30:41 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define RED "\033[33m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

# include <iostream>

# include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string	name;
		int					grade;
	
	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat();
		Bureaucrat	&operator=(const Bureaucrat &rhs);
		
		const std::string	getName() const;
		int					getGrade() const;
		void				setGrade(int grade);
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(AForm &form) const;
		void				executeForm(AForm &form);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &rhs);

#endif
