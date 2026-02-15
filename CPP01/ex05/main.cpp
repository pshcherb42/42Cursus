#include "Harl.hpp"

int main(int argc, char **argv) {
    Harl harl;

    if (argc == 1){
        std::cout << "write DEBUG, INFO, WARNING or ERROR\n";
    }
    else if (argc == 2) {
        harl.complain(argv[1]);
    }
    else if (argc > 2) {
        std::cout << "program only accepts one argument\n";
    }
    return ( 0 );
}