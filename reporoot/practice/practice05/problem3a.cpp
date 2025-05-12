
#include <iostream>
#include <vector>
#include <algorithm>
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

    std::cout << "Each number squared:\n";

    std::for_each(numbers.begin(), numbers.end(), [](int n) {
        std::cout << n * n << " ";
    });
    std::cout << std::endl;

    int sumOfSquares = std::accumulate(numbers.begin(), numbers.end(), 0, [](int total, int n) {
        return total + (n * n);
    });

    std::cout << "Sum of squares: " << sumOfSquares << std::endl;

    return 0;
}
