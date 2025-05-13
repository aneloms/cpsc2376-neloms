#include "MixedFraction.h"

MixedFraction::MixedFraction(int whole, int n, int d)
    : Fraction(whole * d + n, d) {}

MixedFraction::MixedFraction(const Fraction& f)
    : Fraction(f) {}

std::ostream& operator<<(std::ostream& os, const MixedFraction& mf) {
    int whole = mf.getNumerator() / mf.getDenominator();
    int remainder = abs(mf.getNumerator() % mf.getDenominator());
    if (whole != 0) {
        os << whole;
        if (remainder != 0) os << ' ' << remainder << '/' << mf.getDenominator();
    } else {
        os << mf.getNumerator() << '/' << mf.getDenominator();
    }
    return os;
}
