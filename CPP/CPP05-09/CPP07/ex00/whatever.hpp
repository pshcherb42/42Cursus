#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>
#include <string>


template <typename T> 
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
};

template <typename T>const T& min(const T& y,const T& x) {
	return (y < x) ? y : x;
};

template <typename T>const T& max(const T& y,const T& x) {
	return (y > x) ? y : x;
};

#endif
