#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
    std::cout << "Base case" << std::endl;
    srand(time(0));
	int randomNum = rand() % 3;
    Base* obj = generate(randomNum);
    // public inheritance ensures Base* can point to derived objects

    identify(obj); // casting pointer uses uses null check for dynamic cast
    identify(*obj); // ref identification handles dynamic_cast failurs using exceptions

    delete obj;
    std::cout << std::endl;

    std::cout << "Multiple objects" << std::endl;
    for (int i = 0; i < 10; i++){
        //srand(time(0));
	    int randomNum = rand() % 3;
        Base *obj = generate(randomNum);
        identify(obj);
        identify(*obj);
        delete obj;
    }
    std::cout << std::endl;

    std::cout << "nullptr safety" << std::endl;
    Base *nullPtr = NULL;
    identify(nullPtr);
    std::cout << "reference version cannot be tested, would crash" << std::endl;
    std::cout << std::endl;

    std::cout << "Array of objects" << std::endl;
    Base *arr[5];
    for(int i = 0; i < 5; ++i) {
        //srand(time(0));
	    int randomNum = rand() % 3;
        arr[i] = generate(randomNum);
    }  
    for(int i = 0; i < 5; i++){
        identify(arr[i]);
        identify(*arr[i]);
        delete arr[i];
    }
    std::cout << std::endl;

    std::cout << "Explicit casting tests" << std::endl;
    
    Base *basePtr = generate(randomNum);
    if(A *a = dynamic_cast<A*>(basePtr)){
        (void)a;
        std::cout << "Explicit cast detected type : A" << std::endl;
    }
    else if(B *b = dynamic_cast<B*>(basePtr)) {
        (void)b;
        std::cout << "Explicit cast detected type : B" << std::endl;
    }  
    else if(C *c = dynamic_cast<C*>(basePtr)) {
        (void)c;
        std::cout << "Explicit cast detected type : C" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Explicit casting tests : using references" << std::endl;
    try{
        (void)dynamic_cast<A&>(*basePtr);
        std::cout << "Explicit cast detected type (ref): A" << std::endl;
    }catch (...){}

    try{
        (void)dynamic_cast<B&>(*basePtr);
        std::cout << "Explicit cast detected type (ref): B" << std::endl;
    }catch (...){}
    
    try{
        (void)dynamic_cast<C&>(*basePtr);
        std::cout << "Explicit cast detected type (ref): C" << std::endl;
    }catch (...){}

    //confirms that identify logic works correctly for all possible casts
    //I verified the type manually with dynamic_cast as well as with my identify functions
} 