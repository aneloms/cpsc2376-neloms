#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <vector>
#include "Observer.h"

class GradeBook {
    int grade;
    std::vector<Observer*> observers;
public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void setGrade(int newGrade) {
        grade = newGrade;
        notifyObservers();
    }

    int getGrade() const {
        return grade;
    }

    void notifyObservers() {
        for (auto& observer : observers) {
            observer->update(grade);
        }
    }
};

#endif
