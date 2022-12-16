#include <iostream>

#include "Ratio.hpp"


int main() {

    //exemple test unitaire : static_assert ( factoriel(4) == 24, " factoriel error ");
    
    Ratio r(1,0);
    Ratio r2(0,4);
    std::cout << Ratio::exp(r2) << std::endl;    
    return 0;
}
