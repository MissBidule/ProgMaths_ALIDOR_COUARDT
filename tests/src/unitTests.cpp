#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <algorithm>
#include <gtest/gtest.h>

#include "RatioConstructors.hpp"
#include "RatioFunctions.hpp"
#include "RatioOperators.hpp"

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
    Ratio<long> r1;
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
        Ratio<long> r(data);

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
        Ratio<long> r1((long)data1, (long)data2), r2;

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
        Ratio<long> r1((long)data1, (long)data2), r2((long)data3, (long)data4), r3;

        r3 = r1 + r2;
        
        ASSERT_NEAR(data1/(float)data2 + data3/(float)data4, r3.getNum()/(float)r3.getDenom()*r3.signRatio(), 0.000015);
        
        r3 = r1 + data3;
        
        ASSERT_NEAR(data1/(float)data2 + data3, r3.getNum()/(float)r3.getDenom()*r3.signRatio(), 0.000015);
        
        r3 = (double)data1 + r2;
        
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
        Ratio<long> r1((long)data1, (long)data2), r2((long)data3, (long)data4), r3;
        
        r3 = r1 - r2;
        
        ASSERT_NEAR((data1/(float)data2) - (data3/(float)data4), r3.getNum()/(float)r3.getDenom()*r3.signRatio(), 0.000015);
        
        r3 = r1 - data3;
        
        ASSERT_NEAR((data1/(float)data2) - data3, r3.getNum()/(float)r3.getDenom()*r3.signRatio(), 0.000015);
        
        r3 = (double)data2 - r2;
        
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
        Ratio<long> r1((long)data1, (long)data2), r2;
        
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
        
        Ratio<long> r1((long)data1, (long)data2), r2((long)data3, (long)data4), r3;
        
        //The fact that there are modulos that works way better in rational provokes some errors :
        //ex : 2%0.667=0.667 <=> (2/1)%(2/3)=0
        r3 = r1 % r2;
        
        EXPECT_NEAR(fmod((data1/(float)data2), (data3/(float)data4)), r3.getNum()/(float)r3.getDenom()*r3.signRatio(), 0.000015);
        
        r3 = r1 % data3;
        
        EXPECT_NEAR(fmod((data1/(float)data2),data3), r3.getNum()/(float)r3.getDenom()*r3.signRatio(), 0.000015);
        
        r3 = (double)data2 % r2;
        
        EXPECT_NEAR(fmod(data2,(data3/(float)data4)), r3.getNum()/(float)r3.getDenom()*r3.signRatio(), 0.000015);
    }
}


TEST (RatioArithmetic, multiplication) {

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
        Ratio<long> r1((long)data1, (long)data2), r2((long)data3, (long)data4), r3;
        
        r3 = r1*r2;
        //precision expected for a 10x10 operation
        ASSERT_NEAR((data1/(float)data2) * (data3/(float)data4), r3.getNum()/(float)r3.getDenom()*r3.signRatio(), 0.00015);
        
        r3 = r1*data2;
        ASSERT_NEAR((data1/(float)data2) * data2, r3.getNum()/(float)r3.getDenom()*r3.signRatio(), 0.00015);
        
        r3 = (double)data1 * r2;
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
        Ratio<long> r1((long)data1, (long)data2), r2((long)data3, (long)data4), r3;
        
        r3 = r1/r2;
        ASSERT_NEAR((data1/(float)data2)/(data3/(float)data4), r3.getNum()/(float)r3.getDenom()*r3.signRatio(), 0.000015);
        
        r3 = r1/data2;
        ASSERT_NEAR((data1/(float)data2)/data2, r3.getNum()/(float)r3.getDenom()*r3.signRatio(), 0.000015);
        
        r3 = (double)data1/r2;
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
        Ratio<long> r1(data), r2(data), r3 (-data);

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
        Ratio<long> r1(data), r2(data), r3 (-data);

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
        Ratio<long> r1(data1), r2;
        
        r2 = Ratio<long>::cos(r1);
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
        Ratio<long> r1(data1), r2;
        
        r2 = Ratio<long>::acos(r1);
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
        Ratio<long> r1(data1), r2;
        
        r2 = Ratio<long>::sin(r1);
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
        Ratio<long> r1(data1), r2;
        
        r2 = Ratio<long>::asin(r1);
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
        Ratio<long> r1(data1), r2;
        
        r2 = Ratio<long>::tan(r1);
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
        Ratio<long> r1(data1), r2;
        
        r2 = Ratio<long>::atan(r1);
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
        Ratio<long> r1((long)data1, (long)data2), r2;
        
        r2 = Ratio<long>::abs(r1);
        
        ASSERT_EQ(r2.getNum(), r1.getNum());
        ASSERT_EQ(r2.getDenom(), r1.getDenom());
        ASSERT_EQ(r2.signRatio(), 1);
        
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
        Ratio<long> r1(data1), r2;
        
        r2 = Ratio<long>::floor(r1);
        
        ASSERT_EQ(std::floor(data1), r2.getNum()/r2.getDenom()*r2.signRatio());
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
//        //Here we need a gcd function between 2 real numbers
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
        Ratio<long> r1(data1), r2;
        
        r2 = Ratio<long>::log(r1);

        ASSERT_NEAR(std::log(data1), r2.getNum()/(float)r2.getDenom()*r2.signRatio(), 0.000015);
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
        Ratio<long> r1((long)data1, (long)data2), r2;

        r2 = Ratio<long>::pow(r1,data3);
        
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
        Ratio<long> r = Ratio<long>::convertFloatToRatio(data);

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
        long data = uniformDistributionValue(generator);
        
        // build the corresponding rational
        Ratio<long> r(data*data);
        r = Ratio<long>::sqrt(r);

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
        long data = uniformDistributionValue(generator);
        
        // build the corresponding rational
        Ratio r(data);
        r = Ratio<long>::exp(r);

        //due to the double precisions as absolute value increases, we adapt the acceptable error converted (expected up to 10000~)
        ASSERT_NEAR(exp(data), r.getNum()/(float)r.getDenom()*r.signRatio(), 0.015);
    }
}

TEST (RatioFunction, Zero) {
    
    Ratio r = Ratio<long>::Zero();
    
    ASSERT_EQ(0, r.getNum());
    ASSERT_EQ(1, r.getDenom());
    
}

TEST (RatioFunction, Infinite) {
    
    Ratio r1 = Ratio<long>::Infinite();
    
    ASSERT_EQ(1, r1.getNum());
    ASSERT_EQ(0, r1.getDenom());
    ASSERT_EQ(1, r1.signRatio());
    
    Ratio r2 = -Ratio<long>::Infinite();
    
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
        Ratio r = Ratio<long>::convertFloatToRatio(data);
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
        Ratio<long> r(data);
        
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
        Ratio<long> r1((long)data1,(long)data2), r2;
        r2 = r1.invert();

        ASSERT_EQ(abs(r1.getNum()), r2.getDenom());
        ASSERT_EQ(abs(r2.getNum()), r1.getDenom());
        ASSERT_EQ(r1.signRatio(), r2.signRatio());
    }
}

///////////////////////////////////////////////////////
//// Infini, zero and other special operation tests

TEST (SpecialOperations, addition) {
    
    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_int_distribution<float> uniformIntDistribution(-(int)maxValue,(int)maxValue);
    
    Ratio<long> r2(Ratio<long>::Zero()), r3(Ratio<long>::Infinite()), r4(-Ratio<long>::Infinite());
    
    ASSERT_EQ((r2+r3), Ratio<long>::Infinite());
    ASSERT_EQ((r2+r4), -Ratio<long>::Infinite());
    
    try{
        r3+r4;
        }
        catch( const std::exception &e){
            EXPECT_TRUE( std::string(e.what()).find("Math error: Inf - Inf undetermined\n") == 0);
        }

    // run many times the same test with different values
    for(int run=0; run<100; ++run){
        
        // generate random data
        int data1 = uniformIntDistribution(generator);
        int data2 = uniformIntDistribution(generator);
        
        while (data2 == 0)
            data2 = uniformIntDistribution(generator);
        
        // build the corresponding rational
        Ratio r1((long)data1, (long)data2);
        
        ASSERT_EQ((r1+r2), r1);
        ASSERT_EQ(r1+r3, Ratio<long>::Infinite());
        ASSERT_EQ(r1+r4, -Ratio<long>::Infinite());
        
    }
    
}

TEST (SpecialOperations, substraction) {
    
    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_int_distribution<float> uniformIntDistribution(-(int)maxValue,(int)maxValue);
    
    Ratio<long> r2(Ratio<long>::Zero()), r3(Ratio<long>::Infinite()), r4(-Ratio<long>::Infinite());
    
    ASSERT_EQ((r2-r3), -Ratio<long>::Infinite());
    ASSERT_EQ((r2-r4), Ratio<long>::Infinite());
    ASSERT_EQ((r3-r4), Ratio<long>::Infinite());
    
    try{
        r4-r3;
        }
        catch( const std::exception &e){
            EXPECT_TRUE( std::string(e.what()).find("Math error: Inf - Inf undetermined\n") == 0);
        }

    // run many times the same test with different values
    for(int run=0; run<100; ++run){
        
        // generate random data
        int data1 = uniformIntDistribution(generator);
        int data2 = uniformIntDistribution(generator);
        
        while (data2 == 0)
            data2 = uniformIntDistribution(generator);
        
        // build the corresponding rational
        Ratio r1((long)data1, (long)data2);
        
        ASSERT_EQ((r1-r2), r1);
        ASSERT_EQ((r1-r3), -Ratio<long>::Infinite());
        ASSERT_EQ((r1-r4), Ratio<long>::Infinite());
        
    }
    
}

TEST (SpecialOperations, unaryMinus) {
    
    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_int_distribution<float> uniformIntDistribution(-(int)maxValue,(int)maxValue);
    
    Ratio<long> r2(Ratio<long>::Zero()), r3(Ratio<long>::Infinite()), r4(-Ratio<long>::Infinite());
    
    ASSERT_EQ(r2, -r2);
    ASSERT_EQ(r3, -r4);
    ASSERT_EQ(-r4, r3);
    
}

TEST (SpecialOperations, modulo) {
    
    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_int_distribution<float> uniformIntDistribution(-(int)maxValue,(int)maxValue);
    
    Ratio<long> r2(Ratio<long>::Zero()), r3(Ratio<long>::Infinite());
    
    ASSERT_EQ((r2%r3), r2);
    ASSERT_EQ((r3%r2), r3);
    
    try{
        r3%r3;
        }
        catch( const std::exception &e){
            EXPECT_TRUE( std::string(e.what()).find("Math error: Inf % Inf undetermined\n") == 0);
        }

    // run many times the same test with different values
    for(int run=0; run<100; ++run){
        
        // generate random data
        int data1 = uniformIntDistribution(generator);
        int data2 = uniformIntDistribution(generator);
        
        while (data2 == 0)
            data2 = uniformIntDistribution(generator);
        
        // build the corresponding rational
        Ratio r1((long)data1, (long)data2);
        
        ASSERT_EQ((r1%r2), r1);
        ASSERT_EQ((r2%r1), r2);
        ASSERT_EQ((r1%r3), r1);
        
    }
    
}

TEST (SpecialOperations, multiplication) {
    
    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_int_distribution<float> uniformIntDistribution(-(int)maxValue,(int)maxValue);
    
    Ratio<long> r2(Ratio<long>::Zero()), r3(Ratio<long>::Infinite()), r4(-r3);
    
    ASSERT_EQ((r3*r4), r4);
    ASSERT_EQ((r3*r3), r3);
    ASSERT_EQ((r4*r4), r3);
    
    try{
        r2*r3;
        }
        catch( const std::exception &e){
            EXPECT_TRUE( std::string(e.what()).find("Math error: Inf x 0 undetermined\n") == 0);
        }

    // run many times the same test with different values
    for(int run=0; run<100; ++run){
        
        // generate random data
        int data1 = uniformIntDistribution(generator);
        int data2 = uniformIntDistribution(generator);
        
        while (data1 == 0)
            data1 = uniformIntDistribution(generator);
        while (data2 == 0)
            data2 = uniformIntDistribution(generator);
        
        // build the corresponding rational
        Ratio r1((long)data1, (long)data2);
        
        ASSERT_EQ((r1*r2), r2);
        ASSERT_EQ((r1*r3), r3*r1.signRatio());
        ASSERT_EQ((r1*r4), r4*r1.signRatio());
        
    }
    
}

TEST (SpecialOperations, division) {
    
    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_int_distribution<float> uniformIntDistribution(-(int)maxValue,(int)maxValue);
    
    Ratio<long> r2(Ratio<long>::Zero()), r3(Ratio<long>::Infinite());
    
    ASSERT_EQ((r2/r3), r2);
    
    try{
        r2/r2;
        }
        catch( const std::exception &e){
            EXPECT_TRUE( std::string(e.what()).find("Math error: Attempted to divide by Zero\n") == 0);
        }

    try{
        r3/r2;
        }
        catch( const std::exception &e){
            EXPECT_TRUE( std::string(e.what()).find("Math error: Attempted to divide by Zero\n") == 0);
        }
    
    try{
        r3/r3;
        }
        catch( const std::exception &e){
            EXPECT_TRUE( std::string(e.what()).find("Math error: Inf / Inf undetermined\n") == 0);
        }

    // run many times the same test with different values
    for(int run=0; run<100; ++run){
        
        // generate random data
        int data1 = uniformIntDistribution(generator);
        int data2 = uniformIntDistribution(generator);
        
        while (data1 == 0)
            data1 = uniformIntDistribution(generator);
        while (data2 == 0)
            data2 = uniformIntDistribution(generator);
        
        // build the corresponding rational
        Ratio r1((long)data1, (long)data2);
        
        try{
            r1/r2;
            }
            catch( const std::exception &e){
                EXPECT_TRUE( std::string(e.what()).find("Math error: Attempted to divide by Zero\n") == 0);
            }
        
        ASSERT_EQ((r1/r3), r2);
        ASSERT_EQ((r3/r1), r3);
        
    }
    
}

TEST (SpecialOperations, equal) {

    Ratio<long> r2(Ratio<long>::Zero()), r3(Ratio<long>::Infinite()), r4(-r3);
    
    ASSERT_TRUE(r2==-r2);
    ASSERT_TRUE(r3==r3);
    ASSERT_FALSE(r3==r4);

}

TEST (SpecialOperations, notEqual) {

    Ratio<long> r2(Ratio<long>::Zero()), r3(Ratio<long>::Infinite()), r4(-r3);
    
    ASSERT_FALSE(r2!=-r2);
    ASSERT_FALSE(r3!=r3);
    ASSERT_TRUE(r3!=r4);

}

TEST (SpecialOperations, LessThan) {

    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_int_distribution<int> uniformIntDistribution(1,(int)maxValue);

    Ratio<long> r2(Ratio<long>::Zero()), r3(Ratio<long>::Infinite()), r4(-r3);
    
    ASSERT_FALSE(r2<-r2);
    ASSERT_FALSE(-r2<r2);
    ASSERT_TRUE(r2<r3);
    ASSERT_FALSE(r2<r4);
    ASSERT_FALSE(r3<r3);
    ASSERT_FALSE(r3<r4);
    ASSERT_TRUE(r4<r3);
    
    // run many times the same test with different values
    for(int run=0; run<100; ++run){
        
        // generate random data
        int data1 = uniformIntDistribution(generator);
        int data2 = uniformIntDistribution(generator);
        
        // build the corresponding rational
        Ratio r1((long)data1, (long)data2);
        
        ASSERT_FALSE(r1<r2);
        ASSERT_TRUE(-r1<r2);
        ASSERT_TRUE(r1<r3);
        ASSERT_FALSE(r1<r4);
    }


}

TEST (SpecialOperations, greaterThan) {

    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_int_distribution<int> uniformIntDistribution(1,(int)maxValue);

    Ratio<long> r2(Ratio<long>::Zero()), r3(Ratio<long>::Infinite()), r4(-r3);
    
    ASSERT_FALSE(r2>-r2);
    ASSERT_FALSE(-r2>r2);
    ASSERT_FALSE(r2>r3);
    ASSERT_TRUE(r2>r4);
    ASSERT_FALSE(r3>r3);
    ASSERT_TRUE(r3>r4);
    ASSERT_FALSE(r4>r3);
    
    // run many times the same test with different values
    for(int run=0; run<100; ++run){
        
        // generate random data
        int data1 = uniformIntDistribution(generator);
        int data2 = uniformIntDistribution(generator);
        
        // build the corresponding rational
        Ratio r1((long)data1, (long)data2);
        
        ASSERT_TRUE(r1>r2);
        ASSERT_FALSE(-r1>r2);
        ASSERT_FALSE(r1>r3);
        ASSERT_TRUE(r1>r4);
    }

}

TEST (SpecialOperations, lessEqual) {

    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_int_distribution<int> uniformIntDistribution(1,(int)maxValue);

    Ratio<long> r2(Ratio<long>::Zero()), r3(Ratio<long>::Infinite()), r4(-r3);
    
    ASSERT_TRUE(r2<=-r2);
    ASSERT_TRUE(-r2<=r2);
    ASSERT_TRUE(r2<=r3);
    ASSERT_FALSE(r2<=r4);
    ASSERT_TRUE(r3<=r3);
    ASSERT_FALSE(r3<=r4);
    ASSERT_TRUE(r4<=r3);
    
    // run many times the same test with different values
    for(int run=0; run<100; ++run){
        
        // generate random data
        int data1 = uniformIntDistribution(generator);
        int data2 = uniformIntDistribution(generator);
        
        // build the corresponding rational
        Ratio r1((long)data1, (long)data2);
        
        ASSERT_FALSE(r1<=r2);
        ASSERT_TRUE(-r1<=r2);
        ASSERT_TRUE(r1<=r3);
        ASSERT_FALSE(r1<=r4);
    }

}

TEST (SpecialOperations, greaterEqual) {

    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_int_distribution<int> uniformIntDistribution(1,(int)maxValue);

    Ratio<long> r2(Ratio<long>::Zero()), r3(Ratio<long>::Infinite()), r4(-r3);
    
    ASSERT_TRUE(r2>=-r2);
    ASSERT_TRUE(-r2>=r2);
    ASSERT_FALSE(r2>=r3);
    ASSERT_TRUE(r2>=r4);
    ASSERT_TRUE(r3>=r3);
    ASSERT_TRUE(r3>=r4);
    ASSERT_FALSE(r4>=r3);
    
    // run many times the same test with different values
    for(int run=0; run<100; ++run){
        
        // generate random data
        int data1 = uniformIntDistribution(generator);
        int data2 = uniformIntDistribution(generator);
        
        // build the corresponding rational
        Ratio r1((long)data1, (long)data2);
        
        ASSERT_TRUE(r1>=r2);
        ASSERT_FALSE(-r1>=r2);
        ASSERT_FALSE(r1>=r3);
        ASSERT_TRUE(r1>=r4);
    }

}

TEST (SpecialOperations, squareRoot) {

    ASSERT_EQ(Ratio<long>::sqrt(Ratio<long>::Infinite()), Ratio<long>::Infinite());
    
    try{
        Ratio<long>::sqrt(Ratio((long)-1));
    }
    catch( const std::exception &e){
        EXPECT_TRUE( std::string(e.what()).find("Math error: Attempted to squared a negative value\n") == 0);
    }

}

TEST (SpecialOperations, exponential) {

    Ratio<long> r2(Ratio<long>::Zero()), r3(Ratio<long>::Infinite());
    
    ASSERT_EQ(Ratio<long>::exp(r2), 1);
    ASSERT_EQ(Ratio<long>::exp(r3), Ratio<long>::Infinite());
    ASSERT_EQ(Ratio<long>::exp(-r3), 0);

}

TEST (SpecialOperations, allTrigonometry) {
    
    try{
        Ratio<long>::cos(Ratio<long>::Infinite());
    }
    catch( const std::exception &e){
        EXPECT_TRUE( std::string(e.what()).find("Math error: cos(Inf) not determined\n") == 0);
    }
    
    try{
        Ratio<long>::acos(Ratio<long>::Infinite());
    }
    catch( const std::exception &e){
        EXPECT_TRUE( std::string(e.what()).find("Math error: acos(Inf) not determined\n") == 0);
    }
    
    try{
        Ratio<long>::sin(Ratio<long>::Infinite());
    }
    catch( const std::exception &e){
        EXPECT_TRUE( std::string(e.what()).find("Math error: sin(Inf) not determined\n") == 0);
    }
    
    try{
        Ratio<long>::asin(Ratio<long>::Infinite());
    }
    catch( const std::exception &e){
        EXPECT_TRUE( std::string(e.what()).find("Math error: asin(Inf) not determined\n") == 0);
    }
    
    try{
        Ratio<long>::tan(Ratio<long>::Infinite());
    }
    catch( const std::exception &e){
        EXPECT_TRUE( std::string(e.what()).find("Math error: tan(Inf) not determined\n") == 0);
    }
    
    try{
        Ratio<long>::atan(Ratio<long>::Infinite());
    }
    catch( const std::exception &e){
        EXPECT_TRUE( std::string(e.what()).find("Math error: atan(Inf) not determined\n") == 0);
    }

}

TEST (SpecialOperations, absolute) {
    
    ASSERT_EQ(Ratio<long>::abs(-Ratio<long>::Infinite()), Ratio<long>::Infinite());

}

TEST (SpecialOperations, floor) {
    
    ASSERT_EQ(Ratio<long>::floor(Ratio<long>::Infinite()), Ratio<long>::Infinite());
    ASSERT_EQ(Ratio<long>::floor(-Ratio<long>::Infinite()), -Ratio<long>::Infinite());

}

TEST (SpecialOperations, gcrd) {
    
    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_int_distribution<int> uniformIntDistribution(1,(int)maxValue);

    Ratio<long> r2(Ratio<long>::Zero()), r3(Ratio<long>::Infinite());

    ASSERT_EQ(Ratio<long>::gcrd(r2,r2), r2);
    ASSERT_EQ(Ratio<long>::gcrd(r3,r3), r3);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){
        
        // generate random data
        int data1 = uniformIntDistribution(generator);
        int data2 = uniformIntDistribution(generator);
        
        // build the corresponding rational
        Ratio r1((long)data1, (long)data2);
        
        ASSERT_EQ(Ratio<long>::gcrd(r2,r1), r1);
        
        try{
            ASSERT_EQ(Ratio<long>::gcrd(r2,r3), r1);
        }
        catch( const std::exception &e){
            EXPECT_TRUE( std::string(e.what()).find("Math error: trying to find common divisor of a number with infinite\n") == 0);
        }

    }

}

TEST (SpecialOperations, log) {
    
    ASSERT_EQ(Ratio<long>::log(Ratio<long>::Zero()), -Ratio<long>::Infinite());
    ASSERT_EQ(Ratio<long>::log(Ratio<long>::Infinite()), Ratio<long>::Infinite());

    try{
        Ratio<long>::log(-Ratio<long>::Infinite());
    }
    catch( const std::exception &e){
        EXPECT_TRUE( std::string(e.what()).find("Domain error: natural logarithm is defined between ]0; Inf.[\n") == 0);
    }
}

TEST (SpecialOperations, power) {
    
    std::mt19937 generator(0);
    //max value
    const size_t maxValue = 10;
    std::uniform_int_distribution<int> uniformIntDistribution(1,(int)maxValue);

    Ratio<long> r2(Ratio<long>::Zero()), r3(Ratio<long>::Infinite());

    ASSERT_EQ(Ratio<long>::pow(r3,0), 1);

    // run many times the same test with different values
    for(int run=0; run<100; ++run){
        
        // generate random data
        int data1 = uniformIntDistribution(generator);
        
        ASSERT_EQ(Ratio<long>::pow(r2,data1), r2);
        ASSERT_EQ(Ratio<long>::pow(r3,data1), r3);
        ASSERT_EQ(Ratio<long>::pow(r3,-data1), r2);
    
        try{
            Ratio<long>::pow(r2,-data1);
        }
        catch( const std::exception &e){
            EXPECT_TRUE( std::string(e.what()).find("Math error: 0 exponent negative number is impossible\n") == 0);
        }
        
    }
    
}

TEST (SpecialOperations, infiniToReal) {
    
    try{
        Ratio<long>::Infinite().convertRatioToFloat();
    }
    catch( const std::exception &e){
        EXPECT_TRUE( std::string(e.what()).find("Domain error: Infini cannot be converted into float\n") == 0);
    }
}

TEST (SpecialOperations, invert) {
    
    ASSERT_EQ((Ratio<long>::Zero().invert()), Ratio<long>::Infinite());
    ASSERT_EQ((-Ratio<long>::Zero().invert()), -Ratio<long>::Infinite());
    ASSERT_EQ((Ratio<long>::Infinite().invert()), Ratio<long>::Zero());
    ASSERT_EQ((-Ratio<long>::Infinite().invert()), Ratio<long>::Zero());

}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
