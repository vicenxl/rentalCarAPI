#include "customer.h"

class Customer {
private:
    std::string name;
    int loyaltyPoints;

public:
    Customer(const std::string& name) : name(name), loyaltyPoints(0) {}

    Customer::~Customer() {}

    void addLoyaltyPoints(int points) {
        loyaltyPoints += points;
    }

    int getLoyaltyPoints() const {
        return loyaltyPoints;
    }

    std::string getName() const {
        return name;
    }
};
