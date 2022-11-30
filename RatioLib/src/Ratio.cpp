#include <stdexcept>
#include <math.h>
#include <numeric>

#include "Ratio.hpp"

Ratio::Ratio(const int & num, const int & denom) : mNum(num), mDenom(denom) {
    if (denom < 0){ 
        mDenom = -denom;
        mNum = -num;
    }
    simplify();
}

Ratio::Ratio(const float & number) : mNum(0), mDenom(1) {
    Ratio temp(convertFloatToRatio(number));
    mNum = temp.mNum;
    mDenom = temp.mDenom;
}

Ratio::Ratio(const Ratio & r) : mNum(r.mNum), mDenom(r.mDenom) {}

//Overload << operator
std::ostream& operator<< (std::ostream& stream, const Ratio& ratio) {
    if (ratio == Ratio::Infinite()){
        stream << "Inf.";
    }
    else
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

float Ratio::convertRatioToFloat()const {
    if (mDenom == 0)
        throw std::runtime_error("Math error: Attempted to divide by Zero\n");
    return mNum/(float)mDenom;
}

Ratio Ratio::invert() const {
    return Ratio(mDenom*numSign(), abs(mNum));
}

Ratio& Ratio::simplify() {
    if (mNum == 0) mDenom = 1;
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

bool Ratio::operator==(const Ratio &r) const{
    return ((r.mNum == mNum) && (r.mDenom == mDenom));
}

//Overload / operator
Ratio Ratio::operator/(const Ratio &r){
    int a = mNum;
    int b = mDenom;
    int c = r.mNum;
    int d = r.mDenom;

    if (b == 0 || d == 0){
        throw std::overflow_error("Divide by zero exception");
    }

    return Ratio(a*d, b*c);
}

//Overload unary minus operator
Ratio Ratio::operator-(){
    return Ratio(-mNum,mDenom);
}

//Square root of a Rational
Ratio Ratio::sqrt(const Ratio &r){
    double a = r.mNum;
    double b = r.mDenom;
    Ratio result;

    a = std::sqrt(a);
    b = std::sqrt(b);

    //convert the Ratio to float, then the result into a Ratio
    if (((a-std::floor(a)) != 0) || ((b-std::floor(b)) != 0)){
        double temp = r.convertRatioToFloat();
        temp = std::sqrt(temp);
        result = Ratio::convertFloatToRatio(temp);
    }
    else{
        result = Ratio(a,b);
    }

return result;
}

Ratio Ratio::Zero(){
    return Ratio(0,1);
}

Ratio Ratio::Infinite(){
    return Ratio(1,0);
}
