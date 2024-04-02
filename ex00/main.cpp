/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhorta-g <nhorta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:02:29 by nuno              #+#    #+#             */
/*   Updated: 2024/04/02 16:19:22 by nhorta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{

	int arr[] = {1, 2, 3, 4, 8};
	size_t size = sizeof(arr) / sizeof(arr[0]);
	//std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0])); //Calling vector constructor with 2 parameters
	//to create vector filled with elements of array. First parameter is the pointer to begin of the array, second is
	//end pointer of array.
	std::vector<int> vec;
	for (size_t i = 0; i < size; ++i) {
		vec.push_back(arr[i]);
	}
	int num;

	try {
		std::cout << "To test easyfind function I creatd an array of ints with 5 elements like this:\n" << std::endl;

		for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
		std::cout << "Type a number from 0 to 9 to check if its contained and what position is" << std::endl;
		std::cin >> num;
		std::vector<int>::iterator result = easyfind(vec, num);
		std::cout << "Value found at index: " << std::distance(vec.begin(), result) << std::endl;

	} catch (const std::exception &e) {
		std::cerr << "Exeception: " << e.what() << std::endl;
	}

	return 0;
}