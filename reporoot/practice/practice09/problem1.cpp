#include <iostream>
#include <string>

int main() {
    float redPotion{0.0f};
    float bluePotion{0.0f};
    float* flask{nullptr};
    std::string choice;

    while (true) {
        std::cout << "Which potion to add to? (Red / Blue / Done): ";
        std::cin >> choice;

        if (choice == "Done") break;

        if (choice == "Red") {
            flask = &redPotion;
        } else if (choice == "Blue") {
            flask = &bluePotion;
        } else {
            std::cout << "Invalid choice. Try again.\n";
            continue;
        }

        float amount;
        std::cout << "How many milliliters to add? ";
        std::cin >> amount;

        *flask += amount;

        std::cout << "Red potion: " << redPotion << " mL, Blue potion: " << bluePotion << " mL\n";
    }

    return 0;
}
