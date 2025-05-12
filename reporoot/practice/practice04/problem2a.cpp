#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

template <typename T>
T calculate(T a, T b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : throw std::runtime_error("Division by zero");
        default: throw std::runtime_error("Invalid operator");
    }
}

bool isDouble(const std::string& s) {
    return s.find('.') != std::string::npos;
}

int main() {
    std::string input1, input2;
    char op;

    std::cout << "Enter first number: ";
    std::cin >> input1;

    std::cout << "Enter second number: ";
    std::cin >> input2;

    std::cout << "Enter operation (+, -, *, /): ";
    std::cin >> op;

    try {
        if (isDouble(input1) || isDouble(input2)) {
            double a = std::stod(input1);
            double b = std::stod(input2);
            double result = calculate(a, b, op);
            std::cout << "Result: " << std::fixed << std::setprecision(2) << result << "\n";
        } else {
            int a = std::stoi(input1);
            int b = std::stoi(input2);
            int result = calculate(a, b, op);
            std::cout << "Result: " << result << "\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    return 0;
}
  