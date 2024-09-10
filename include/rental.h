#ifndef RENTAL_H
#define RENTAL_H

#include "car.h"      
#include "customer.h" 

class Rental {
private:
    Car* car;           
    int daysRented; 
    int extraDays;    

public:
    Rental();
    Rental(Car* car, int daysRented);

    void returnCar(int extraDays);
    double calculateTotalPrice();
    void assignLoyaltyPoints(Customer& customer);
    int getLoyaltyPoints();
};

#endif