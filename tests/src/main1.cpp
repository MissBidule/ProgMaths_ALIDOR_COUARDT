#include <iostream>

#include "Ratio.hpp"


int main() {

    //exemple test unitaire : static_assert ( factoriel(4) == 24, " factoriel error ");
    
    Ratio r(1,2);
    Ratio r2(3,3);
    std::cout << Ratio::sqrt(r2) << std::endl;    
    return 0;
}
