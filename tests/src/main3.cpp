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
//trier les fonctions
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
    ASSERT_EQ (r1.signRatio(), 1);
    
    Ratio r2((long)-1,(long)3);
    ASSERT_EQ (r2.getNum(), 1);
    ASSERT_EQ (r2.getDenom(), 3);
    ASSERT_EQ (r2.signRatio(), -1);
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
        ASSERT_NEAR(data, r.getNum()/(float)r.getDenom()*r.signRatio(), 0.00000015*maxValue);
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
        Ratio r1((long)data1, (long)data2), r2;

        r2 = r1;
        ASSERT_EQ (r2.getNum(), r1.getNum());
        ASSERT_EQ (r2.getDenom(), r1.getDenom());
        ASSERT_EQ (r2.signRatio(), r1.signRatio());
        
    }
}


/////////////////////////////////////////////////////
// arithmetic

TEST (RatioArithmetic, addition) {

    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 100;
    std::uniform_int_distribution<int> uniformIntDistribution(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){

        // generate random data
        int data1 = uniformIntDistribution(generator);
        int data2 = uniformIntDistribution(generator);
        int data3 = uniformIntDistribution(generator);
        int data4 = uniformIntDistribution(generator);
        
        while (data1 == 0)
            data1 = uniformIntDistribution(generator);
        
        while (data2 == 0)
            data2 = uniformIntDistribution(generator);
        
        while (data3 == 0)
            data3 = uniformIntDistribution(generator);

        while (data4 == 0)
            data4 = uniformIntDistribution(generator);
        
        // build the corresponding rational
        Ratio r1((long)data1, (long)data2), r2((long)data3, (long)data4), r3;

        r3 = r1 + r2;
        
        ASSERT_NEAR(data1/(float)data2 + data3/(float)data4, r3.getNum()/(float)r3.getDenom()*r3.signRatio(), 0.000015);
        
        r3 = r1 + data3;
        
        ASSERT_NEAR(data1/(float)data2 + data3, r3.getNum()/(float)r3.getDenom()*r3.signRatio(), 0.000015);
        
        r3 = data1 + r2;
        
        ASSERT_NEAR(data1 + data3/(float)data4, r3.getNum()/(float)r3.getDenom()*r3.signRatio(), 0.000015);
    }
}

TEST (RatioArithmetic, substraction) {

    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 100;
    std::uniform_int_distribution<int> uniformIntDistribution(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){

        // generate random data
        int data1 = uniformIntDistribution(generator);
        int data2 = uniformIntDistribution(generator);
        int data3 = uniformIntDistribution(generator);
        int data4 = uniformIntDistribution(generator);
        
        while (data1 == 0)
            data1 = uniformIntDistribution(generator);
        
        while (data2 == 0)
            data2 = uniformIntDistribution(generator);
        
        while (data3 == 0)
            data3 = uniformIntDistribution(generator);

        while (data4 == 0)
            data4 = uniformIntDistribution(generator);
        
        // build the corresponding rational
        Ratio r1((long)data1, (long)data2), r2((long)data3, (long)data4), r3;
        
        r3 = r1 - r2;
        
        ASSERT_NEAR((data1/(float)data2) - (data3/(float)data4), r3.getNum()/(float)r3.getDenom()*r3.signRatio(), 0.000015);
        
        r3 = r1 - data3;
        
        ASSERT_NEAR((data1/(float)data2) - data3, r3.getNum()/(float)r3.getDenom()*r3.signRatio(), 0.000015);
        
        r3 = data2 - r2;
        
        ASSERT_NEAR(data2 - (data3/(float)data4), r3.getNum()/(float)r3.getDenom()*r3.signRatio(), 0.000015);
        
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
        Ratio r1((long)data1, (long)data2), r2;
        
        r2 = -r1;
        
        ASSERT_EQ (r2.getNum(), r1.getNum());
        ASSERT_EQ (r2.getDenom(), r1.getDenom());
        ASSERT_EQ (r2.signRatio(), -r1.signRatio());
        
    }
}

TEST (RatioArithmetic, modulo) {

    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 100;
    std::uniform_int_distribution<int> uniformIntDistribution(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){
        
        // generate random data
        int data1 = uniformIntDistribution(generator);
        int data2 = uniformIntDistribution(generator);
        int data3 = uniformIntDistribution(generator);
        int data4 = uniformIntDistribution(generator);
        
        while (data1 == 0)
            data1 = uniformIntDistribution(generator);
        
        while (data2 == 0)
            data2 = uniformIntDistribution(generator);
        
        while (data3 == 0)
            data3 = uniformIntDistribution(generator);
        
        while (data4 == 0)
            data4 = uniformIntDistribution(generator);
        
        // build the corresponding rational
        
        Ratio r1((long)data1, (long)data2), r2((long)data3, (long)data4), r3;
        
        //The fact that there are modulos that works way better in rational provokes some errors :
        //ex : 2%0.667=0.667 <=> (2/1)%(2/3)=0
        r3 = r1 % r2;
        
        EXPECT_NEAR(fmod((data1/(float)data2), (data3/(float)data4)), r3.getNum()/(float)r3.getDenom()*r3.signRatio(), 0.000015);
        
        r3 = r1 % data3;
        
        EXPECT_NEAR(fmod((data1/(float)data2),data3), r3.getNum()/(float)r3.getDenom()*r3.signRatio(), 0.000015);
        
        r3 = data2 % r2;
        
        EXPECT_NEAR(fmod(data2,(data3/(float)data4)), r3.getNum()/(float)r3.getDenom()*r3.signRatio(), 0.000015);
    }
}


TEST (RatioArithmetic, multiply) {

    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_int_distribution<float> uniformIntDistribution(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){
        
        // generate random data
        int data1 = uniformIntDistribution(generator);
        int data2 = uniformIntDistribution(generator);
        int data3 = uniformIntDistribution(generator);
        int data4 = uniformIntDistribution(generator);
        
        while (data2 == 0)
            data2 = uniformIntDistribution(generator);
        while (data4 == 0)
            data4 = uniformIntDistribution(generator);
        
        // build the corresponding rational
        Ratio r1((long)data1, (long)data2), r2((long)data3, (long)data4), r3;
        
        r3 = r1*r2;
        //precision expected for a 10x10 operation
        ASSERT_NEAR((data1/(float)data2) * (data3/(float)data4), r3.getNum()/(float)r3.getDenom()*r3.signRatio(), 0.00015);
        
        r3 = r1*data2;
        ASSERT_NEAR((data1/(float)data2) * data2, r3.getNum()/(float)r3.getDenom()*r3.signRatio(), 0.00015);
        
        r3 = data1*r2;
        //precision expected for a 10x10 operation
        ASSERT_NEAR(data1 * (data3/(float)data4), r3.getNum()/(float)r3.getDenom()*r3.signRatio(), 0.00015);
    }
        
}

TEST (RatioArithmetic, division) {

    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_int_distribution<float> uniformIntDistribution(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){
        
        // generate random data
        int data1 = uniformIntDistribution(generator);
        int data2 = uniformIntDistribution(generator);
        int data3 = uniformIntDistribution(generator);
        int data4 = uniformIntDistribution(generator);
        
        while (data2 == 0)
            data2 = uniformIntDistribution(generator);
        while (data3 == 0)
            data3 = uniformIntDistribution(generator);
        while (data4 == 0)
            data4 = uniformIntDistribution(generator);
        
        // build the corresponding rational
        Ratio r1((long)data1, (long)data2), r2((long)data3, (long)data4), r3;
        
        r3 = r1/r2;
        ASSERT_NEAR((data1/(float)data2)/(data3/(float)data4), r3.getNum()/(float)r3.getDenom()*r3.signRatio(), 0.000015);
        
        r3 = r1/data2;
        ASSERT_NEAR((data1/(float)data2)/data2, r3.getNum()/(float)r3.getDenom()*r3.signRatio(), 0.000015);
        
        r3 = data1/r2;
        ASSERT_NEAR(data1/(data3/(float)data4), r3.getNum()/(float)r3.getDenom()*r3.signRatio(), 0.000015);
    }
        
}

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
        Ratio r1(data), r2(data), r3 (-data);

        ASSERT_TRUE(r1==r2);
        ASSERT_FALSE(r1==r3);
    }

}

TEST (RatioComparison, notEqual) {

    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_real_distribution<float> uniformDistribution(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){

        // generate random data
        float data = uniformDistribution(generator);

        // build the corresponding rational
        Ratio r1(data), r2(data), r3 (-data);

        ASSERT_FALSE(r1!=r2);
        ASSERT_TRUE(r1!=r3);
    }


}

TEST (RatioComparison, LessThan) {

    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_int_distribution<float> uniformIntDistribution(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){
        
        // generate random data
        int data1 = uniformIntDistribution(generator);
        int data2 = uniformIntDistribution(generator);
        
        while (data2 == 0)
            data2 = uniformIntDistribution(generator);
        
        // build the corresponding rational
        Ratio r1((long)data1, (long)data2), r2(r1), r3(r1+1), r4(r1-1);
        
        ASSERT_FALSE(r1<r2);
        ASSERT_TRUE(r1<r3);
        ASSERT_FALSE(r1<r4);
    }

}

TEST (RatioComparison, greaterThan) {

    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_int_distribution<float> uniformIntDistribution(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){
        
        // generate random data
        int data1 = uniformIntDistribution(generator);
        int data2 = uniformIntDistribution(generator);
        
        while (data2 == 0)
            data2 = uniformIntDistribution(generator);
        
        // build the corresponding rational
        Ratio r1((long)data1, (long)data2), r2(r1), r3(r1+1), r4(r1-1);
        
        ASSERT_FALSE(r1>r2);
        ASSERT_FALSE(r1>r3);
        ASSERT_TRUE(r1>r4);
    }

}

TEST (RatioComparison, lessEqual) {

    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_int_distribution<float> uniformIntDistribution(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){
        
        // generate random data
        int data1 = uniformIntDistribution(generator);
        int data2 = uniformIntDistribution(generator);
        
        while (data2 == 0)
            data2 = uniformIntDistribution(generator);
        
        // build the corresponding rational
        Ratio r1((long)data1, (long)data2), r2(r1), r3(r1+1), r4(r1-1);
        
        ASSERT_TRUE(r1<=r2);
        ASSERT_TRUE(r1<=r3);
        ASSERT_FALSE(r1<=r4);
    }

}

TEST (RatioComparison, greaterEqual) {

    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_int_distribution<float> uniformIntDistribution(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){
        
        // generate random data
        int data1 = uniformIntDistribution(generator);
        int data2 = uniformIntDistribution(generator);
        
        while (data2 == 0)
            data2 = uniformIntDistribution(generator);
        
        // build the corresponding rational
        Ratio r1((long)data1, (long)data2), r2(r1), r3(r1+1), r4(r1-1);
        
        ASSERT_TRUE(r1>=r2);
        ASSERT_FALSE(r1>=r3);
        ASSERT_TRUE(r1>=r4);
    }

}

///////////////////////////////////////////////////////
//// Various functions

TEST (RatioFunction, cosinus) {

    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_real_distribution<float> uniformDistribution(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){

        // generate random data
        float data1 = uniformDistribution(generator);

        // build the corresponding rational
        Ratio r1(data1), r2;
        
        r2 = Ratio::cos(r1);
        ASSERT_NEAR(std::cos(data1*M_PI/180.0), r2.getNum()/(float)r2.getDenom()*r2.signRatio(), 0.0015);
    }

}

TEST (RatioFunction, arcCosinus) {

    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 1;
    std::uniform_real_distribution<float> uniformDistribution(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){

        // generate random data
        float data1 = uniformDistribution(generator);

        // build the corresponding rational
        Ratio r1(data1), r2;
        
        r2 = Ratio::acos(r1);
        ASSERT_NEAR(std::acos(data1)*180.0/M_PI, r2.getNum()/(float)r2.getDenom()*r2.signRatio(), 0.0015);
    }


}

TEST (RatioFunction, sinus) {

    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_real_distribution<float> uniformDistribution(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){

        // generate random data
        float data1 = uniformDistribution(generator);

        // build the corresponding rational
        Ratio r1(data1), r2;
        
        r2 = Ratio::sin(r1);
        ASSERT_NEAR(std::sin(data1*M_PI/180.0), r2.getNum()/(float)r2.getDenom()*r2.signRatio(), 0.0015);
    }

}

TEST (RatioFunction, arcSinus) {
    
    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 1;
    std::uniform_real_distribution<float> uniformDistribution(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){

        // generate random data
        float data1 = uniformDistribution(generator);

        // build the corresponding rational
        Ratio r1(data1), r2;
        
        r2 = Ratio::asin(r1);
        ASSERT_NEAR(std::asin(data1)*180.0/M_PI, r2.getNum()/(float)r2.getDenom()*r2.signRatio(), 0.0015);
    }


}

TEST (RatioFunction, tangent) {

    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_real_distribution<float> uniformDistribution(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){

        // generate random data
        float data1 = uniformDistribution(generator);

        // build the corresponding rational
        Ratio r1(data1), r2;
        
        r2 = Ratio::tan(r1);
        ASSERT_NEAR(std::tan(data1*M_PI/180.0), r2.getNum()/(float)r2.getDenom()*r2.signRatio(), 0.0015);
    }

}

TEST (RatioFunction, arcTangent) {
    
    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 1;
    std::uniform_real_distribution<float> uniformDistribution(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){

        // generate random data
        float data1 = uniformDistribution(generator);

        // build the corresponding rational
        Ratio r1(data1), r2;
        
        r2 = Ratio::atan(r1);
        ASSERT_NEAR(std::atan(data1)*180.0/M_PI, r2.getNum()/(float)r2.getDenom()*r2.signRatio(), 0.0015);
    }


}

TEST (RatioFunction, absolute) {

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
        Ratio r1((long)data1, (long)data2), r2;
        
        r2 = Ratio::abs(r1);
        
        ASSERT_EQ (r2.getNum(), r1.getNum());
        ASSERT_EQ (r2.getDenom(), r1.getDenom());
        ASSERT_EQ (r2.signRatio(), 1);
        
    }

}

TEST (RatioFunction, floor) {

    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 1;
    std::uniform_real_distribution<float> uniformDistribution(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){

        // generate random data
        float data1 = uniformDistribution(generator);

        // build the corresponding rational
        Ratio r1(data1), r2;
        
        r2 = Ratio::floor(r1);
        
        ASSERT_EQ (std::floor(data1), r2.getNum()/r2.getDenom()*r2.signRatio());
    }

}

//Didn't manage to find a good gcd function between two real numbers that works with our tests
//TEST (RatioFunction, gcd) {
//
//    std::mt19937 generator(0);
//    //max value
//    const size_t maxValue = 10;
//    std::uniform_real_distribution<float> uniformDistribution(-(int)maxValue,(int)maxValue);
//
//    // run many times the same test with different values
//    for(int run=0; run<50; ++run){
//
//        // generate random data
//        float data1 = uniformDistribution(generator);
//        float data2 = uniformDistribution(generator);
//
//        // build the corresponding rational
//        Ratio r1(data1), r2(data2), r3;
//
//        r3 = Ratio::gcrd(r1, r2);
//        ASSERT_NEAR(gcd(data1,data2), r3.getNum()/(float)r3.getDenom(), 0.15);
//    }
//
//}

TEST (RatioFunction, logarithm) {

    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 1;
    std::uniform_real_distribution<float> uniformDistribution(0,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){

        // generate random data
        float data1 = uniformDistribution(generator);
        
        // build the corresponding rational
        Ratio r1(data1), r2;
        
        r2 = Ratio::log(r1);

        ASSERT_NEAR (std::log(data1), r2.getNum()/(float)r2.getDenom()*r2.signRatio(), 0.000015);
    }

}

TEST (RatioFunction, power) {

    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 5;
    std::uniform_int_distribution<int> uniformIntDistribution(-(int)maxValue,(int)maxValue);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){

        // generate random data
        int data1 = uniformIntDistribution(generator);
        int data2 = uniformIntDistribution(generator);
        int data3 = uniformIntDistribution(generator);
        
        while (data1 == 0)
            data1 = uniformIntDistribution(generator);
        while (data2 == 0)
            data2 = uniformIntDistribution(generator);

        // build the corresponding rational
        Ratio r1((long)data1, (long)data2), r2;

        r2 = Ratio::pow(r1,data3);
        
        std::cout << "Expected pow(" << data1 << "/" << data2 << "," << data3 << ") = " << pow(data1/(float)data2, data3) << std::endl;

        std::cout << "Outputed pow(" << r1 << "," << data3 << ") = " << Ratio::pow(r1, data3).convertRatioToFloat() << std::endl;
        
        ASSERT_NEAR(std::pow(data1/(float)data2, data3), r2.getNum()/(float)r2.getDenom()*r2.signRatio(), 0.00015);
    }

}

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
        ASSERT_NEAR(data, r.getNum()/(float)r.getDenom()*r.signRatio(), 0.00000015*maxValue);
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
        ASSERT_NEAR(data, r.getNum()/(float)r.getDenom(), 0.015);
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
        ASSERT_NEAR(exp(data), r.getNum()/(float)r.getDenom()*r.signRatio(), 0.015);
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
    ASSERT_EQ(1, r1.signRatio());
    
    Ratio r2 = -Ratio::Infinite();
    
    ASSERT_EQ(1, r2.getNum());
    ASSERT_EQ(0, r2.getDenom());
    ASSERT_EQ(-1, r2.signRatio());
    
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
    Ratio r((long)4,(long)8);
    
    ASSERT_EQ(1, r.getNum());
    ASSERT_EQ(2, r.getDenom());
    
    r = Ratio((long)-27,(long)9);
    
    ASSERT_EQ(3, r.getNum());
    ASSERT_EQ(1, r.getDenom());
    ASSERT_EQ(-1, r.signRatio());
    
    r = Ratio((long)-36,(long)-14);
    
    ASSERT_EQ(18, r.getNum());
    ASSERT_EQ(7, r.getDenom());
    ASSERT_EQ(1, r.signRatio());
    
    r = Ratio((long)37,(long)-49);
    
    ASSERT_EQ(37, r.getNum());
    ASSERT_EQ(49, r.getDenom());
    ASSERT_EQ(-1, r.signRatio());
    
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
        Ratio r1((long)data1,(long)data2), r2;
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
