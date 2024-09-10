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


void RentalService::returnCar(Customer& customer, int extraDays) {
    if (activeRentals.find(customer.getName()) == activeRentals.end()) {
        std::cout << "Error: " << customer.getName() << " don't have car rented!!" << std::endl;
        return;
    }

    Rental& rental = activeRentals[customer.getName()];
    rental.returnCar(extraDays);

    double surcharge = rental.calculateTotalPrice();
    std::cout << "The surcharge for extra days is: " << surcharge << " €" << std::endl;

    activeRentals.erase(customer.getName());
    std::cout << customer.getName() << " has returned the car." << std::endl;
}

void RentalService::showInventory() const {
    std::cout << "Cars Inventory: " << std::endl;
    for (const auto& car : carInventory) 
        std::cout << "- " << car->getModel() << std::endl;
}
