#include "Car.h"

Car::Car(const std::string& model, double basePrice, int loyaltyPoints)
    : model(model), basePrice(basePrice), loyaltyPoints(loyaltyPoints) {}

Car::~Car()
{
}

int Car::getLoyaltyPoints() const {
    return loyaltyPoints;
}

std::string Car::getModel() const {
    return model;
}

PremiumCar::PremiumCar(const std::string& model)
    : Car(model, 300, 5) {}

double PremiumCar::calculatePrice(int days) {
    return days * basePrice;
}

double PremiumCar::calculateExtraDayCharge(int extraDays) {
    return extraDays * (basePrice * 1.2);
}

SUVCar::SUVCar(const std::string& model)
    : Car(model, 150, 3) {}

double SUVCar::calculatePrice(int days) {
    if (days <= 7) return days * basePrice;
    if (days <= 30) return 7 * basePrice + (days - 7) * basePrice * 0.8;
    return 7 * basePrice + 23 * basePrice * 0.8 + (days - 30) * basePrice * 0.5;
}

double SUVCar::calculateExtraDayCharge(int extraDays) {
    return extraDays * (basePrice + 60); 
}

SmallCar::SmallCar(const std::string& model)
    : Car(model, 50, 1) {}

double SmallCar::calculatePrice(int days) {
    if (days <= 7) return days * basePrice;
    return 7 * basePrice + (days - 7) * basePrice * 0.6;
}

double SmallCar::calculateExtraDayCharge(int extraDays) {
    return extraDays * (basePrice * 1.3);  
}
