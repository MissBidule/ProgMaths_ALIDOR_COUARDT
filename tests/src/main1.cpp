#include <iostream>

#include "Ratio.hpp"


int main() {

    VectorD v(3);

    v[0] = 1.0;
    v[1] = 0.3; 
    v[2] = 5.2;

    std::cout << "v : " << v << std::endl;    

    return 0;
}
