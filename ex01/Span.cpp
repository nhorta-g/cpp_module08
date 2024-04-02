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

Span::Span (const Span &obj) : _maxSize(obj._maxSize), _vector(obj._vector) {}

Span& Span::operator = (const Span &obj) {
	if (this != &obj) {
		_maxSize = obj._maxSize;
		_vector = obj._vector;
	}
return (*this);
}

Span::~Span() {}

void Span::addNumber(int number) {
	if (_vector.size() >= _maxSize)
		throw OverFlowException();
	_vector.push_back(number);
}

void Span::addManyNumbers(unsigned int ammount) {
	for (unsigned int i = 0; i < ammount; i++)
		addNumber(i);
}

void Span::appendVector( std::vector<int> array ) {
	if ( _vector.size() + array.size() > _maxSize )
		throw OverFlowException();
	_vector.insert( _vector.end(), array.begin(), array.end() );
}

unsigned int Span::shortestSpan() const{
	if (_vector.size() < 2)
		throw ZeroOrOneNumberException();

	std::vector<int> sortedNumbers = _vector;
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
	if (_vector.size() < 2)
		throw ZeroOrOneNumberException();
	int min = *std::min_element(_vector.begin(), _vector.end());
	int max = *std::max_element(_vector.begin(), _vector.end());
	return(max - min);
}

const std::vector<int> &Span::getVector() const {
	return _vector;
}

std::ostream &operator << (std::ostream &stream, const Span &obj) {
	stream << "{ ";
	for (unsigned int i = 0; i < obj.getVector().size(); i++) {
		stream << obj.getVector().at(i);
		i != obj.getVector().size() - 1 ? stream << ", " : stream << " ";
	}
	stream << "}";
	return stream;
}