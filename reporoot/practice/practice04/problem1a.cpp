#include <iostream>
#include <iomanip>

double convertTemperature(double temp, char scale = 'F') {
    if (scale == 'F') {

        return (temp * 9.0 / 5.0) + 32;
    } else {

        return (temp - 32) * 5.0 / 9.0;
    }
}

int main() {
    int choice;
    double inputTemp, result;
    
    std::cout << "1. Convert Celsius to Fahrenheit\n";
    std::cout << "2. Convert Fahrenheit to Celsius\n";
    std::cout << "Choose an option: ";
    std::cin >> choice;

    if (choice != 1 && choice != 2) {
        std::cout << "Invalid choice.\n";
        return 1;
    }

    std::cout << "Enter temperature: ";
    std::cin >> inputTemp;

    if (choice == 1) {
        result = convertTemperature(inputTemp, 'F');
        std::cout << "Converted: " << std::fixed << std::setprecision(2) << result << "°F\n";
    } else {
        result = convertTemperature(inputTemp, 'C');
        std::cout << "Converted: " << std::fixed << std::setprecision(2) << result << "°C\n";
    }

    return 0;
}
