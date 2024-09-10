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

public:
    void addCar(Car* car) ;
    void rentCar(Customer& customer, Car* car, int days); 
    double returnCar(Customer& customer, int extraDays);
    void showInventory(std::ostream& os) const;
};

