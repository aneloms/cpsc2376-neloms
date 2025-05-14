#ifndef DISCOUNTDECORATOR_H
#define DISCOUNTDECORATOR_H
#include "Decorator.h"

class DiscountDecorator : public PurchaseDecorator {
public:
    DiscountDecorator(std::shared_ptr<Purchase> purchase) : PurchaseDecorator(purchase) {}
    double getCost() const override {
        return decoratedPurchase->getCost() * 0.90;
    }
};

#endif
