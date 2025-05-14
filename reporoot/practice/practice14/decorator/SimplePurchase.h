#ifndef SIMPLEPURCHASE_H
#define SIMPLEPURCHASE_H
#include "Purchase.h"

class SimplePurchase : public Purchase {
    double cost;
public:
    SimplePurchase(double c) : cost(c) {}
    double getCost() const override {
        return cost;
    }
};

#endif
