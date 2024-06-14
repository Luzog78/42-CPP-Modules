/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:30:00 by ysabik            #+#    #+#             */
/*   Updated: 2024/05/29 22:57:18 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include "ATarget.hpp"

class TargetGenerator {
	private:
		std::vector<ATarget*>	targets;

		TargetGenerator(const TargetGenerator &src);
		TargetGenerator	&operator=(const TargetGenerator &rhs);

	public:
		TargetGenerator();
		~TargetGenerator();

		void		learnTargetType(ATarget *target);
		void		forgetTargetType(std::string targetsType);
		ATarget*	createTarget(const std::string &targetsType) const;
};

#endif
