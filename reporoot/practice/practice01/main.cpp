#include <iostream>
#include <vector>

void printVector(const std::vector<int>& vec) {
    std::cout << "Vector elements: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec.at(i) << " ";
    }
    std::cout << std::endl;
}

void doubleVector(std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        vec.at(i) *= 2;
    }
}

int calculateSum(const std::vector<int>& vec) {
    int sum = 0;
    for (size_t i = 0; i < vec.size(); i++) {
        sum += vec.at(i);
    }
    return sum;
}

void printMultiples(const std::vector<int>& vec, int multiple) {
    std::cout << "Multiples of " << multiple << ": ";
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec.at(i) % multiple == 0) {
            std::cout << vec.at(i) << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> numbers;
    int choice, value;

    do {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Add an item to the vector" << std::endl;
        std::cout << "2. Print the vector" << std::endl;
        std::cout << "3. Double the vector" << std::endl;
        std::cout << "4. Find the sum" << std::endl;
        std::cout << "5. Print multiples of a user-defined value" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter a number: ";
                std::cin >> value;
                numbers.push_back(value);
                break;
            case 2:
                printVector(numbers);
                break;
            case 3:
                doubleVector(numbers);
                std::cout << "Vector doubled." << std::endl;
                break;
            case 4:
                std::cout << "Sum of elements: " << calculateSum(numbers) << std::endl;
                break;
            case 5:
                std::cout << "Enter a number: ";
                std::cin >> value;
                printMultiples(numbers, value);
                break;
            case 6:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != 6);
    
    return 0;
}
