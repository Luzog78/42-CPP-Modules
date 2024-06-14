/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:30:00 by ysabik            #+#    #+#             */
/*   Updated: 2024/05/29 22:52:07 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
# define ATARGET_HPP

# include "ASpell.hpp"

class ASpell;

class ATarget {
	protected:
		std::string	type;

	public:
		ATarget();
		ATarget(std::string type);
		ATarget(const ATarget &src);
		ATarget	&operator=(const ATarget &rhs);
		virtual ~ATarget();

		virtual ATarget		*clone() const = 0;
		void				getHitBySpell(const ASpell &spell) const;

		const std::string	&getType() const;
};

#endif
