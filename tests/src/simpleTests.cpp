#include <iostream>
#include <cmath> //for verification/comparison
#include <numeric>

#include "RatioConstructors.hpp"
#include "RatioFunctions.hpp"
#include "RatioOperators.hpp"

//#include "Ratio.hpp"


int main() {

    //testing file to use if you want to make rational operations
    
    Ratio<long> r((long)3,(long)2);
    Ratio<long> r2((float)-5);
    Ratio<long> r3((float)-4);
    Ratio<long> r4((float)5);
    //float f = 1.791;
    //std::cout << r*f << std::endl;
    
    std::cout << r4%r3 << " " << r2%r3 << " " << r4%r3 << " " << -5%-4 << std::endl;
    std::cout << (r+r4).convertRatioToFloat<float>() << std::endl;
    std::cout << r2.convertRatioToFloat<float>() << std::endl;

    return 0;
}
