/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.cpp										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ysabik <ysabik@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/12 08:54:40 by ysabik			#+#	#+#			 */
/*   Updated: 2024/01/12 09:11:28 by ysabik		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "Point.hpp"

int	main() {

	Point	a(-7, -7);
	Point	b( 7, -7);
	Point	c( 0,  7);

	Fixed const	min_x = (Fixed) Fixed::min(a.getX(), Fixed::min(b.getX(), c.getX())) - 1;
	Fixed const	max_x = (Fixed) Fixed::max(a.getX(), Fixed::max(b.getX(), c.getX())) + 1;
	Fixed const	min_y = (Fixed) Fixed::min(a.getY(), Fixed::min(b.getY(), c.getY())) - 1;
	Fixed const	max_y = (Fixed) Fixed::max(a.getY(), Fixed::max(b.getY(), c.getY())) + 1;

	for (Fixed i = min_x; i < max_x; i = i + 0.3f) {
		for (Fixed j = min_y; j < max_y; j = j + 0.2f) {
			Point p(i.toFloat(), j.toFloat());
			std::cout << (bsp(a, b, c, p) ? "X" : ".");
		}
		std::cout << std::endl;
	}

	return 0;
}
