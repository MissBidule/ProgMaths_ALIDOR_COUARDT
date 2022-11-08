#include <iostream>

#include "Ratio.hpp"


int main() {

    VectorD v1(3);
    v1[0] = 1.0;
    v1[1] = 0.3; 
    v1[2] = 5.2;

    VectorD v2(3);
    v2[0] = -1.0;
    v2[1] =  3.0; 
    v2[2] = 42.0;

    std::cout << "v1 + v2  : " << v1 + v2 << std::endl;
    std::cout << "v1 - v2  : " << v1 - v2 << std::endl;
    std::cout << "v1.v2    : " << v1.dot(v2) << std::endl;

    return 0;
}
