#ifndef CENSORFILTER_H
#define CENSORFILTER_H
#include "TextFilter.h"
#include <string>

class CensorFilter : public TextFilter {
public:
    std::string apply(const std::string& input) override {
        std::string censored = input;
        size_t pos = censored.find("badword");
        while (pos != std::string::npos) {
            censored.replace(pos, 7, "*****");
            pos = censored.find("badword", pos + 5);
        }
        return censored;
    }
};

#endif
