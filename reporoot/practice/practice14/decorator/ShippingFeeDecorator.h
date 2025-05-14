#ifndef SHIPPINGFEEDECORATOR_H
#define SHIPPINGFEEDECORATOR_H
#include "Decorator.h"

class ShippingFeeDecorator : public PurchaseDecorator {
public:
    ShippingFeeDecorator(std::shared_ptr<Purchase> purchase) : PurchaseDecorator(purchase) {}
    double getCost() const override {
        return decoratedPurchase->getCost() + 15.0;
    }
};

#endif
