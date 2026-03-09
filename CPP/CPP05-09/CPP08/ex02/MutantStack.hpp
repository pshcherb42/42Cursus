#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <iostream>
#include <iterator>
#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>{
	public:
		MutantStack() : std::stack<T, Container>() {}
		
		// Copy constructor
    	MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}

		// Assignment operator
		MutantStack& operator=(const MutantStack& other) {
			if (this != &other) {
				std::stack<T, Container>::operator=(other);
			}
			return *this;
    	}

		~MutantStack() {}

		typedef typename Container::iterator iterator;

		iterator begin() {
			return (this->c.begin());
		}

		iterator end() {
			return (this->c.end());
		}

		typedef typename Container::const_iterator const_iterator;

		const_iterator begin() const {
			return this->c.begin();
		}

		const_iterator end() const {
			return this->c.end();
		}		
};

#endif