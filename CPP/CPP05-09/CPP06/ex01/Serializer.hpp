#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include "Data.hpp"
#include <stdint.h>
#include <iostream>
//uintptr is an unsigned integer type guaranteed to be able to hold a pointer
class Serializer {
	private:
		Serializer();
	public:
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

		~Serializer();
};

#endif