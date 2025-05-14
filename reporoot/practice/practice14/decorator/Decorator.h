#ifndef DECORATOR_H
#define DECORATOR_H
#include "Purchase.h"
#include <memory>

class PurchaseDecorator : public Purchase {
protected:
    std::shared_ptr<Purchase> decoratedPurchase;
public:
    PurchaseDecorator(std::shared_ptr<Purchase> purchase) : decoratedPurchase(purchase) {}
    virtual double getCost() const = 0;
};

#endif
