#ifndef UPPERCASEFILTER_H
#define UPPERCASEFILTER_H
#include "TextFilter.h"
#include <algorithm>

class UppercaseFilter : public TextFilter {
public:
    std::string apply(const std::string& input) override {
        std::string upper = input;
        std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
        return upper;
    }
};

#endif
