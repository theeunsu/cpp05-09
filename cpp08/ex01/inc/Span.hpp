/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahn <eahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:37:30 by eahn              #+#    #+#             */
/*   Updated: 2025/03/27 21:59:50 by eahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator> 

class Span
{
    private:
        unsigned int _maxSize; // maximum number of elements
        std::vector<int> _numbers; // container to store the numbers

    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int n);
        int shortestSpan() const;
        int longestSpan() const;

        template<typename Iterator>
        void addNumber(Iterator begin, Iterator end)
        {
            if (_numbers.size() + std::distance(begin, end) > _maxSize)
                throw std::runtime_error("Not enough space to add range");
            _numbers.insert(_numbers.end(), begin, end);
        }
};


#endif
