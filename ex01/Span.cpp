	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:10:38 by nuno              #+#    #+#             */
/*   Updated: 2024/03/26 15:11:54 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0){}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span (const Span &obj) : _maxSize(obj._maxSize), _numbers(obj._numbers) {}

Span& Span::operator = (const Span &obj) {
	if (this != &obj) {
		_maxSize = obj._maxSize;
		_numbers = obj._numbers;
	}
return (*this);
}

Span::~Span() {}

void Span::addNumber(int number) {
	if (_numbers.size() >= _maxSize)
		throw OverFlowException();
	_numbers.push_back(number);
}

unsigned int Span::shortestSpan() const{
	if (_numbers.size() < 2)
		throw ZeroOrOneNumberException();

	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	int shortestSpan = longestSpan();
	std::vector<int>::iterator it;
	for (it = sortedNumbers.begin(); it != sortedNumbers.end() - 1; ++it ) {
		if ( ( *( it + 1 ) - *it ) < shortestSpan )
				shortestSpan = *( it + 1 ) - *it;
		if ( shortestSpan == 0 )
			return shortestSpan;
	}
	return shortestSpan;
}

unsigned int Span::longestSpan() const{
	if (_numbers.size() < 2)
		throw ZeroOrOneNumberException();
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	return(max - min);
}