#include <iostream>

#include "Ratio.hpp"


int main() {

    //exemple test unitaire : static_assert ( factoriel(4) == 24, " factoriel error ");
    
    Ratio r(8,6);
    Ratio r2(300,10);
    if (r == r2)
        std::cout << "yes" << std::endl;
    else 
        std::cout << "no" << std::endl;
    std::cout << Ratio::convertFloatToRatio(0.866) << std::endl;
    std::cout << Ratio::cos(r2) << std::endl;
    return 0;
}