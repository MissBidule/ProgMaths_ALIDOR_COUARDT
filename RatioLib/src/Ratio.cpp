#include <stdexcept>
#include <math.h>
#include <numeric>

#include "Ratio.hpp"

Ratio::Ratio(const int & num, const int & denom) : mNum(num), mDenom(denom) {
    if (denom == 0) mNum = 1;
}

Ratio::Ratio(const float & number) : mNum(0), mDenom(1) {
    Ratio temp(convertFloatToRatio(number));
    mNum = temp.mNum;
    mDenom = temp.mDenom;
}

Ratio::Ratio(const Ratio & r) : mNum(r.mNum), mDenom(r.mDenom) {}

//Overload << operator
std::ostream& operator<< (std::ostream& stream, const Ratio& ratio) {
    stream << ratio.mNum << '/' << ratio.mDenom;
    return stream;
}

Ratio Ratio::convertFloatToRatio(const float & number, unsigned nb_iter) {
    if (number == 0) return Ratio();
    if (nb_iter == 0) return Ratio();
    
    //std::cout << sign(number);
    
    if (fabs(number) < 1) {
        return convertFloatToRatio(1/number, nb_iter).invert();
    }
    
    int q = abs(floor(number));
    return (Ratio(q,1) + convertFloatToRatio(fabs(number)-q, nb_iter-1)) * sign(number);
    
}

float Ratio::convertRatioToFloat() {
    if (mDenom == 0)
        throw std::runtime_error("Math error: Attempted to divide by Zero\n");
    return mNum/(float)mDenom;
}

Ratio Ratio::invert() const {
    return Ratio(mDenom*numSign(), abs(mNum));
}

Ratio& Ratio::simplify() {
    int GCD = std::gcd(mNum, mDenom);
    if (GCD == 1) return *this;
    mNum /= GCD;
    mDenom /= GCD;
    return *this;
}

//Overload + operator
Ratio Ratio::operator+(const Ratio &r){
    int a = mNum;
    int b = mDenom;
    int c = r.mNum;
    int d = r.mDenom;

    if (b == 0 || d == 0){
        throw std::overflow_error("Divide by zero exception");
    }

    return Ratio(a*d + b*c, b*d).simplify();
}

//Overload * operator
Ratio Ratio::operator*(const Ratio &r){
    int a = mNum;
    int b = mDenom;
    int c = r.mNum;
    int d = r.mDenom;

    if (b == 0 || d == 0){
        throw std::overflow_error("Divide by zero exception");
    }

    return Ratio(a*c, b*d).simplify();
}

//Overload * operator (ratio * float)
Ratio Ratio::operator*(const float &f){
    return Ratio(mNum*f,mDenom).simplify();
}

//Overload - operator
Ratio Ratio::operator-(const Ratio &r){
    int a = mNum;
    int b = mDenom;
    int c = r.mNum;
    int d = r.mDenom;

    if (b == 0 || d == 0){
        throw std::overflow_error("Divide by zero exception");
    }

    return Ratio(a*d - b*c, b*d).simplify();
}

//Overload unary minus operator
Ratio Ratio::operator-(){
    return Ratio(mNum,mDenom);
}
