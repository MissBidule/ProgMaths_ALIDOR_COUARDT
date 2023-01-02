//
//  RatioConstructors.hpp
//  Ratio
//
//  Created by MissBidule on 02/01/2023.
//

#ifndef RatioConstructors_h
#define RatioConstructors_h

#include "Ratio.hpp"

template<typename T>
Ratio<T>::Ratio(const T & num, const T & denom, const int & sign) : mNum(std::abs(num)), mDenom(std::abs(denom)), mSign(1){
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

template<typename T>
Ratio<T>::Ratio(const double & number) : mNum(0), mDenom(1) {
    *this = (convertFloatToRatio(number));
}

template<typename T>
Ratio<T>::Ratio(const Ratio<T> & r, const int & sign) : mNum(r.mNum), mDenom(r.mDenom), mSign(r.mSign) {
    //if the sign is filled the ratio will have this as its sign
    if (sign != 0) {
        if (sign > 0)
            mSign = 1;
        else
            mSign = -1;
    }
}


#endif /* RatioConstructors_h */
