#ifndef AVERAGER_H
#define AVERAGER_H

#include "Observer.h"
#include <iostream>

class Averager : public Observer {
    int totalGrades = 0;
    int numGrades = 0;
public:
    void update(int grade) override {
        totalGrades += grade;
        numGrades++;
        std::cout << "Average grade: " << (totalGrades / numGrades) << "\n";
    }
};

#endif
