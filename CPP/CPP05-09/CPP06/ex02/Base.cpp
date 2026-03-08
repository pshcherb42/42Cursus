#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(int num) {
	//randomly create A, B or C
	switch(num) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}
}

void identify(Base* p) {
	if (!p) {
        std::cout << "Pointer is NULL" << std::endl;
        return;
    }

	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;

	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
		
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;

	else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch(...) {
		// silently continue to next type
	}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch(...) {
		// silently continue to next type
	}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch(...) {
		// silently continue to next type
	}

	std::cout << "Unknown type" << std::endl;
}

Base::~Base() {}
