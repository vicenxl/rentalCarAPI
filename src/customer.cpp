#include "customer.h"

Customer::Customer(const std::string& name) : name(name), loyaltyPoints(0) {}

Customer::~Customer() {}

void Customer::addLoyaltyPoints(int points) {
        loyaltyPoints += points;
}

int Customer::getLoyaltyPoints() const {
        return loyaltyPoints;
}

std::string Customer::getName() const {
        return name;
}

