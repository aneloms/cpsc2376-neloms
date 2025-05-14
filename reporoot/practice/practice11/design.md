class Game {
public:
    std::string name;
    int totalCopies;
    int availableCopies;

    Game(std::string name, int total);
    void addCopies(int count);
    bool checkout();
    void returnCopy();
};

class Customer {
public:
    std::string name;

    Customer(std::string name);
};

class Checkout {
public:
    Customer customer;
    Game* game;
    std::string dueDate;

    Checkout(Customer c, Game* g, std::string dueDate);
};
