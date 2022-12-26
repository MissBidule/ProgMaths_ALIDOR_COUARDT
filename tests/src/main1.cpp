#include <iostream>

#include "Ratio.hpp"


int main() {

    //exemple test unitaire : static_assert ( factoriel(4) == 24, " factoriel error ");
    
    Ratio r(54,3);
    Ratio r2(3,1);
    float f = 1.791;
    std::cout << r*f << std::endl;

    return 0;
}