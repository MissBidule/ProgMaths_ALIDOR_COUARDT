#include <iostream>
#include <cmath> //for verification/comparison
#include <numeric>

#include "Ratio.hpp"


int main() {

    //exemple test unitaire : static_assert ( factoriel(4) == 24, " factoriel error ");
    
    Ratio r(1,2);
    Ratio r2(36,10);
    //float f = 1.791;
    //std::cout << r*f << std::endl;
    std::cout << Ratio::pow(r,-4) << std::endl;
    std::cout << std::pow((1/2.0),-4) << std::endl;

    return 0;
}