#include <string> 
#include <iostream>
#include <vector>
#include <unordered_map>
#include "car.h"
#include "customer.h"
#include "rental.h"

class RentalService {
private:
    std::vector<Car*> carInventory;
    std::unordered_map<std::string, Rental> activeRentals;

public:
    void addCar(Car* car) {
        carInventory.push_back(car);
    }

    void rentCar(Customer& customer, Car* car, int days) {
        Rental rental(car, days);
        customer.addLoyaltyPoints(rental.getLoyaltyPoints());
        activeRentals[customer.getName()] = rental;
    }

    void returnCar(Customer& customer, int extraDays) {
        Rental& rental = activeRentals[customer.getName()];
        rental.returnCar(extraDays);
        double surcharge = rental.calculateTotalPrice();
        std::cout << "Surcharge for extra days: " << surcharge << " €" << std::endl;
    }
};
