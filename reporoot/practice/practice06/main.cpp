#include <iostream>
#include "Fraction.h"
#include "MixedFraction.h"

void showMenu() {
    std::cout << "\nOptions:\n"
              << "1. Enter a fraction manually\n"
              << "2. Add a fraction\n"
              << "3. Subtract a fraction\n"
              << "4. Multiply by a fraction\n"
              << "5. Divide by a fraction\n"
              << "6. Display as Mixed Fraction\n"
              << "7. Clear Fraction\n"
              << "8. Exit\n";
}

Fraction inputFraction() {
    int n, d;
    std::cout << "Enter numerator: ";
    std::cin >> n;
    std::cout << "Enter denominator: ";
    std::cin >> d;
    return Fraction(n, d);
}

int main() {
    Fraction current;
    int choice;
    bool running = true;

    while (running) {
        std::cout << "\nCurrent Fraction: " << current << '\n';
        showMenu();
        std::cout << "Choose an option: ";
        std::cin >> choice;

        try {
            switch (choice) {
                case 1:
                    current = inputFraction();
                    break;
                case 2:
                    current = current + inputFraction();
                    break;
                case 3:
                    current = current - inputFraction();
                    break;
                case 4:
                    current = current * inputFraction();
                    break;
                case 5:
                    current = current / inputFraction();
                    break;
                case 6: {
                    MixedFraction mf(current);
                    std::cout << "Mixed Fraction: " << mf << '\n';
                    break;
                }
                case 7:
                    current = Fraction();
                    break;
                case 8:
                    running = false;
                    break;
                default:
                    std::cout << "Invalid option.\n";
            }
        } catch (std::exception& e) {
            std::cout << "Error: " << e.what() << '\n';
        }
    }
    return 0;
}
