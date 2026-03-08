#ifndef ARRAY_HPP 
#define ARRAY_HPP
#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <string>
#include <cstdlib> // for rand()

template <typename T> // type of elements decided at compile time
class Array {
	private :
		unsigned int _size; // number of elements
		T* _data; // pointer to dynamicaly allocated array of T
	public: 
		Array() : _size(0), _data(NULL) {} // this respects the rule: preventive allocation is forbiden

		Array(unsigned int n) : _size(n), _data(n ? new T[n]() : NULL) {} // without () the content would be garbage, with () is 0
		// DEEP COPY
		Array(const Array& other) : _size(other._size), _data(other._size ? new T[other._size] : NULL) {
			for (unsigned int i = 0; i < _size; ++i) { // we use new[] so the adress of the memory is different and the original is not affected
				_data[i] = other._data[i];
			}
		};

		~Array() { delete [] _data; }

		Array& operator=(const Array& other) {
			if (this != &other) {
				T* new_data = other._size ? new T[other._size] : NULL; // use new[], modifying the original or the copy doesnt the affect the other
				for (unsigned int i = 0; i < other._size; ++i) { // copy values
					new_data[i] = other._data[i];
				}
				delete [] _data; // delete old memory
				_data = new_data;
				_size = other._size; // replace
			}
			return *this;
		}

		T& operator[](unsigned int idx) { // access elements
			if (idx >= _size)
				throw std::out_of_range("Array index out of range"); // exception
			return _data[idx];
		}

		const T& operator[](unsigned int idx) const { // const operator needed for const Array<int> a, a[0]
			if (idx >= _size)
				throw std::out_of_range("Array index out of range");
			return _data[idx];
		}

		unsigned int size() const { // number of arguments in the array
			return _size;
		};
		
};

#endif