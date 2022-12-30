#include <iostream>
#include "Ratio.hpp"


int main() {
    
    Ratio r1((long)1,(long)3);
    Ratio r2(r1);
    
    std::cout << r2 << std::endl;
    std::cout << r2*4 << std::endl;
    std::cout << r2.convertRatioToFloat() << std::endl;
    std::cout << Ratio::convertFloatToRatio(28) << std::endl;
    std::cout << Ratio((long)6,(long)30).simplify() << std::endl;
    std::cout << r1+r2 << std::endl;

    return 0;
}
