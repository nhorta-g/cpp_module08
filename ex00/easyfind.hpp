/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhorta-g <nhorta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:02:20 by nuno              #+#    #+#             */
/*   Updated: 2024/04/02 16:32:16 by nhorta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>
# include <iostream>
# include <vector>

class NotFoundException: public std::exception {
	public:
		const char* what() const throw() {
			return ("Needle not found.");
		}
};

//std::find searches a certain value within a range defined by 2 iteratos. And returns an iterator to that value
template <typename T>
typename T::iterator easyfind(T &container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it != container.end())
		return it;
	throw NotFoundException();
}

#endif