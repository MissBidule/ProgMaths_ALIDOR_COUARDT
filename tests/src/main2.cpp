#include <iostream>
#include <gtest/gtest.h>
#include "Ratio.hpp"


int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    
    Ratio r1(1,3);
    Ratio r2(r1);
    
    std::cout << r2 << std::endl;
    std::cout << r2*4 << std::endl;
    std::cout << r2.convertRatioToFloat() << std::endl;
    std::cout << Ratio::convertFloatToRatio(28) << std::endl;
    std::cout << Ratio(6,30).simplify() << std::endl;
    std::cout << r1+r2 << std::endl;
//    v1[0] = 1.0;
//    v1[1] = 0.3; 
//    v1[2] = 5.2;
//
//    VectorD v2(3);
//    v2[0] = -1.0;
//    v2[1] =  3.0; 
//    v2[2] = 42.0;
//
//    std::cout << "v1 + v2  : " << v1 + v2 << std::endl;
//    std::cout << "v1 - v2  : " << v1 - v2 << std::endl;
//    std::cout << "v1.v2    : " << v1.dot(v2) << std::endl;

    return RUN_ALL_TESTS();
}
