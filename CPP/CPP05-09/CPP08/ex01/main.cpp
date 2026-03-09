#include "Span.hpp"

int main()
{
    // Test 1: normal usage with addNumbers (vector) + addNumber
    try {
        Span sp(5);
        std::vector<int> data;
        data.push_back(6); data.push_back(3); data.push_back(17);
        sp.addNumbers(data.begin(), data.end()); // add 3
        sp.addNumber(9);
        sp.addNumber(11); // total 5
        std::cout << "sp shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "sp longest: " << sp.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Test1 exception: " << e.what() << std::endl;
    }

    // Test 2: addNumbers exceeds capacity -> expect exception
    try {
        Span sp2(3);
        std::vector<int> many;
        for (int i = 0; i < 5; ++i) many.push_back(i);
        sp2.addNumbers(many.begin(), many.end()); // should throw
    } catch (std::exception& e) {
        std::cout << "Test2 expected exception: " << e.what() << std::endl;
    }

    // Test 3: shortest/longest with <2 elements -> expect exceptions
    try {
        Span sp3(2);
        sp3.addNumber(42);
        std::cout << "sp3 shortest: " << sp3.shortestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Test3 expected (shortest): " << e.what() << std::endl;
    }
    try {
        Span sp3b(2);
        sp3b.addNumber(42);
        std::cout << "sp3b longest: " << sp3b.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Test3 expected (longest): " << e.what() << std::endl;
    }

    // Test 4: addNumbers with a different iterator type (list)
    try {
        Span sp4(4);
        std::list<int> lst;
        lst.push_back(10); lst.push_back(20);
        sp4.addNumbers(lst.begin(), lst.end());
        sp4.addNumber(15);
        sp4.addNumber(25);
        std::cout << "sp4 shortest: " << sp4.shortestSpan() << std::endl;
        std::cout << "sp4 longest: " << sp4.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Test4 exception: " << e.what() << std::endl;
    }

    return 0;
}