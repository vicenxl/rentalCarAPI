// Customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>  

class Customer {
private:
    std::string name;
    int loyaltyPoints;

public:
    Customer(const std::string& name);
    ~Customer();
    
    void addLoyaltyPoints(int points);
    int getLoyaltyPoints() const;
    std::string getName() const;
};

#endif