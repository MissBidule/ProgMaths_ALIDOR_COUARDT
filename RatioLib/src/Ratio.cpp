#include <stdexcept>
#include <cmath>
#include <numeric>

#include "Ratio.hpp"

//TRIER LES FONCTIONS SVP

Ratio::Ratio(const long & num, const long & denom, const int & sign) : mNum(std::abs(num)), mDenom(std::abs(denom)), mSign(1){
    if ((denom < 0 && num > 0) || (denom > 0 && num < 0)){
        mSign = -1;
    }
    //if the sign is filled the ratio will have this as its sign
    if (sign != 0) {
        if (sign > 0)
            mSign = 1;
        else
            mSign = -1;
    }
    simplify();
}

Ratio::Ratio(const float & number) : mNum(0), mDenom(1) {
    Ratio temp(convertFloatToRatio(number));
    mNum = temp.mNum;
    mDenom = temp.mDenom;
    mSign = temp.mSign;
}

Ratio::Ratio(const Ratio & r, const int & sign) : mNum(r.mNum), mDenom(r.mDenom), mSign(r.mSign) {
    if (sign != 0) {
        if (sign > 0)
            mSign = 1;
        else
            mSign = -1;
    }
}

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
        stream << ratio.signRatio() * (long)ratio.mNum << '/' << ratio.mDenom;
    return stream;
}

Ratio Ratio::convertFloatToRatio(const float & number, unsigned nb_iter) {
    if ((roundf(fabs(number) * 1000) / 1000) == 0 || nb_iter == 0) return Ratio();
    
    if ((roundf(fabs(number) * 1000) / 1000) < 1) {
        return Ratio((convertFloatToRatio(1/fabs(number), nb_iter).invert()),sign(number));
    }
    
    if ((roundf(fabs(number) * 1000) / 1000) > 1) {
        float q = fabs(std::floor(number));
        return Ratio(Ratio(q, (long)1) + convertFloatToRatio(fabs(number)-q, nb_iter-1),sign(number));
    }
    
    return Ratio((long)1, (long)1, sign(number));
}

float Ratio::convertRatioToFloat()const {
    if (mDenom == 0)
        throw std::runtime_error("Math error: Attempted to divide by Zero\n");
    return mNum/(float)mDenom*signRatio();
}

Ratio Ratio::invert() const {
    if (mNum == 0 || mDenom == 0)
        return *this;
    return Ratio(mDenom, mNum, mSign);
}

Ratio& Ratio::simplify() {
    if (mNum == 0) mDenom = 1;
    if (mDenom == 0) mNum = 1;
    long GCD = std::gcd(mNum, mDenom);
    if (GCD == 1) return *this;
    mNum /= GCD;
    mDenom /= GCD;
    return *this;
}

//Overload + operator
Ratio Ratio::operator+(const Ratio &r) const{
    if (mSign != r.mSign)
        return operator-(-r);
    
    long a = mNum;
    long b = mDenom;
    long c = r.mNum;
    long d = r.mDenom;

    if (b == 0 || d == 0){
        return Infinite()*signRatio();
    }

    return Ratio(a*d + b*c, b*d, signRatio()).simplify();
}

//Ratio + float
Ratio Ratio::operator+(const float &f)const {
    return operator+(Ratio(f));
}

//float + Ratio
Ratio operator+(const float &f, const Ratio &r) {
    return r+f;
}

//Ratio - float
Ratio Ratio::operator-(const float &f)const {
    return operator-(Ratio(f));
}

//float - Ratio
Ratio operator-(const float &f, const Ratio &r) {
    return -r+f;
}

//Ratio % float
Ratio Ratio::operator%(const float &f)const {
    return operator%(Ratio(f));
}

//float % Ratio
Ratio operator%(const float &f, const Ratio &r) {
    return Ratio(f)%r;
}

//Overload * operator
Ratio Ratio::operator*(const Ratio &r) const{
    long a = mNum;
    long b = mDenom;
    long c = r.mNum;
    long d = r.mDenom;

    //if one of the term is infinite, the result will be too
//    if (b == 0 || d == 0){
//        throw std::runtime_error("Math error: Attempted to divide by Zero\n");
//    }

    return Ratio(a*c, b*d, mSign*r.signRatio()).simplify();
}

//Overload * operator (ratio * float)
Ratio Ratio::operator*(const float &f) const{
    //return Ratio(mNum*f,mDenom).simplify();

    //seg fault here
    //Ratio r(mNum,mDenom);
    float numTemp = f * mNum * signRatio();
    Ratio temp = convertFloatToRatio(numTemp/(float)mDenom);
    return temp;
}

//float * Ratio
Ratio operator*(const float &f, const Ratio &r){
    return r*f;
}

//Overload - operator
Ratio Ratio::operator-(const Ratio &r) const{
    if (mSign != r.mSign)
        return operator+(-r);
    long a = mNum;
    long b = mDenom;
    long c = r.mNum;
    long d = r.mDenom;
    int sign = mSign;
    
    if (b == 0 && d == 0)
        throw std::runtime_error("Math error: Inf - Inf undetermined\n");
    if (d == 0)
        throw std::runtime_error("Math error: F - Inf impossible\n");
    if (b == 0)
        return Infinite()*mSign;
    
    //in order to make an substraction of 2 differents sign, we use the bigger one to
    if (abs(r)>abs(*this)) {
        long temp = a;
        a = c;
        c = temp;
        
        temp = b;
        b = d;
        d = temp;
        
        sign = -r.mSign;
    }

    return Ratio(a*d - b*c, b*d, sign).simplify();
}

//Overload unary minus operator
Ratio Ratio::operator-() const{
    return Ratio(*this, signRatio()*-1);
}

//Overload / operator
Ratio Ratio::operator/(const Ratio &r) const{

    if (r.mNum == 0){
        throw std::runtime_error("Math error: Attempted to divide by Zero\n");
    }

    return operator*(r.invert());
}

Ratio Ratio::operator/(const float &f)const{
    Ratio r(mNum,mDenom);

    if (f == 0.0){
        throw std::runtime_error("Math error: Attempted to divide by Zero\n");
    }

    return r*(Ratio(f).invert()); // if (r*(1.0/f)), it would return absolute division
}

//float / Ratio
Ratio operator/(const float &f, const Ratio &r){

    if (r.mNum == 0 || r.mDenom == 0){
        throw std::runtime_error("Math error: Attempted to divide by Zero\n");
    }

    return f * r.invert();
}

//Overload % operator
Ratio Ratio::operator%(const Ratio &r) const{
    long a = mNum;
    long b = mDenom;
    long c = r.mNum;
    long d = r.mDenom;

    if (b == 0 || d == 0){
        return *this;
    }

    return Ratio(((a*d)%(b*c)), b*d, mSign).simplify();
}


bool Ratio::operator!=(const Ratio &r) const{
    return (!(*this==r));
}

bool Ratio::operator==(const Ratio &r) const{
    return ((r.mNum == 0 && mNum == 0) || ((r.mNum == mNum) && (r.mDenom == mDenom) && (r.mSign == mSign)));
}

bool Ratio::operator<(const Ratio &r)const{
    long a = mNum * mSign;
    long b = mDenom;
    long c = r.mNum * r.mSign;
    long d = r.mDenom;

    return((a*d)<(b*c));
}

bool Ratio::operator>(const Ratio &r)const{
    long a = mNum * mSign;
    long b = mDenom;
    long c = r.mNum * r.mSign;
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
    return(convertRatioToFloat() == f);
}

bool Ratio::operator!=(const float &f) const{
    return (!(*this==f));
}

bool Ratio::operator<(const float &f)const{
    return(convertRatioToFloat() < f);
}

bool Ratio::operator>(const float &f)const{
    return(convertRatioToFloat() > f);
}

bool Ratio::operator<=(const float &f)const{
    return(!(*this>f));
}

bool Ratio::operator>=(const float &f)const{
    return(!(*this<f));
}

//comparing float with Ratio//


bool operator==(const float &f, const Ratio &r){
    return (r == f);
}

bool operator!=(const float &f, const Ratio &r){
    return (r != f);
}

bool operator<(const float &f, const Ratio &r){
    return (r > f);
}

bool operator>(const float &f, const Ratio &r){
    return (r < f);
}

bool operator<=(const float &f, const Ratio &r){
    return (r >= f);
}

bool operator>=(const float &f, const Ratio &r){
    return (r <= f);
}

//Square root of a Rational
Ratio Ratio::sqrt(const Ratio &r){
    long a = r.mNum;
    long b = r.mDenom;
    Ratio result;
    
    if (r.signRatio() == -1)
        throw std::runtime_error("Math error: Attempted to squared a negative value\n");
    if (b == 0)
        return Infinite();

    a = std::sqrt(a);
    b = std::sqrt(b);

    //convert the Ratio to float, then the result into a Ratio
    if ((((long)a-std::floor(a)) != 0) || (((long)b-std::floor(b)) != 0)){
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
        result = convertFloatToRatio(std::exp((a*r.signRatio())/(float)b));
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

//ArcCos in degrees
Ratio Ratio::acos(const Ratio &r){
    return Ratio(convertFloatToRatio((std::acos(r.convertRatioToFloat()))*180.0/M_PI));
}

//Sinus in degrees
Ratio Ratio::sin(const Ratio &r){
    return Ratio(convertFloatToRatio(std::sin((r.convertRatioToFloat())*M_PI/180.0)));
}

//ArcSin in degrees
Ratio Ratio::asin(const Ratio &r){
    return Ratio(convertFloatToRatio((std::asin(r.convertRatioToFloat()))*180.0/M_PI));
}

//Tangent in degrees
Ratio Ratio::tan(const Ratio &r){
    return Ratio(convertFloatToRatio(std::tan((r.convertRatioToFloat())*M_PI/180.0)));
    //sin/cos precision not enough
    //return Ratio(sin(r)/cos(r));
}

//ArcTan in degrees
Ratio Ratio::atan(const Ratio &r){
    return Ratio(convertFloatToRatio((std::atan(r.convertRatioToFloat()))*180.0/M_PI));
}

Ratio Ratio::abs(const Ratio &r){
    return Ratio(r, 1);
}

Ratio Ratio::floor(const Ratio &r){
    return Ratio((long)std::floor(r.convertRatioToFloat()), (long)1);
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
    if (r.signRatio() == -1){
        throw std::runtime_error("Domain error: natural logarithm is defined between ]0; Inf.[\n");
    }
    
    return Ratio(convertFloatToRatio((std::log(a))-(std::log(b))));
    
}

Ratio Ratio::pow(const Ratio &r, const long &exponent){
    long a = r.mNum;
    long b = r.mDenom;
    Ratio result;

    if (r == Zero() || r == abs(Infinite())) {
        throw std::runtime_error("Math error: Undefined behaviour\n");
    }
    
    if (exponent < 0){
        long temp = a;
        a = b;
        b = temp;
    }
    
    result = Ratio(std::pow(a*r.signRatio(),std::abs(exponent)),std::pow(b,std::abs(exponent))).simplify();
    
    return result;
}

Ratio Ratio::Zero(){
    return Ratio(0,1,1);
}

Ratio Ratio::Infinite(){
    return Ratio(1,0,1);
}
