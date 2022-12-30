#include <iostream>
#include <cmath> //for verification/comparison
#include <numeric>

#include "Ratio.hpp"


int main() {

    //exemple test unitaire : static_assert ( factoriel(4) == 24, " factoriel error ");
    
    Ratio r((long)3,(long)2);
    Ratio r2((float)-5);
    Ratio r3((float)-4);
    Ratio r4((float)5);
    //float f = 1.791;
    //std::cout << r*f << std::endl;
    std::cout << r4%r3 << " " << r2%r3 << " " << r4%r3 << " " << -5%-4 << std::endl;
    std::cout << (r3+r4).convertRatioToFloat() << std::endl;
    std::cout << r2.convertRatioToFloat() << std::endl;

    return 0;
}
