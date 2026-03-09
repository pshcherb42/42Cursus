#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <stdexcept>
#include <iostream>
#include <iterator>
#include <list>

class Span {
	private:
		unsigned int N;
		std::vector<int> v;
	public:
		Span();
		Span(unsigned int num);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int num);
		int shortestSpan();
		int longestSpan();

		// add a range [first, last)
        template<typename InputIt>
        void addNumbers(InputIt first, InputIt last);
};

template<typename InputIt>
void Span::addNumbers(InputIt first, InputIt last) {
    typename std::iterator_traits<InputIt>::difference_type dist = std::distance(first, last);
    if (dist < 0 || static_cast<size_t>(dist) + v.size() > N)
        throw std::out_of_range("Not enough space to add range");
    for (; first != last; ++first)
        v.push_back(*first);
}

#endif