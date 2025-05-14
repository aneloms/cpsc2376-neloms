#include <iostream>
#include <memory>
#include "TextFilter.h"
#include "ReverseFilter.h"
#include "UppercaseFilter.h"
#include "VowelRemover.h"
#include "CensorFilter.h"

int main() {
    std::unique_ptr<TextFilter> currentFilter = std::make_unique<ReverseFilter>();

    std::string input;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, input);

    std::cout << "Choose a filter:\n1. Reverse\n2. Uppercase\n3. Remove Vowels\n4. Censor Words\n";
    int choice;
    std::cin >> choice;
    std::cin.ignore();

    switch (choice) {
        case 1: currentFilter = std::make_unique<ReverseFilter>(); break;
        case 2: currentFilter = std::make_unique<UppercaseFilter>(); break;
        case 3: currentFilter = std::make_unique<VowelRemover>(); break;
        case 4: currentFilter = std::make_unique<CensorFilter>(); break;
        default: 
            std::cout << "Invalid option, using default Reverse Filter.\n";
            currentFilter = std::make_unique<ReverseFilter>();
    }

    std::cout << "Filtered sentence: " << currentFilter->apply(input) << "\n";
    return 0;
}
