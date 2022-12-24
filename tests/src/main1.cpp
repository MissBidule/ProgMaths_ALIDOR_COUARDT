#include <iostream>

#include "Ratio.hpp"


int main() {

    //exemple test unitaire : static_assert ( factoriel(4) == 24, " factoriel error ");
    
    Ratio r(2,1);
    Ratio r2(3,1);
    //float f = 7.3891;
    std::cout << r%r2 << std::endl;
    return 0;
}