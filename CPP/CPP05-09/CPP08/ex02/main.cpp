#include "MutantStack.hpp"
#include <list>

int main()
{
	// Test 1: Basic functionality
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // Test 2: Iteration
    std::cout << "Elements in stack:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // Test 3: Copy constructor
    MutantStack<int> copyStack(mstack);
    std::cout << "Copy stack elements:" << std::endl;
    for (MutantStack<int>::iterator it = copyStack.begin(); it != copyStack.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // Test 4: Assignment operator
    MutantStack<int> assignedStack;
    assignedStack = mstack;
    std::cout << "Assigned stack elements:" << std::endl;
    for (MutantStack<int>::iterator it = assignedStack.begin(); it != assignedStack.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // Test 5: Empty stack behavior
    MutantStack<int> emptyStack;
    try {
        if (emptyStack.empty()) {
        	throw std::runtime_error("Stack is empty");
		}
		std::cout << "Top of empty stack: " << emptyStack.top() << std::endl;    
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 6: Const iterators (requires const_iterator support in MutantStack)
    const MutantStack<int> constStack(mstack);
    std::cout << "Const stack elements:" << std::endl;
    for (MutantStack<int>::const_iterator it = constStack.begin(); it != constStack.end(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}