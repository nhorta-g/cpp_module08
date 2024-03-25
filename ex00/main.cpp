/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:02:29 by nuno              #+#    #+#             */
/*   Updated: 2024/03/25 00:48:41 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

	try {
		std::vector<int>::iterator result = easyfind(vec, 3);
		std::cout << "Value found at index: " << std::distance(vec.begin(), result) << std::endl;

	} catch (const std::exception &e) {
		std::cerr << "Exeception " << e.what() << std::endl;
	}

	return 0;
}