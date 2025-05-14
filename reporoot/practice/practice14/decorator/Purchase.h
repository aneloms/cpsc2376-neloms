#ifndef PURCHASE_H
#define PURCHASE_H

class Purchase {
public:
    virtual ~Purchase() = default;
    virtual double getCost() const = 0;
};

#endif
