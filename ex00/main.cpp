/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:02:29 by nuno              #+#    #+#             */
/*   Updated: 2024/03/25 16:15:17 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{

	int arr[] = {1, 2, 3, 4, 8};
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
	int num;

	try {
		std::cout << "To test easyfind function we have an array of ints with 5 elements." << std::endl;
		std::cout << "Type a number from 0 to 9 to check if its contained and what position" << std::endl;
		std::cin >> num;
		std::vector<int>::iterator result = easyfind(vec, num);
		std::cout << "Value found at index: " << std::distance(vec.begin(), result) << std::endl;

	} catch (const std::exception &e) {
		std::cerr << "Exeception " << e.what() << std::endl;
	}

	return 0;
}