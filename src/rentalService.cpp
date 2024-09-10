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
    customer.addLoyaltyPoints(rental.getLoyaltyPoints());
    activeRentals[customer.getName()] = rental;

    std::cout << customer.getName() << " has rented a" << car->getModel() << " for " << days << " days." << std::endl;
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
