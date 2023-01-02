//
//  RatioOperators.hpp
//  Ratio

#ifndef RatioOperators_h
#define RatioOperators_h

#include "Ratio.hpp"

template<typename T>
//Overload + operator
Ratio<T> Ratio<T>::operator+(const Ratio<T> &r) const{
    if (mSign != r.mSign)
        return operator-(-r);
    
    T a = mNum;
    T b = mDenom;
    T c = r.mNum;
    T d = r.mDenom;

    if (b == 0 || d == 0){
        return Infinite()*signRatio();
    }

    return Ratio<T>(a*d + b*c, b*d, signRatio()).simplify();
}

template<typename T>
//Ratio + float
Ratio<T> Ratio<T>::operator+(const double &f)const {
    return operator+(Ratio<T>(f));
}

template<typename T>
//float + Ratio
Ratio<T> operator+(const double &f, const Ratio<T> &r) {
    return r+f;
}

template<typename T>
//Overload - operator
Ratio<T> Ratio<T>::operator-(const Ratio<T> &r) const{
    if (mSign != r.mSign)
        return operator+(-r);
    T a = mNum;
    T b = mDenom;
    T c = r.mNum;
    T d = r.mDenom;
    int sign = mSign;
    
    if (b == 0 && d == 0) {
        throw std::runtime_error("Math error: Inf - Inf undetermined\n");
    }
    if (d == 0)
        return Infinite()*-mSign;
    if (b == 0)
        return Infinite()*mSign;
    
    //in order to make an substraction of 2 differents sign, we use the bigger one to
    if (abs(r)>abs(*this)) {
        T temp = a;
        a = c;
        c = temp;
        
        temp = b;
        b = d;
        d = temp;
        
        sign = -r.mSign;
    }

    return Ratio<T>(a*d - b*c, b*d, sign).simplify();
}

template<typename T>
//Ratio - float
Ratio<T> Ratio<T>::operator-(const double &f)const {
    return operator-(Ratio<T>(f));
}

template<typename T>
//float - Ratio
Ratio<T> operator-(const double &f, const Ratio<T> &r) {
    return -r+f;
}

template<typename T>
//Overload unary minus operator
Ratio<T> Ratio<T>::operator-() const{
    return Ratio<T>(*this, signRatio()*-1);
}

template<typename T>
//Overload % operator
Ratio<T> Ratio<T>::operator%(const Ratio<T> &r) const{
    T a = mNum;
    T b = mDenom;
    T c = r.mNum;
    T d = r.mDenom;

    if (b == 0 && d == 0) {
        throw std::runtime_error("Math error: Inf % Inf undetermined\n");
    }
    if (b == 0 || d == 0){
        return *this;
    }

    return Ratio<T>(((a*d)%(b*c)), b*d, mSign).simplify();
}

template<typename T>
//Ratio % float
Ratio<T> Ratio<T>::operator%(const double &f)const {
    return operator%(Ratio(f));
}

template<typename T>
//float % Ratio
Ratio<T> operator%(const double &f, const Ratio<T> &r) {
    return Ratio<T>(f)%r;
}

template<typename T>
//Overload * operator
Ratio<T> Ratio<T>::operator*(const Ratio<T> &r) const{
    T a = mNum;
    T b = mDenom;
    T c = r.mNum;
    T d = r.mDenom;
    
    if ((b == 0 && c == 0) || (a == 0 && d == 0)) {
        throw std::runtime_error("Math error: Inf x 0 undetermined\n");
    }
    
    //if one of the term is infinite, the result will be too
//    if (b == 0 || d == 0){
//        throw std::runtime_error("Math error: Attempted to divide by Zero\n");
//    }

    return Ratio<T>(a*c, b*d, mSign*r.signRatio()).simplify();
}

template<typename T>
//Overload * operator (ratio * float)
Ratio<T> Ratio<T>::operator*(const double &f) const{
    //return Ratio(mNum*f,mDenom).simplify();

    //seg fault here
    //Ratio r(mNum,mDenom);
    if (mDenom == 0)
        return Ratio<T>(Infinite(), sign(f)*mSign);
    
    float numTemp = f * mNum * signRatio();
    Ratio<T> temp = convertFloatToRatio(numTemp/(float)mDenom);
    return temp;
}

template<typename T>
//float * Ratio
Ratio<T> operator*(const float &f, const Ratio<T> &r){
    return r*f;
}

template<typename T>
//double * Ratio
Ratio<T> operator*(const double &f, const Ratio<T> &r){
    return r*f;
}

template<typename T>
//Overload / operator
Ratio<T> Ratio<T>::operator/(const Ratio<T> &r) const{

    if (r.mNum == 0){
        throw std::runtime_error("Math error: Attempted to divide by Zero\n");
    }
    
    if (mDenom == 0 && r.mDenom == 0) {
        throw std::runtime_error("Math error: Inf / Inf undetermined\n");
    }

    return operator*(r.invert());
}

template<typename T>
Ratio<T> Ratio<T>::operator/(const double &f)const{

    if (f == 0.0){
        throw std::runtime_error("Math error: Attempted to divide by Zero\n");
    }

    return (*this)*(Ratio(f).invert()); // if (r*(1.0/f)), it would return absolute division
}

template<typename T>
//double / Ratio
Ratio<T> operator/(const double &f, const Ratio<T> &r){

    if (r.mNum == 0 || r.mDenom == 0){
        throw std::runtime_error("Math error: Attempted to divide by Zero\n");
    }

    return f * r.invert();
}

template<typename T>
bool Ratio<T>::operator==(const Ratio<T> &r) const{
    return ((r.mNum == 0 && mNum == 0) || ((r.mNum == mNum) && (r.mDenom == mDenom) && (r.mSign == mSign)));
}

template<typename T>
bool Ratio<T>::operator!=(const Ratio<T> &r) const{
    return (!(*this==r));
}

template<typename T>
bool Ratio<T>::operator<(const Ratio<T> &r)const{
    if (r == Infinite() && *this != Infinite())
        return true;
    if (*this == -Infinite() && r != -Infinite())
        return true;
    
    T a = mNum * mSign;
    T b = mDenom;
    T c = r.mNum * r.mSign;
    T d = r.mDenom;

    return((a*d)<(b*c));
}

template<typename T>
bool Ratio<T>::operator>(const Ratio<T> &r)const{
    if (r == -Infinite() && *this != -Infinite())
        return true;
    if (*this == Infinite() && r != Infinite())
        return true;
    
    T a = mNum * mSign;
    T b = mDenom;
    T c = r.mNum * r.mSign;
    T d = r.mDenom;

    return((a*d)>(b*c));
}

template<typename T>
bool Ratio<T>::operator<=(const Ratio<T> &r)const{
    return(!(*this>r));
}

template<typename T>
bool Ratio<T>::operator>=(const Ratio<T> &r)const{
    return(!(*this<r));
}

//Comparing Ratio with float//
template<typename T>
bool Ratio<T>::operator==(const double &f) const{
    if (abs(*this) == Infinite())
        return false;
    return(convertRatioToFloat() == f);
}

template<typename T>
bool Ratio<T>::operator!=(const double &f) const{
    return (!(*this==f));
}

template<typename T>
bool Ratio<T>::operator<(const double &f)const{
    if (abs(*this) == Infinite())
        return (*this ==-Infinite());
    return(convertRatioToFloat() < f);
}

template<typename T>
bool Ratio<T>::operator>(const double &f)const{
    if (abs(*this) == Infinite())
        return (*this == Infinite());
    return(convertRatioToFloat() > f);
}

template<typename T>
bool Ratio<T>::operator<=(const double &f)const{
    return(!(*this>f));
}

template<typename T>
bool Ratio<T>::operator>=(const double &f)const{
    return(!(*this<f));
}

//comparing float with Ratio//

template<typename T>
bool operator==(const double &f, const Ratio<T> &r){
    return (r == f);
}

template<typename T>
bool operator!=(const double &f, const Ratio<T> &r){
    return (r != f);
}

template<typename T>
bool operator<(const double &f, const Ratio<T> &r){
    return (r > f);
}

template<typename T>
bool operator>(const double &f, const Ratio<T> &r){
    return (r < f);
}

template<typename T>
bool operator<=(const double &f, const Ratio<T> &r){
    return (r >= f);
}

template<typename T>
bool operator>=(const double &f, const Ratio<T> &r){
    return (r <= f);
}

template<typename T>
//Overload << operator
std::ostream& operator<< (std::ostream& stream, const Ratio<T>& ratio) {
    if (ratio == Ratio<T>::Infinite()){
        stream << "Inf.";
    }
    else if (ratio == - Ratio<T>::Infinite())
    {
        stream << "-Inf.";
    }
    else if (ratio == 0)
    {
        stream << "0";
    }
    else
        stream << ratio.signRatio() * (T)ratio.mNum << '/' << ratio.mDenom;
    return stream;
}


#endif /* RatioOperators_h */
