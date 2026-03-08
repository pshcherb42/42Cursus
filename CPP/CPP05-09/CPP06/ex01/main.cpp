#include "Serializer.hpp"

int main() {
    struct Data d = {0, 1};
    uintptr_t ui = Serializer::serialize(&d);
    std::cout << "Data *ptr address : " << &d << std::endl;
    std::cout << "Deserialize return : " <<  Serializer::deserialize(ui) << std::endl;
    std::cout << d.x << ',' << d.y << std::endl;
    std::cout << std::endl;

    std::cout << "nullptr case" << std::endl;
    Data *ptr = NULL;
    uintptr_t raw = Serializer::serialize(ptr);
    std::cout << "Data *ptr address : " << ptr << std::endl;
    Data *res = Serializer::deserialize(raw);
    std::cout << "Deserialize return : " <<  res << std::endl;
    std::cout << std::endl;

    std::cout << "Multiple objects" << std::endl;
    Data a, b;
    uintptr_t ra = Serializer::serialize(&a);
    std::cout << "Data *ptr address a : " << &a << std::endl;
    std::cout << "Serialized ra       : " << ra << std::endl;
    uintptr_t rb = Serializer::serialize(&b);
    std::cout << "Data *ptr address b : " << &b << std::endl;
    std::cout << "Serialized rb       : " << rb << std::endl;
    Data *desA = Serializer::deserialize(ra);
    Data *desB = Serializer::deserialize(rb);
    std::cout << "Deserialized A : " << desA << std::endl;
    std::cout << "Deserialized B : " << desB << std::endl;
    std::cout << std::endl; 

    // pointer re ususally 8 bytes
    // uintptr_t is also 8 bytes and guaranteed to hold any pointer value
    // unsigned int 32 bits, deserialization may fail
    // type cualifiers like const don't matter. 
    // I can store const Data *, the adress is not affected by it
    // If I add 1 to the raw value before deserializing it will fail
    // and point to garbage data
    // if data is empty the program works as expected and pointer value is valid
    // padding(several elements inside Data) doesnt affect the pointer.
    // Because pointer is the address, not content

    std::cout << "Multiple casts" << std::endl;
    Data rt;
    uintptr_t raw2 = Serializer::serialize(&rt);
    std::cout << "Data *ptr address : " << &rt << std::endl;
    long l = (long)raw2;
    Data *res2 = Serializer::deserialize((uintptr_t)l);
    std::cout << "uintptr may be larger that 64bit long -> truncation -> undefined behavior" << std::endl;
    std::cout << "Deserialize return (after cast long) : " << res2 << std::endl;
    // why is this useful?
    // for low-level tasks like storing pointers in generic containers,
    // serialization for network/memory transport
    // or educational to understand how pinters work
}