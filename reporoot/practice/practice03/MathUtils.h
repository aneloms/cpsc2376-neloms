#include "MathUtils.h"
#include <climits>

int MathUtils::sumRange(int start, int end) {
    int sum = 0;
    for (int i = start; i < end; i++) {
        sum += i;
    }
    return sum;
}

bool MathUtils::containsNegative(const std::vector<int>& numbers) {
    for (size_t i = 0; i < numbers.size(); i++) {
        if (numbers[i] < 0) {
            return true;
        }
    }
    return false;
}

int MathUtils::findMax(const std::vector<int>& numbers) {
    if (numbers.empty()) return INT_MIN;
    int maxVal = numbers[0];
    for (size_t i = 1; i < numbers.size(); i++) { 
        if (numbers[i] > maxVal) {
            maxVal = numbers[i];
        }
    }
    return maxVal;
}
