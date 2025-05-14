#include <iostream>
#include "Purchase.h"
#include "SimplePurchase.h"
#include "TaxDecorator.h"
#include "ShippingFeeDecorator.h"
#include "DiscountDecorator.h"

int main() {
    std::shared_ptr<Purchase> purchase = std::make_shared<SimplePurchase>(100.0);

    char choice;
    std::cout << "Would you like to add tax? (y/n): ";
    std::cin >> choice;
    if (choice == 'y') {
        purchase = std::make_shared<TaxDecorator>(purchase);
    }

    std::cout << "Would you like to add shipping fee? (y/n): ";
    std::cin >> choice;
    if (choice == 'y') {
        purchase = std::make_shared<ShippingFeeDecorator>(purchase);
    }

    std::cout << "Would you like to apply a discount? (y/n): ";
    std::cin >> choice;
    if (choice == 'y') {
        purchase = std::make_shared<DiscountDecorator>(purchase);
    }

    std::cout << "Final cost: " << purchase->getCost() << "\n";
    return 0;
}
