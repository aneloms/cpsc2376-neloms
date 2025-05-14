#ifndef NOTIFIER_H
#define NOTIFIER_H

#include "Observer.h"
#include <iostream>

class Notifier : public Observer {
public:
    void update(int grade) override {
        if (grade < 60) {
            std::cout << "Email sent to student@example.com\n";
        }
    }
};

#endif
