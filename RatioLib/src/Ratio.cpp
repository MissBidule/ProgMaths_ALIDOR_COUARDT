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

Ratio Ratio::operator+(const Ratio &r) const{
    
    
}