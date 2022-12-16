#include <iostream>

#include "Ratio.hpp"


int main() {

    //exemple test unitaire : static_assert ( factoriel(4) == 24, " factoriel error ");
    
    Ratio r(8,6);
    Ratio r2(4,3);
    if (r == r2)
        std::cout << "yes" << std::endl;
    else 
        std::cout << "no" << std::endl;
    return 0;
}