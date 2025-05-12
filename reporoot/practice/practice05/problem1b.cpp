#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;
    int input;

    std::cout << "Enter integers (type -1 to stop):\n";

    while (true) {
        std::cin >> input;
        if (input == -1) break;
        numbers.push_back(input);
    }

    std::cout << "Numbers in reverse order:\n";
    for (auto rit = numbers.rbegin(); rit != numbers.rend(); ++rit) {
        std::cout << *rit << " ";
    }

    std::cout << std::endl;
    return 0;
}
