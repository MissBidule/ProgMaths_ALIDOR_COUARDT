#include "Ratio.hpp"

Ratio::Ratio(const int & num, const int & denom) : mNum(num), mDenom(denom) {}

Ratio::Ratio(const Ratio & r) : mNum(r.mNum), mDenom(r.mDenom) {}
