#pragma once

#include <vector>
#include <unordered_map>
#include "car.h"
#include "customer.h"
#include "rental.h"

class RentalService {
private:
    std::vector<Car*> carInventory;
    std::unordered_map<std::string, Rental> activeRentals;
    std::unordered_map<std::string, Customer> customers;

public:
    void addCar(Car* car) ;
    void rentCar(Customer& customer, Car* car, int days); 
    double returnCar(Customer& customer, int extraDays);
    void showInventory(std::ostream& os) const;
    void addCustomer(const Customer& customer);
    int getLoyaltyPoints(const std::string& customerName) const;
    Customer getCustomer(const std::string& customerName) const;
};

