#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <algorithm>
#include <gtest/gtest.h>
#include "Ratio.hpp"

//tester :
//toutes les fonctions //manque celles pas déjà faites
//les cas particuliers
//les exceptions

//tout passer en template

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
        int data1 = uniformIntDistribution(generator);
        int data2 = uniformIntDistribution(generator);

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

TEST (RatioArithmetic, addition) {

    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_real_distribution<float> uniformDistribution(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){

        // generate random data
        float data1 = uniformDistribution(generator);
        float data2 = uniformDistribution(generator);

        // build the corresponding rational
        Ratio r1(data1), r2(data2), r3;

        r3 = r1 + r2;
        
        ASSERT_NEAR(data1+data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
        
    }
}

TEST (RatioArithmetic, substraction) {

    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_real_distribution<float> uniformDistribution(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){

        // generate random data
        float data1 = uniformDistribution(generator);
        float data2 = uniformDistribution(generator);

        // build the corresponding rational
        Ratio r1(data1), r2(data2), r3;

        r3 = r1 - r2;
        
        ASSERT_NEAR(data1-data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
        
    }
}

TEST (RatioArithmetic, unaryMinus) {

    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_int_distribution<int> uniformIntDistribution(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){

        // generate random data
        int data1 = uniformIntDistribution(generator);
        int data2 = uniformIntDistribution(generator);

        // build the corresponding rational
        Ratio r1(data1, data2), r2;
        
        r2 = -r1;
        
        ASSERT_EQ (r2.getNum(), -r1.getNum());
        ASSERT_EQ (r2.getDenom(), r1.getDenom());
        
    }
}

TEST (RatioArithmetic, multiply) {

    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_real_distribution<float> uniformDistribution(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){
        
        // generate random data
        float data1 = uniformDistribution(generator);
        float data2 = uniformDistribution(generator);
        
        // build the corresponding rational
        Ratio r1(data1), r2(data2), r3;
        
        r3 = r1*r2;
        //precision expected for a 10x10 operation
        ASSERT_NEAR(data1*data2, r3.getNum()/(float)r3.getDenom(), 0.00015);
        r3 = r1*data2;
        ASSERT_NEAR(data1*data2, r3.getNum()/(float)r3.getDenom(), 0.00015);
    }
        
}

TEST (RatioArithmetic, division) {

    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_real_distribution<float> uniformDistribution(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){
        
        // generate random data
        float data1 = uniformDistribution(generator);
        float data2 = uniformDistribution(generator);
        
        // build the corresponding rational
        Ratio r1(data1), r2(data2), r3;
        
        r3 = r1/r2;
        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
        r3 = r1/data2;
        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
    }
        
}

//TEST (RatioComparison, greaterThan) {
//
//    std::mt19937 generator(0);
//    //max value
//    const size_t maxValue = 10;
//    std::uniform_real_distribution<float> uniformDistribution(-(int)maxValue,(int)maxValue);
//
//    // run many times the same test with different values
//    for(int run=0; run<100; ++run){
//
//        // generate random data
//        float data1 = uniformDistribution(generator);
//        float data2 = uniformDistribution(generator);
//
//        // build the corresponding rational
//        Ratio r1(data1), r2(data2), r3;
//
//        r3 = r1/r2;
//        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
//        r3 = r1/data2;
//        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
//    }
//
//}

//TEST (RatioComparison, LessThan) {
//
//    std::mt19937 generator(0);
//    //max value
//    const size_t maxValue = 10;
//    std::uniform_real_distribution<float> uniformDistribution(-(int)maxValue,(int)maxValue);
//
//    // run many times the same test with different values
//    for(int run=0; run<100; ++run){
//
//        // generate random data
//        float data1 = uniformDistribution(generator);
//        float data2 = uniformDistribution(generator);
//
//        // build the corresponding rational
//        Ratio r1(data1), r2(data2), r3;
//
//        r3 = r1/r2;
//        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
//        r3 = r1/data2;
//        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
//    }
//
//}

//TEST (RatioComparison, greaterEqual) {
//
//    std::mt19937 generator(0);
//    //max value
//    const size_t maxValue = 10;
//    std::uniform_real_distribution<float> uniformDistribution(-(int)maxValue,(int)maxValue);
//
//    // run many times the same test with different values
//    for(int run=0; run<100; ++run){
//
//        // generate random data
//        float data1 = uniformDistribution(generator);
//        float data2 = uniformDistribution(generator);
//
//        // build the corresponding rational
//        Ratio r1(data1), r2(data2), r3;
//
//        r3 = r1/r2;
//        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
//        r3 = r1/data2;
//        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
//    }
//
//}

//TEST (RatioComparison, lessEqual) {
//
//    std::mt19937 generator(0);
//    //max value
//    const size_t maxValue = 10;
//    std::uniform_real_distribution<float> uniformDistribution(-(int)maxValue,(int)maxValue);
//
//    // run many times the same test with different values
//    for(int run=0; run<100; ++run){
//
//        // generate random data
//        float data1 = uniformDistribution(generator);
//        float data2 = uniformDistribution(generator);
//
//        // build the corresponding rational
//        Ratio r1(data1), r2(data2), r3;
//
//        r3 = r1/r2;
//        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
//        r3 = r1/data2;
//        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
//    }
//
//}

TEST (RatioComparison, equal) {

    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_real_distribution<float> uniformDistribution(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){

        // generate random data
        float data = uniformDistribution(generator);

        // build the corresponding rational
        Ratio r1(data), r2(data), r3 (data*-1);

        ASSERT_TRUE(r1==r2);
        ASSERT_FALSE(r1==r3);
    }

}

//TEST (RatioComparison, notEqual) {
//
//    std::mt19937 generator(0);
//    //max value
//    const size_t maxValue = 10;
//    std::uniform_real_distribution<float> uniformDistribution(-(int)maxValue,(int)maxValue);
//
//    // run many times the same test with different values
//    for(int run=0; run<100; ++run){
//
//        // generate random data
//        float data1 = uniformDistribution(generator);
//        float data2 = uniformDistribution(generator);
//
//        // build the corresponding rational
//        Ratio r1(data1), r2(data2), r3;
//
//        r3 = r1/r2;
//        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
//        r3 = r1/data2;
//        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
//    }
//
//}

///////////////////////////////////////////////////////
//// Various functions
//
//TEST (RatioFunction, cosinus) {
//
//    std::mt19937 generator(0);
//    //max value
//    const size_t maxValue = 10;
//    std::uniform_real_distribution<float> uniformDistribution(-(int)maxValue,(int)maxValue);
//
//    // run many times the same test with different values
//    for(int run=0; run<100; ++run){
//
//        // generate random data
//        float data1 = uniformDistribution(generator);
//        float data2 = uniformDistribution(generator);
//
//        // build the corresponding rational
//        Ratio r1(data1), r2(data2), r3;
//
//        r3 = r1/r2;
//        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
//        r3 = r1/data2;
//        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
//    }
//
//}

//TEST (RatioFunction, sinus) {
//
//    std::mt19937 generator(0);
//    //max value
//    const size_t maxValue = 10;
//    std::uniform_real_distribution<float> uniformDistribution(-(int)maxValue,(int)maxValue);
//
//    // run many times the same test with different values
//    for(int run=0; run<100; ++run){
//
//        // generate random data
//        float data1 = uniformDistribution(generator);
//        float data2 = uniformDistribution(generator);
//
//        // build the corresponding rational
//        Ratio r1(data1), r2(data2), r3;
//
//        r3 = r1/r2;
//        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
//        r3 = r1/data2;
//        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
//    }
//
//}

//TEST (RatioFunction, tangent) {
//
//    std::mt19937 generator(0);
//    //max value
//    const size_t maxValue = 10;
//    std::uniform_real_distribution<float> uniformDistribution(-(int)maxValue,(int)maxValue);
//
//    // run many times the same test with different values
//    for(int run=0; run<100; ++run){
//
//        // generate random data
//        float data1 = uniformDistribution(generator);
//        float data2 = uniformDistribution(generator);
//
//        // build the corresponding rational
//        Ratio r1(data1), r2(data2), r3;
//
//        r3 = r1/r2;
//        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
//        r3 = r1/data2;
//        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
//    }
//
//}

//TEST (RatioFunction, absolute) {
//
//    std::mt19937 generator(0);
//    //max value
//    const size_t maxValue = 10;
//    std::uniform_real_distribution<float> uniformDistribution(-(int)maxValue,(int)maxValue);
//
//    // run many times the same test with different values
//    for(int run=0; run<100; ++run){
//
//        // generate random data
//        float data1 = uniformDistribution(generator);
//        float data2 = uniformDistribution(generator);
//
//        // build the corresponding rational
//        Ratio r1(data1), r2(data2), r3;
//
//        r3 = r1/r2;
//        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
//        r3 = r1/data2;
//        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
//    }
//
//}

//TEST (RatioFunction, floor) {
//
//    std::mt19937 generator(0);
//    //max value
//    const size_t maxValue = 10;
//    std::uniform_real_distribution<float> uniformDistribution(-(int)maxValue,(int)maxValue);
//
//    // run many times the same test with different values
//    for(int run=0; run<100; ++run){
//
//        // generate random data
//        float data1 = uniformDistribution(generator);
//        float data2 = uniformDistribution(generator);
//
//        // build the corresponding rational
//        Ratio r1(data1), r2(data2), r3;
//
//        r3 = r1/r2;
//        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
//        r3 = r1/data2;
//        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
//    }
//
//}

//TEST (RatioFunction, gcd) {
//
//    std::mt19937 generator(0);
//    //max value
//    const size_t maxValue = 10;
//    std::uniform_real_distribution<float> uniformDistribution(-(int)maxValue,(int)maxValue);
//
//    // run many times the same test with different values
//    for(int run=0; run<100; ++run){
//
//        // generate random data
//        float data1 = uniformDistribution(generator);
//        float data2 = uniformDistribution(generator);
//
//        // build the corresponding rational
//        Ratio r1(data1), r2(data2), r3;
//
//        r3 = r1/r2;
//        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
//        r3 = r1/data2;
//        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
//    }
//
//}

//TEST (RatioFunction, logarithm) {
//
//    std::mt19937 generator(0);
//    //max value
//    const size_t maxValue = 10;
//    std::uniform_real_distribution<float> uniformDistribution(-(int)maxValue,(int)maxValue);
//
//    // run many times the same test with different values
//    for(int run=0; run<100; ++run){
//
//        // generate random data
//        float data1 = uniformDistribution(generator);
//        float data2 = uniformDistribution(generator);
//
//        // build the corresponding rational
//        Ratio r1(data1), r2(data2), r3;
//
//        r3 = r1/r2;
//        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
//        r3 = r1/data2;
//        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
//    }
//
//}

//TEST (RatioFunction, power) {
//
//    std::mt19937 generator(0);
//    //max value
//    const size_t maxValue = 10;
//    std::uniform_real_distribution<float> uniformDistribution(-(int)maxValue,(int)maxValue);
//
//    // run many times the same test with different values
//    for(int run=0; run<100; ++run){
//
//        // generate random data
//        float data1 = uniformDistribution(generator);
//        float data2 = uniformDistribution(generator);
//
//        // build the corresponding rational
//        Ratio r1(data1), r2(data2), r3;
//
//        r3 = r1/r2;
//        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
//        r3 = r1/data2;
//        ASSERT_NEAR(data1/data2, r3.getNum()/(float)r3.getDenom(), 0.000015);
//    }
//
//}

TEST (RatioFunction, floatToRatio) {
    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 1000;
    std::uniform_real_distribution<float> uniformDistributionValue(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){

        // generate random data
        float data = uniformDistributionValue(generator);
        
        // build the corresponding rational
        Ratio r = Ratio::convertFloatToRatio(data);

        //due to the double precisions as absolute value increases, we adapt the acceptable error converted
        ASSERT_NEAR(data, r.getNum()/(float)r.getDenom(), 0.00000015*maxValue);
    }
}

TEST (RatioFunction, squareRoot) {
    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_real_distribution<float> uniformDistributionValue(0,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){

        // generate random data
        float data = uniformDistributionValue(generator);
        
        // build the corresponding rational
        Ratio r(data*data);
        r = Ratio::sqrt(r);

        //due to the double precisions as absolute value increases, we adapt the acceptable error converted
        ASSERT_NEAR(data, r.getNum()/(float)r.getDenom(), 0.000015);
    }
}

TEST (RatioFunction, exponential) {
    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_real_distribution<float> uniformDistributionValue(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){

        // generate random data
        float data = uniformDistributionValue(generator);
        
        // build the corresponding rational
        Ratio r(data);
        r = Ratio::exp(r);

        //due to the double precisions as absolute value increases, we adapt the acceptable error converted (expected up to 10000~)
        ASSERT_NEAR(exp(data), r.getNum()/(float)r.getDenom(), 0.015);
    }
}

TEST (RatioFunction, Zero) {
    
    Ratio r = Ratio::Zero();
    
    ASSERT_EQ(0, r.getNum());
    ASSERT_EQ(1, r.getDenom());
    
}

TEST (RatioFunction, Infinite) {
    
    Ratio r1 = Ratio::Infinite();
    
    ASSERT_EQ(1, r1.getNum());
    ASSERT_EQ(0, r1.getDenom());
    
    Ratio r2 = -Ratio::Infinite();
    
    ASSERT_EQ(-1, r2.getNum());
    ASSERT_EQ(0, r2.getDenom());
    
}

TEST (RatioFunction, ratioToFloat) {
    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 1000;
    std::uniform_real_distribution<float> uniformDistributionValue(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){

        // generate random data
        float data = uniformDistributionValue(generator);
        
        // build the corresponding rational
        Ratio r = Ratio::convertFloatToRatio(data);
        float temp = r.convertRatioToFloat();

        //due to the double precisions as absolute value increases, we adapt the acceptable error converted
        ASSERT_NEAR(data, temp, 0.00000015*maxValue);
    }
}

TEST (RatioFunction, signRatio) {
    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_real_distribution<float> uniformDistributionValue(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){

        // generate random data
        float data = uniformDistributionValue(generator);
        Ratio r(data);
        
        // build the corresponding rational
        int generatedSign = r.signRatio();

        ASSERT_GE(data*generatedSign, 0);
    }
}

TEST (RatioFunction, simplify) {
    
    //uses simplify implicitly
    Ratio r(4,8);
    
    ASSERT_EQ(1, r.getNum());
    ASSERT_EQ(2, r.getDenom());
    
    r = Ratio(-27,9);
    
    ASSERT_EQ(-3, r.getNum());
    ASSERT_EQ(1, r.getDenom());
    
    r = Ratio(-36,-14);
    
    ASSERT_EQ(18, r.getNum());
    ASSERT_EQ(7, r.getDenom());
    
    r = Ratio(37,-49);
    
    ASSERT_EQ(-37, r.getNum());
    ASSERT_EQ(49, r.getDenom());
    
}

TEST (RatioFunction, invert) {
    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_int_distribution<int> uniformIntDistributionValue(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){

        // generate random data
        int data1 = uniformIntDistributionValue(generator);
        int data2 = uniformIntDistributionValue(generator);
        
        while (data1 == 0) {
            data1 = uniformIntDistributionValue(generator);
        }
        while (data2 == 0) {
            data2 = uniformIntDistributionValue(generator);
        }
        
        // build the corresponding rational
        Ratio r1(data1,data2), r2;
        r2 = r1.invert();

        ASSERT_EQ(abs(r1.getNum()), r2.getDenom());
        ASSERT_EQ(abs(r2.getNum()), r1.getDenom());
        ASSERT_EQ(r1.signRatio(), r2.signRatio());
    }
}



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
