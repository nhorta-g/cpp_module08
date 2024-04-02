/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhorta-g <nhorta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 23:45:36 by nhorta-g          #+#    #+#             */
/*   Updated: 2024/04/02 14:16:48 by nhorta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template<typename T>
class MutantStack : public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator			iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator	reverse_iterator;

	MutantStack() : std::stack<T>() {}
	~MutantStack() {}
	MutantStack( const MutantStack& src ) : std::stack<T>( src ){};
	MutantStack& operator=( const MutantStack& src ) {
	if ( this == src ) {
		return ( *this );
	}
	std::stack<T>::operator=( src );
	};

	iterator begin() {
		return std::stack<T>::c.begin();
	}
	iterator end() {
		return std::stack<T>::c.end();
	}
	reverse_iterator rbegin() {
		return std::stack<T>::c.rbegin();
	}
	reverse_iterator rend() {
		return std::stack<T>::c.rend();
	}
};

#endif