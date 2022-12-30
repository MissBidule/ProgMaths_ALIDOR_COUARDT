#include <iostream>
#include <cmath> //for verification/comparison
#include <numeric>

#include "Ratio.hpp"


int main() {

    //exemple test unitaire : static_assert ( factoriel(4) == 24, " factoriel error ");
    
    Ratio r((long)3,(long)2);
    Ratio r2((float)-2.777867317199707);
    Ratio r3((float)-2.33117);
    Ratio r4((float)-0.446697);
    //float f = 1.791;
    //std::cout << r*f << std::endl;
    std::cout << r3 << std::endl << r4 << std::endl << r3+r4 << std::endl;
    std::cout << (r3+r4).convertRatioToFloat() << std::endl;
    std::cout << r2.convertRatioToFloat() << std::endl;

    return 0;
}
