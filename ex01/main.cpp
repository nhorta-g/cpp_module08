/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhorta-g <nhorta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:02:29 by nuno              #+#    #+#             */
/*   Updated: 2024/04/02 19:34:06 by nhorta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl << std::endl;

	int arr[] = {-1, 3, -5, 7, -9, 7, -5, 3, -1, 0};
	std::vector<int> vect(arr, arr + sizeof(arr) / sizeof(int));
	Span cont = Span(110);
	std::cout << "Apending this following vector to a vector container 10 times\n" << std::endl;

	std::cout << "{-1, 3, -5, 7, -9, 7, -5, 3, -1, 0}" << std::endl;
	for (int i = 0; i < 10; i++)
		cont.appendVector(vect);
	std::cout << "Resulting vector container\n" << std::endl;
	std::cout << cont << std::endl << std::endl;

	std::cout << "Created a vector with 9 million elements from 0 to 8999999 " << std::endl;
	std::cout << "Vector big vector longest span is... ";
	Span many = Span(90000000);
	many.addManyNumbers(90000000);
	std::cout << many.longestSpan() << std::endl;
}