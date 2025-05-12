#include <iostream>
#include <deque>
#include <string>

void showMenu() {
    std::cout << "\n1. Add Text\n";
    std::cout << "2. Undo Last Edit\n";
    std::cout << "3. Show Content\n";
    std::cout << "4. Exit\n";
    std::cout << "Choice: ";
}

int main() {
    std::deque<std::string> edits;
    std::string input;
    int choice;

    do {
        showMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {
                std::cout << "Enter text: ";
                std::getline(std::cin, input);
                edits.push_back(input);
                break;
            }
            case 2: {
                if (!edits.empty()) {
                    edits.pop_back();
                    std::cout << "Undo successful!\n";
                } else {
                    std::cout << "Nothing to undo!\n";
                }
                break;
            }
            case 3: {
                std::cout << "Current Content: ";
                for (const auto& text : edits) {
                    std::cout << text << " ";
                }
                std::cout << "\n";
                break;
            }
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
