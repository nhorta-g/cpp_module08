/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhorta-g <nhorta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:02:20 by nuno              #+#    #+#             */
/*   Updated: 2024/04/01 23:45:45 by nhorta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <iostream>
# include <vector>
# include <algorithm>

class Span {
	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;
	public:
		Span();
		Span(unsigned int N);
		Span (const Span &obj);
		Span &operator = (const Span &obj);
		~Span();

		void addNumber(int number);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

	class OverFlowException: public std::exception {
		public:
			const char* what() const throw() {
				return ("Cant add a new element if there are already N elements stored.");
			}
	};

	class ZeroOrOneNumberException: public std::exception {
		public:
			const char* what() const throw() {
				return ("No numbers stored, or only one, no span can be found.");
			}
	};
};

#endif