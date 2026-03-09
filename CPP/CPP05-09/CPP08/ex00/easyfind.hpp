#ifndef EASYFIND_HPP 
#define EASYFIND_HPP
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <iterator>

template<typename T>
typename T::iterator easyfind(T& stack, int needle) {
    // find first occurrence of needle in stack
        // find out the size of stack
        // run through all the characters untill one is equal to param2
    // if no ocurrence found throw an exception 
    typename T::iterator it = find(stack.begin(), stack.end(), needle);
    if (it == stack.end())
        throw std::runtime_error("Not present");
    return it;
}


#endif