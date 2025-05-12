
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> numbers;
    int input;

    std::cout << "Enter integers (type -1 to stop):\n";

    while (true) {
        std::cin >> input;
        if (input == -1) break;
        numbers.push_back(input);
    }

    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);

    int product = std::accumulate(numbers.begin(), numbers.end(), 1, [](int a, int b) {
        return a * b;
    });

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Product: " << product << std::endl;

    return 0;
}
