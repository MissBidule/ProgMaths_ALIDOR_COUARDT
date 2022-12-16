#include <stdexcept>
#include <cmath>
#include <numeric>

#include "Ratio.hpp"

Ratio::Ratio(const long & num, const long & denom) : mNum(num), mDenom(denom) {
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
    if (number == 0 || nb_iter == 0) return Ratio();
    
    if (fabs(number) < 1) {
        return (convertFloatToRatio(1/fabs(number), nb_iter).invert()) * sign(number);
    }
    
    if (fabs(number) > 1) {
        float q = fabs(floor(number));
        return (Ratio(q,1) + convertFloatToRatio(fabs(number)-q, nb_iter-1)) * sign(number);
    }
    
    return Ratio((long)1) * sign(number);
}

float Ratio::convertRatioToFloat()const {
    if (mDenom == 0)
        throw std::runtime_error("Math error: Attempted to divide by Zero\n");
    return mNum/(float)mDenom;
}

Ratio Ratio::invert() const {
    return Ratio(mDenom*signRatio(), std::abs(mNum));
}

Ratio& Ratio::simplify() {
    if (mNum == 0) mDenom = 1;
    long GCD = std::gcd(mNum, mDenom);
    if (GCD == 1) return *this;
    mNum /= GCD;
    mDenom /= GCD;
    return *this;
}

//Overload + operator
Ratio Ratio::operator+(const Ratio &r){
    long a = mNum;
    long b = mDenom;
    long c = r.mNum;
    long d = r.mDenom;

    if (b == 0 || d == 0){
        throw std::overflow_error("Divide by zero exception");
    }

    return Ratio(a*d + b*c, b*d).simplify();
}

//Overload * operator
Ratio Ratio::operator*(const Ratio &r){
    long a = mNum;
    long b = mDenom;
    long c = r.mNum;
    long d = r.mDenom;

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
    long a = mNum;
    long b = mDenom;
    long c = r.mNum;
    long d = r.mDenom;

    if (b == 0 || d == 0){
        throw std::overflow_error("Divide by zero exception");
    }

    return Ratio(a*d - b*c, b*d).simplify();
}

bool Ratio::operator!=(const Ratio &r) const{
    return (!(*this==r));
}

bool Ratio::operator==(const Ratio &r) const{
    return ((r.mNum == mNum) && (r.mDenom == mDenom));
}

//Overload / operator
Ratio Ratio::operator/(const Ratio &r){
    long a = mNum;
    long b = mDenom;
    long c = r.mNum;
    long d = r.mDenom;

    if (b == 0 || d == 0){
        throw std::overflow_error("Divide by zero exception");
    }

    return Ratio(a*d, b*c);
}

//Overload unary minus operator
Ratio Ratio::operator-(){
    return Ratio(-mNum,mDenom);
}

bool Ratio::operator<(const Ratio &r)const{
    long a = mNum;
    long b = mDenom;
    long c = r.mNum;
    long d = r.mDenom;

    return((a*d)<(b*c));
}

bool Ratio::operator>(const Ratio &r)const{
    long a = mNum;
    long b = mDenom;
    long c = r.mNum;
    long d = r.mDenom;

    return((a*d)>(b*c));
}

bool Ratio::operator<=(const Ratio &r)const{
    return(!(*this>r));
}

bool Ratio::operator>=(const Ratio &r)const{
    return(!(*this<r));
}

//Square root of a Rational
Ratio Ratio::sqrt(const Ratio &r){
    long a = r.mNum;
    long b = r.mDenom;
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

Ratio Ratio::exp(const Ratio &r){
    long a = r.mNum;
    long b = r.mDenom;
    Ratio result;

    if(a == 0){
        result.mNum = 1;
        result.mDenom = 1;
    }
    else if(b == 0){
        result = Infinite();
    }
    else{
        result = convertFloatToRatio(std::pow(std::exp(1/b),a));
    }

return result;
}

Ratio Ratio::cos(const Ratio &r){
    long a = r.mNum;
    long b = r.mDenom;
    Ratio result;
    Ratio Epsilon(1,10000);

    if (a == 0){
        result.mNum = 1;
        result.mDenom = 1;
    }
    else if (b == 0){
        throw std::runtime_error("Cosinus of infinity");
    }
    else{
        //if (r < Epsilon)
    }
return result;
}

Ratio Ratio::Zero(){
    return Ratio(0,1);
}

Ratio Ratio::Infinite(){
    return Ratio(1,0);
}
