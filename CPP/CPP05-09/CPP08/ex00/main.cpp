#include "easyfind.hpp"

int main() {
    int arr[] = {1, 7, 3, 5, 9, 2};
    std::vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

    try {
        std::vector<int>::iterator it = easyfind(v, 9);
        std::cout << "Found: " << *it << " at index " << std::distance(v.begin(), it) << std::endl;
    } catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(v, 8);
        std::cout << "Found: " << *it << " at index " << std::distance(v.begin(), it) << std::endl;
    } catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}