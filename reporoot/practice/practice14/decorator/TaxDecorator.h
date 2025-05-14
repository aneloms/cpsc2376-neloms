#ifndef TAXDECORATOR_H
#define TAXDECORATOR_H
#include "Decorator.h"

class TaxDecorator : public PurchaseDecorator {
public:
    TaxDecorator(std::shared_ptr<Purchase> purchase) : PurchaseDecorator(purchase) {}
    double getCost() const override {
        return decoratedPurchase->getCost() * 1.10;  
    }
};

#endif
