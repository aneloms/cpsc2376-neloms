#ifndef VOWELREMOVER_H
#define VOWELREMOVER_H
#include "TextFilter.h"
#include <string>

class VowelRemover : public TextFilter {
public:
    std::string apply(const std::string& input) override {
        std::string noVowels = input;
        noVowels.erase(std::remove_if(noVowels.begin(), noVowels.end(), 
            [](char c) { return std::string("aeiouAEIOU").find(c) != std::string::npos; }), noVowels.end());
        return noVowels;
    }
};

#endif
