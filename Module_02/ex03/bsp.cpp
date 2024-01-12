/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:42:14 by ysabik            #+#    #+#             */
/*   Updated: 2024/01/12 10:46:07 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * ==> [ Binary Space Partitioning of a triangle ] <==
 * 
 * Thanks to : https://www.youtube.com/watch?v=HYAgJN3x4GA
 * 
 * Summary :
 * 
 * 	w1 = ( a.x * (c.y - a.y) + (p.y - a.y) * (c.x - a.x) - p.x * (c.y - a.y) )
 * 			/ ( (b.y - a.y) * (c.x - a.x) - (b.x - a.x) * (c.y - a.y) )
 * 	w2 = ( p.y - a.y - w1 * (b.y - a.y) ) / (c.y - a.y)
 * 
 * 	P is inside the triangle if ALL of the following are true :
 * 		-> w1 >= 0
 * 		-> w2 >= 0
 * 		-> w1 + w2 <= 1
*/
bool	bsp(Point const a, Point const b, Point const c, Point const p) {
	Fixed	w1 = (
		(a.getX() * (c.getY() - a.getY()))
		+ (p.getY() - a.getY()) * (c.getX() - a.getX())
		- p.getX() * (c.getY() - a.getY())
	) / (
		(b.getY() - a.getY()) * (c.getX() - a.getX())
		- (b.getX() - a.getX()) * (c.getY() - a.getY())
	);

	Fixed	w2 = (p.getY() - a.getY() - w1 * (b.getY() - a.getY()))
					/ (c.getY() - a.getY());

	return w1 >= 0 && w2 >= 0 && w1 + w2 <= 1;
}
