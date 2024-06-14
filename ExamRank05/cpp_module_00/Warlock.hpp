/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:30:00 by ysabik            #+#    #+#             */
/*   Updated: 2024/05/29 21:05:58 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>

class Warlock {
	private:
		std::string	name;
		std::string	title;

		Warlock();
		Warlock(const Warlock &src);
		Warlock	&operator=(const Warlock &rhs);
	
	public:
		Warlock(std::string name, std::string title);
		~Warlock();

		void				introduce() const;

		const std::string	&getName() const;
		const std::string	&getTitle() const;
		void				setTitle(const std::string &title);
};

#endif
