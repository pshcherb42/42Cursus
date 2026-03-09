#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span() : N(0),  v() {}
Span::Span(unsigned int num) : N(num) , v() {
	v.reserve(num);
}
Span::Span(const Span& other) : N(other.N), v(other.v) {}
Span& Span::operator=(const Span& other) {
	if (this != &other) {
		N = other.N;
		v = other.v;
	}
	return *this;
}
Span::~Span() {}

void Span::addNumber(int num) {
	if (v.size() >= N)
		throw std::out_of_range("Array is full");
	v.push_back(num);
}

int Span::shortestSpan() {
    if (v.size() < 2) throw std::out_of_range("Not enough numbers to find a span");
        
	std::vector<int> tmp = v;
	std::sort(tmp.begin(), tmp.end());
	// int span = v.at(0) - v.at(1);
	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 0; i + 1 < tmp.size(); ++i) {
		int diff = tmp[i + 1] - tmp[i];
		if (diff < minSpan) {
			minSpan = diff;
		}
	}
	return minSpan;
}
int Span::longestSpan() {
	if (v.size() < 2)
        throw std::out_of_range("Not enough numbers to find a span");
	/*sort(v.begin(), v.end());
	int span = v.at(0) - v.at(v.size());*/
	int minVal = *std::min_element(v.begin(), v.end());
	int maxVal = *std::max_element(v.begin(), v.end());
	return maxVal - minVal;
}