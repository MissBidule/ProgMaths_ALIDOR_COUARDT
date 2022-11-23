#include <iostream>

#include "Ratio.hpp"


int main() {

    //exemple test unitaire : static_assert ( factoriel(4) == 24, " factoriel error ");
    
    Ratio r(1,0);
    Ratio r2(3,3);
    std::cout << r << std::endl;    
    return 0;
}
