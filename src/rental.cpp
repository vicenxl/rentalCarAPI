#include "rental.h"

class Rental {
private:
    Car* car;
    int daysRented;
    int extraDays;

public:
    Rental(Car* car, int daysRented) : car(car), daysRented(daysRented), extraDays(0) {}

    void returnCar(int extraDays) {
        this->extraDays = extraDays;
    }

    double calculateTotalPrice() {
        double basePrice = car->calculatePrice(daysRented);
        if (extraDays > 0) {
            basePrice += car->calculateExtraDayCharge(extraDays);
        }
        return basePrice;
    }

    void assignLoyaltyPoints(Customer &customer)   {}

    int Rental::getLoyaltyPoints(){
        return car->getLoyaltyPoints();
    }
};
