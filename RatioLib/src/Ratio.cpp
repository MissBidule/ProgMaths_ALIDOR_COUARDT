#include <stdexcept>
#include <cmath>
#include <numeric>

#include "Ratio.hpp"

//TRIER LES FONCTIONS SVP

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
    else if (ratio == - Ratio::Infinite())
    {
        stream << "-Inf.";
    }
    else if (ratio == Ratio::Zero())
    {
        stream << "0";
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
        float q = fabs(std::floor(number));
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
    if (mNum == 0 || mDenom == 0)
        return *this;
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
Ratio Ratio::operator+(const Ratio &r) const{
    long a = mNum;
    long b = mDenom;
    long c = r.mNum;
    long d = r.mDenom;

    if (b == 0 || d == 0){
        throw std::runtime_error("Math error: Attempted to divide by Zero\n");
    }

    return Ratio(a*d + b*c, b*d).simplify();
}

//Overload * operator
Ratio Ratio::operator*(const Ratio &r) const{
    long a = mNum;
    long b = mDenom;
    long c = r.mNum;
    long d = r.mDenom;

    if (b == 0 || d == 0){
        throw std::runtime_error("Math error: Attempted to divide by Zero\n");
    }

    return Ratio(a*c, b*d).simplify();
}

//Overload * operator (ratio * float)
Ratio Ratio::operator*(const float &f) const{
    return Ratio(mNum*f,mDenom).simplify();

    //seg fault here
    /*Ratio r(mNum,mDenom);
    float ftemp = f * r.convertRatioToFloat();
    Ratio temp = convertFloatToRatio(ftemp,15);
    return temp;*/
}

//float * Ratio
Ratio operator*(const float &f, const Ratio &r){
    return Ratio((r.mNum)*f,r.mDenom).simplify();
}

//Overload - operator
Ratio Ratio::operator-(const Ratio &r) const{
    long a = mNum;
    long b = mDenom;
    long c = r.mNum;
    long d = r.mDenom;

    if (b == 0 || d == 0){
        throw std::runtime_error("Math error: Attempted to divide by Zero\n");
    }

    return Ratio(a*d - b*c, b*d).simplify();
}

//Overload unary minus operator
Ratio Ratio::operator-() const{
    return Ratio(-mNum,mDenom);
}

//Overload / operator
Ratio Ratio::operator/(const Ratio &r) const{
    long a = mNum;
    long b = mDenom;
    long c = r.mNum;
    long d = r.mDenom;

    if (b == 0 || d == 0){
        throw std::runtime_error("Math error: Attempted to divide by Zero\n");
    }

    return Ratio(a*d, b*c).simplify();
}

Ratio Ratio::operator/(const float &f)const{
    Ratio r(mNum,mDenom);

    if (f == 0.0){
        throw std::runtime_error("Math error: Attempted to divide by Zero\n");
    }

    return Ratio((r.convertRatioToFloat())/f); // if (r*(1.0/f)), it would return absolute division
}

//float / Ratio
Ratio operator/(const float &f, const Ratio &r){

    if (r.mNum == 0.0){
        throw std::runtime_error("Math error: Attempted to divide by Zero\n");
    }

    return Ratio((r.mDenom)*f,r.mNum).simplify();
}

//Overload % operator
Ratio Ratio::operator%(const Ratio &r) const{
    long a = mNum;
    long b = mDenom;
    long c = r.mNum;
    long d = r.mDenom;

    if (b == 0 || d == 0){
        throw std::runtime_error("Math error: Attempted to divide by Zero\n");
    }

    return Ratio(((a*d)%(b*c)), b*d).simplify();
}


bool Ratio::operator!=(const Ratio &r) const{
    return (!(*this==r));
}

bool Ratio::operator==(const Ratio &r) const{
    return ((r.mNum == mNum) && (r.mDenom == mDenom));
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


//Comparing Ratio with float//

bool Ratio::operator==(const float &f) const{
    Ratio r(mNum,mDenom);

    return(r.convertRatioToFloat() == f);
}

bool Ratio::operator!=(const float &f) const{
    return (!(*this==f));
}

bool Ratio::operator<(const float &f)const{
    Ratio r(mNum,mDenom);
    
    return(r.convertRatioToFloat() < f);
}

bool Ratio::operator>(const float &f)const{
    Ratio r(mNum,mDenom);
    
    return(r.convertRatioToFloat() > f);
}

bool Ratio::operator<=(const float &f)const{
    return(!(*this>f));
}

bool Ratio::operator>=(const float &f)const{
    return(!(*this<f));
}

//comparing float with Ratio//


bool operator==(const float &f, const Ratio &r){
    return (f == r.convertRatioToFloat());
}

bool operator!=(const float &f, const Ratio &r){
    return (f != r.convertRatioToFloat());
}

bool operator<(const float &f, const Ratio &r){
    return (f < r.convertRatioToFloat());
}

bool operator>(const float &f, const Ratio &r){
    return (f > r.convertRatioToFloat());
}

bool operator<=(const float &f, const Ratio &r){
    return (f <= r.convertRatioToFloat());
}

bool operator>=(const float &f, const Ratio &r){
    return (f >= r.convertRatioToFloat());
}

//Square root of a Rational
Ratio Ratio::sqrt(const Ratio &r){
    float a = r.mNum;
    float b = r.mDenom;
    Ratio result;

    a = std::sqrt(a);
    b = std::sqrt(b);

    //convert the Ratio to float, then the result into a Ratio
    if (((a-std::floor(a)) != 0) || ((b-std::floor(b)) != 0)){
        double temp = r.convertRatioToFloat();
        temp = std::sqrt(temp);
        result = convertFloatToRatio(temp);
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
        result = convertFloatToRatio(std::exp(a/b));
    }

    return result;
}

//Cosinus in degrees
Ratio Ratio::cos(const Ratio &r){
    return Ratio(convertFloatToRatio(std::cos((r.convertRatioToFloat())*M_PI/180.0)));

    
    /*long a = r.mNum;
    long b = r.mDenom;
    int n = 0;
    Ratio unitaire(1,1);
    Ratio divide(1,2);
    Ratio result;
    Ratio Epsilon(1,10000); //threshold

    if (a == 0){
        result.mNum = 1;
        result.mDenom = 1;
    }
    else if (b == 0){
        throw std::runtime_error("Cosinus of infinity");
    }
    else{
        while (r>Epsilon){
                r = r*divide;
                n+=1;
        }
        std::cout << r << std::endl;
        result = unitaire-((r*r)*divide);
        while(n>0){
            result = ((result*result) + (result*result)) - unitaire;
            n-=1;
        }
    }
    return result;*/
}


//Sinus in degrees
Ratio Ratio::sin(const Ratio &r){
    return Ratio(convertFloatToRatio(std::sin((r.convertRatioToFloat())*M_PI/180.0)));
}

//Tangent in degrees
Ratio Ratio::tan(const Ratio &r){
    return Ratio(sin(r)/cos(r));
}

Ratio Ratio::abs(const Ratio &r){
    long a = r.mNum;
    long b = r.mDenom;

    if (a == 0){
        return Zero();
    }
    if (b == 0){
        return Infinite();
    }

    return Ratio(std::labs(a), b);
}

Ratio Ratio::floor(const Ratio &r){
    long a = r.mNum;
    long b = r.mDenom;

    if (a == 0){
        return Zero();
    }
    if (b == 0){
        return Infinite();
    }

    return Ratio(std::floor(r.convertRatioToFloat()), 1);
}

Ratio Ratio::gcrd(const Ratio &r1, const Ratio &r2){
    long a = r1.mNum;
    long b = r1.mDenom;
    long c = r2.mNum;
    long d = r2.mDenom;

    if (a == 0 && c == 0){
        return Zero();
    }
    if (b == 0 && d == 0){
        return Infinite();
    }
    
    return Ratio(std::gcd(a*d,b*c), b*d);
}

Ratio Ratio::log(const Ratio &r){
    long a = r.mNum;
    long b = r.mDenom;

    if (a == 0){
        return -Infinite();
    }
    if (b == 0){
        return Infinite();
    }
    if (r < 0){
        throw std::runtime_error("Domain error: natural logarithm is defined between ]0; Inf.[\n");
    }
    
    return Ratio(convertFloatToRatio((std::log(a))-(std::log(b))));
    
}

Ratio Ratio::pow(const Ratio &r, const long &exponent){
    float a = r.mNum;
    float b = r.mDenom;
    Ratio result;

    if (r == Zero() && exponent < 0){
        return Infinite();
    }
    
    if (exponent < 0){
        result = convertFloatToRatio((std::pow(std::pow((a/b),-exponent),-1)));
    }
    else{
        result = Ratio(std::pow(a,exponent),std::pow(b,exponent)).simplify();
    }

    return result;
}

Ratio Ratio::Zero(){
    return Ratio(0,1);
}

Ratio Ratio::Infinite(){
    return Ratio(1,0);
}
