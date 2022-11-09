#include <iostream>

#include "Ratio.hpp"


int main() {

    //exemple test unitaire : static_assert ( factoriel(4) == 24, " factoriel error ");
    
    Ratio r(1,2);
    Ratio r2(2,3);
    Ratio r3;

    r3 = r - r2;
    std::cout << r3 << std::endl;
    r3 = r*r2;
    std::cout << r3 << std::endl;
    return 0;
}
