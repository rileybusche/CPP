#include <iostream>
using namespace std;

int main() {


    /* 
    integers

    float 4 bytes
    double 8 bytes
    int 4 bytes
    char 1 byte
    short 2 bytes
    long 8 bytes 
    */

    int i = 3;      //takes up 4 addresses in memory
    int *ptoi = &i;  //ptoi is a pointer to an integer

    i == *ptoi;
    /*
    we know: 
    name (i)
    type (int)
    value (3)
    size
    address - &i - addresses/pointers are typically 64bits = 8 bytes
    */

    std::cout << &i;
}