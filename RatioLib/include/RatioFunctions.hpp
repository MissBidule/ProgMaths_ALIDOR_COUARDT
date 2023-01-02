//
//  RatioFunctions.hpp
//  Ratio
//
//  Created by MissBidule on 02/01/2023.
//

#ifndef RatioFunctions_h
#define RatioFunctions_h

#include <numeric>

#include "Ratio.hpp"

template<typename T>
//Square root of a Rational
Ratio<T> Ratio<T>::sqrt(const Ratio<T> &r){
    T a = r.mNum;
    T b = r.mDenom;
    Ratio<T> result;

    if (r.signRatio() == -1)
        throw std::runtime_error("Math error: Attempted to squared a negative value\n");
    if (b == 0)
        return Infinite();

    a = std::sqrt(a);
    b = std::sqrt(b);

    //convert the Ratio to float, then the result into a Ratio
    if ((((T)a-std::floor(a)) != 0) || (((T)b-std::floor(b)) != 0)){
        double temp = r.convertRatioToFloat();
        temp = std::sqrt(temp);
        result = convertFloatToRatio(temp);
    }
    else{
        result = Ratio<T>(a,b);
    }

    return result;
}

template<typename T>
Ratio<T> Ratio<T>::exp(const Ratio<T> &r){
    T a = r.mNum;
    T b = r.mDenom;
    Ratio<T> result;

    if(a == 0){
        result.mNum = 1;
        result.mDenom = 1;
    }
    else if (r == Infinite()){
        result = Infinite();
    }
    else if (r == -Infinite()){
        result = Zero();
    }
    else{
        result = convertFloatToRatio(std::exp((a*r.signRatio())/(float)b));
    }

    return result;
}

template<typename T>
//Cosinus in degrees
Ratio<T> Ratio<T>::cos(const Ratio<T> &r){

    if (abs(r) == Infinite()) {
        throw std::runtime_error("Math error: cos(Inf) not determined\n");
    }

    return Ratio<T>(convertFloatToRatio(std::cos((r.convertRatioToFloat())*M_PI/180.0)));

    //our first lead didn't work
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

template<typename T>
//ArcCos in degrees
Ratio<T> Ratio<T>::acos(const Ratio<T> &r){

    if (abs(r) == Infinite()) {
        throw std::runtime_error("Math error: acos(Inf) not determined\n");
    }

    return Ratio<T>(convertFloatToRatio((std::acos(r.convertRatioToFloat()))*180.0/M_PI));
}

template<typename T>
//Sinus in degrees
Ratio<T> Ratio<T>::sin(const Ratio<T> &r){

    if (abs(r) == Infinite()) {
        throw std::runtime_error("Math error: sin(Inf) not determined\n");
    }

    return Ratio<T>(convertFloatToRatio(std::sin((r.convertRatioToFloat())*M_PI/180.0)));
}

template<typename T>
//ArcSin in degrees
Ratio<T> Ratio<T>::asin(const Ratio<T> &r){

    if (abs(r) == Infinite()) {
        throw std::runtime_error("Math error: asin(Inf) not determined\n");
    }

    return Ratio<T>(convertFloatToRatio((std::asin(r.convertRatioToFloat()))*180.0/M_PI));
}

template<typename T>
//Tangent in degrees
Ratio<T> Ratio<T>::tan(const Ratio<T> &r){

    if (abs(r) == Infinite()) {
        throw std::runtime_error("Math error: tan(Inf) not determined\n");
    }

    return Ratio<T>(convertFloatToRatio(std::tan((r.convertRatioToFloat())*M_PI/180.0)));
    //sin/cos precision not enough
    //return Ratio(sin(r)/cos(r));
}

template<typename T>
//ArcTan in degrees
Ratio<T> Ratio<T>::atan(const Ratio<T> &r){

    if (abs(r) == Infinite()) {
        throw std::runtime_error("Math error: atan(Inf) not determined\n");
    }

    return Ratio<T>(convertFloatToRatio((std::atan(r.convertRatioToFloat()))*180.0/M_PI));
}

template<typename T>
Ratio<T> Ratio<T>::abs(const Ratio<T> &r){
    if (r.getDenom() == 0)
        return Infinite();
    return Ratio<T>(r, 1);
}

template<typename T>
Ratio<T> Ratio<T>::floor(const Ratio<T> &r){
    if (abs(r) == Infinite())
        return r;
    return Ratio<T>((T)std::floor(r.convertRatioToFloat()), (T)1);
}

template<typename T>
Ratio<T> Ratio<T>::gcrd(const Ratio<T> &r1, const Ratio<T> &r2){
    T a = r1.mNum;
    T b = r1.mDenom;
    T c = r2.mNum;
    T d = r2.mDenom;

    if (a == 0 && c == 0){
        return Zero();
    }
    if (b == 0 && d == 0){
        return Infinite();
    }
    if (b==0 || d == 0)
        throw std::runtime_error("Math error: trying to find common divisor of a number with infinite\n");

    return Ratio<T>(std::gcd(a*d,b*c), b*d);
}

template<typename T>
Ratio<T> Ratio<T>::log(const Ratio<T> &r){
    T a = r.mNum;
    T b = r.mDenom;

    if (a == 0){
        return -Infinite();
    }
    if (b == 0){
        return Infinite();
    }
    if (r.signRatio() == -1){
        throw std::runtime_error("Domain error: natural logarithm is defined between ]0; Inf.[\n");
    }

    return Ratio<T>(convertFloatToRatio((std::log(a))-(std::log(b))));

}

template<typename T>
Ratio<T> Ratio<T>::pow(const Ratio<T> &r, const long &exponent){
    T a = r.mNum;
    T b = r.mDenom;

    if (exponent < 0){
        if (r == 0)
            throw std::runtime_error("Math error: 0 exponent negative number is impossible\n");
        T temp = a;
        a = b;
        b = temp;
    }

    return Ratio<T>(std::pow(a*r.signRatio(),std::abs(exponent)),std::pow(b,std::abs(exponent))).simplify();
}

template<typename T>
Ratio<T> Ratio<T>::Zero(){
    return Ratio<T>(0,1,1);
}

template<typename T>
Ratio<T> Ratio<T>::Infinite(){
    return Ratio<T>(1,0,1);
}

template<typename T>
Ratio<T> Ratio<T>::convertFloatToRatio(const double & number, unsigned nb_iter) {
    if ((roundf(std::fabs((double)number) * 1000) / 1000) == 0 || nb_iter == 0) return Ratio<T>();

    if ((roundf(std::fabs((double)number) * 1000) / 1000) < 1) {
        return Ratio<T>((convertFloatToRatio(1/std::fabs((double)number), nb_iter).invert()),sign(number));
    }

    if ((roundf(std::fabs((double)number) * 1000) / 1000) > 1) {
        float q = fabs(std::floor((double)number));
        return Ratio<T>(Ratio<T>(q, (T)1) + convertFloatToRatio(std::fabs((double)number)-q, nb_iter-1),sign(number));
    }

    return Ratio<T>((T)1, (T)1, sign(number));
}

template<typename T>
auto Ratio<T>::convertRatioToFloat()const {
    if (mDenom == 0)
        throw std::runtime_error("Domain error: Infini cannot be converted into float\n");
    return mNum/(float)mDenom*signRatio();
}

template<typename T>
Ratio<T>& Ratio<T>::simplify() {
    if (mNum == 0) mDenom = 1;
    if (mDenom == 0) mNum = 1;
    T GCD = std::gcd(mNum, mDenom);
    if (GCD == 1 || GCD == 0) return *this;
    mNum /= GCD;
    mDenom /= GCD;
    return *this;
}

template<typename T>
Ratio<T> Ratio<T>::invert() const {
    return Ratio<T>(mDenom, mNum, mSign);
}

#endif /* RatioFunctions_h */
