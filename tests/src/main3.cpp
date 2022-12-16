#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <algorithm>
#include <gtest/gtest.h>
#include "Ratio.hpp"

//tester :
//toutes les fonctions
//les cas particuliers
//les exceptions
//les affichages

/////////////////////////////////////////////////////
// other operations

TEST (OtherOperations, sign) {
    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_real_distribution<float> uniformDistributionValue(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){

        // generate random data
        float data = uniformDistributionValue(generator);
        
        // build the corresponding rational
        int generatedSign = sign(data);

        ASSERT_GE(data*generatedSign, 0);
    }
}

/////////////////////////////////////////////////////
// constructors

TEST (RatioConstructor, defaultConstructor) {
    Ratio r1;
    ASSERT_EQ (r1.getNum(), 0);
    ASSERT_EQ (r1.getDenom(), 1);
    
    Ratio r2(1,3);
    ASSERT_EQ (r2.getNum(), 1);
    ASSERT_EQ (r2.getDenom(), 3);
}

TEST (RatioConstructor, floatConstructor) {
    std::mt19937 generator(0);
    //max value
    //Has a weird behaviour above 100
    const size_t maxValue = 1000;
    std::uniform_real_distribution<float> uniformDistributionValue(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){

        // generate random data
        float data = uniformDistributionValue(generator);
        
        // build the corresponding rational
        Ratio r(data);

        //due to the double precisions as absolute value increases, we adapt the acceptable error converted
        ASSERT_NEAR(data, r.getNum()/(float)r.getDenom(), 0.00000015*maxValue);
    }
}

TEST (RatioConstructor, copyConstructor) {
    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_int_distribution<int> uniformIntDistribution(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){

        // generate random data
        double data1 = uniformIntDistribution(generator);
        double data2 = uniformIntDistribution(generator);

        // build the corresponding rational
        Ratio r1(data1, data2), r2;

        r2 = r1;
        ASSERT_EQ (r2.getNum(), r1.getNum());
        ASSERT_EQ (r2.getDenom(), r1.getDenom());
        
    }
}

/////////////////////////////////////////////////////
// arithmetic

//TEST (RatioArithmetic, modulo) {
//
//    const size_t maxSize = 1000;  // max size of the tested vectors
//    std::mt19937 generator(0);
//    std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
//    std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
//    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
//
//    // run many times the same test with different values
//    for(int run=0; run<100; ++run){
//
//        // define a vector dimension
//        const size_t dim = uniformIntDistribution(generator);
//
//        // generate random data
//        std::vector<double> data1(dim), data2(dim);
//        std::generate(data1.begin(), data1.end(), gen);
//        std::generate(data2.begin(), data2.end(), gen);
//
//        // build the corresponding VectorD
//        VectorD vec1(dim), vec2(dim), vec3(dim);
//        for(size_t i=0; i<dim; ++i){
//            vec1[i] = data1[i];
//            vec2[i] = data2[i];
//        }
//
//        vec3 = vec1 + vec2;
//        ASSERT_EQ (vec3.size(), dim);
//
//        for(size_t i=0; i<dim; ++i){
//            ASSERT_DOUBLE_EQ (vec3[i], data1[i] + data2[i]);    // EXPECT_DOUBLE_EQ would be fine too
//        }
//
//    }
//}
//

///////////////////////////////////////////////////////
//// exception
//
//TEST (VectorDException, loadExceptionMessage) {
//    const std::string filename = "filename.txt";
//    const std::string expectedException = "VectorD::load: error: can not open file: " + filename;
//
//    // check the exception message
//    try{
//        VectorD vec;
//        vec.load(filename);
//    }
//    catch( const std::exception &e){
//        EXPECT_TRUE( std::string(e.what()).find(expectedException) == 0);
//    }
//}
//
//
//TEST (VectorDException, loadExceptionType) {
//
//    // check exception type
//    VectorD vec;
//    EXPECT_THROW(vec.load("filename.txt"), std::ios_base::failure);
//}
//
//TEST (VectorDException, plusExceptionMessage) {
//    const std::string expectedException = "VectorD::operator+: operand with incompatible size : ";
//
//    const size_t maxSize = 1000;  // max size of the tested vectors
//    std::mt19937 generator(0);
//    std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
//    std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
//    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};
//
//    // check the exception message
//    try{
//        // define a vector dimension
//        const size_t dim = uniformIntDistribution(generator);
//
//        // build the corresponding VectorD
//        VectorD vec1(dim), vec2(dim+1);
//
//        vec1 + vec2;
//    }
//    catch( const std::exception &e){
//        EXPECT_TRUE( std::string(e.what()).find(expectedException) == 0);
//    }
//}





int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
