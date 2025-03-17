/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 22:27:49 by eahn              #+#    #+#             */
/*   Updated: 2025/03/14 15:10:44 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept> // std::exception
#include <string> // std::to_string

template <typename T>
class Array
{
	private:
		T* _data; // pointer for dynamic array
		unsigned int _size; // size of array

	public:
		// default constructor: empty array | C++11: nullptr
		Array() : _data(nullptr), _size(0) {} 

		// constructor: array of size n
		// initialize list {} used (C++11)
		Array(unsigned int n) : _data(new T[n]{}), _size(n)
		{
			// std::cout << "Array of size " << _size << " created." << std::endl;
		}

		// copy constructor (deep copy)
		Array(const Array &other) : _data(new T[other._size]{}), _size(other._size)
		{
			std::copy(other._data, other._data + _size, _data); 
			// std::cout << "Array copied (copy constructor)." << std::endl;
		}

		// move constructor (c++17) - prevent unnecessary copy
		Array(Array&& other) noexcept: _size(other._size), _data(other._data)
		{
			other._size = 0;
			other._data = nullptr;
			// std::cout << "Array moved (move constructor)." << std::endl;
		}

		// assignment operator overload (deep copy)
		Array& operator=(const Array& other)
		{
			if (this != &other) // prevent self-assignment
			{
				delete[] _data; // delete existing data
				_size = other._size;
				_data = new T[_size];
				std::copy(other._data, other._data + _size, _data);
			}
			// std::cout << "Array copied (assignment operator)." << std::endl;
			return *this;
		}

		// move assignment operator overload (c++17) - prevent unnecessary copy
		// && means rvalue reference used for move semantics
		Array& operator=(Array&& other) noexcept
		{
			if (this != &other)
			{
				delete[] _data;
				_size = other._size;
				_data = other._data; // pointer moved (without deep copy)
				other._size = 0;
				other._data = nullptr;
			}
			// std::cout << "Array moved (move assignment operator)." << std::endl;
			return *this;
		}

		// destructor: free memory
		~Array()
		{
			delete[] _data;
		}

		// [] operator overload (include exception handling)
		T& operator[] (int index)
		{
    		if (index < 0 || index >= static_cast<int>(_size)) 
			{
       			throw std::out_of_range("Array index out of range: " + std::to_string(index));
    		}
    		return _data[index];
		}

		// size() function (return size of array)
		unsigned int size() const noexcept{
			return _size;
		}
};


#endif


// from C++17, move constructor, move assignment operator can be used
// -> prevent unnecessary copy, using pointer to improve performance

//The {} ensures default initialization: (only for C++11)
// If T is a primitive type (int, double, etc.), elements are zero-initialized.
// If T is a class, its default constructor is called for each element