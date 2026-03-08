#ifndef BASE_HPP
#define BASE_HPP
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

class Base {	
	public :
		virtual ~Base(); 
};

Base * generate(int num);
void identify(Base* p);
void identify(Base& p);

#endif

// virtual public destructor ensures derived objects are properly cleaned up 
// if not it can cause memory leaks
