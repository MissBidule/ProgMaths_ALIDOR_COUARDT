#include <iostream>

#include "Ratio.hpp"


int main() {

    //exemple test unitaire : static_assert ( factoriel(4) == 24, " factoriel error ");
    
    Ratio r(1,3);
    Ratio r2(4,3);
    if (r <= r2)
        std::cout << "yes";
    return 0;
}