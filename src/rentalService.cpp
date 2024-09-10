#include <string> 
#include <iostream>
#include <vector>
#include <unordered_map>
#include "car.h"
#include "customer.h"
#include "rental.h"
#include "rentalService.h"

void RentalService::addCar(Car* car) {
    carInventory.push_back(car);
}

void RentalService::rentCar(Customer& customer, Car* car, int days) {
    if (activeRentals.find(customer.getName()) != activeRentals.end()) {
        std::cout << "Error: " << customer.getName() << " already has a rented car" << std::endl;
        return;
    }
        
    Rental rental(car, days);

    if (customers.find(customer.getName()) != customers.end())
        customers[customer.getName()].addLoyaltyPoints(rental.getLoyaltyPoints());
    else {
        customers[customer.getName()] = customer;
        customers[customer.getName()].addLoyaltyPoints(rental.getLoyaltyPoints());
    }

    activeRentals[customer.getName()] = rental;

    std::cout << customer.getName() << " has rented a " << car->getModel() << " for " << days << " days." << std::endl;
}


double RentalService::returnCar(Customer& customer, int extraDays) {
    if (activeRentals.find(customer.getName()) == activeRentals.end()) {
        std::cout << "Error: " << customer.getName() << " don't have a car rented!!" << std::endl;
        return -1.0;
    }

    Rental& rental = activeRentals[customer.getName()];

    rental.returnCar(extraDays);
    double totalPrice = rental.calculateTotalPrice();
    
    activeRentals.erase(customer.getName());
    std::cout << customer.getName() << " has returned the car." << std::endl;

    return totalPrice;
}

void RentalService::showInventory(std::ostream& os) const {
    os << "Cars Inventory: " << std::endl;
    for (const auto& car : carInventory) {
        if (car) 
            os << "- " << car->getModel() << std::endl;
    }
}

void RentalService::addCustomer(const Customer& customer) {
    customers[customer.getName()] = customer;
}

int RentalService::getLoyaltyPoints(const std::string& customerName) const {
    auto it = customers.find(customerName);
    if (it != customers.end()) {
        return it->second.getLoyaltyPoints();
    } else {
        std::cout << "Customer " << customerName << " not found!" << std::endl;
        return -1;
    }
}

Customer RentalService::getCustomer(const std::string& customerName) const {
    auto it = customers.find(customerName);
    if (it != customers.end()) {
        return it->second;
    }
    
    throw std::runtime_error("Customer not found");
}