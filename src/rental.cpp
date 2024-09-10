#include "rental.h"

Rental::Rental() : car(nullptr), daysRented(0), extraDays(0) {}

Rental::Rental(Car* car, int daysRented) : car(car), daysRented(daysRented), extraDays(0) {}

void Rental::returnCar(int extraDays) {
        this->extraDays = extraDays;
}

double Rental::calculateTotalPrice() {
    double basePrice = car->calculatePrice(daysRented);
    if (extraDays > 0) 
        basePrice += car->calculateExtraDayCharge(extraDays);

    return basePrice;
}

void Rental::assignLoyaltyPoints(Customer &customer)   {}

int Rental::getLoyaltyPoints(){
    return car->getLoyaltyPoints();
}

