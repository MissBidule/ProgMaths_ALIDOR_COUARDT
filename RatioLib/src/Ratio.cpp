#include "Ratio.hpp"

Ratio::Ratio(const int & num, const int & denom) : mNum(num), mDenom(denom) {}

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

//Overload + operator
Ratio Ratio::operator+(const Ratio &r){
    int a = mNum;
    int b = mDenom;
    int c = r.mNum;
    int d = r.mDenom;

    if (b == 0 || d == 0){
        throw std::overflow_error("Divide by zero exception");
    }

    return Ratio(a*d + b*c, b*d);
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

    return Ratio(a*c, b*d);
}

//Overload * operator (ratio * float)
Ratio Ratio::operator*(const float &f){
    return Ratio(mNum*f,mDenom);
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

    return Ratio(a*d - b*c, b*d);
}

//Overload unary minus operator
Ratio Ratio::operator-(){
    return Ratio(mNum,mDenom);
}

Ratio Ratio::convertFloatToRatio(const float & number, const unsigned & nb_iter){ return Ratio();}