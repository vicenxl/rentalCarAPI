#include "Car.h"     

class Car {
protected:
    std::string model;
    double basePrice;
    int loyaltyPoints;

public:
    Car(const std::string& model, double basePrice, int loyaltyPoints)
        : model(model), basePrice(basePrice), loyaltyPoints(loyaltyPoints) {}

    virtual ~Car() {}

    virtual double calculatePrice(int days) = 0;
    virtual double calculateExtraDayCharge(int extraDays) = 0;

    int getLoyaltyPoints() const { return loyaltyPoints; }

    std::string getModel() const { return model; }
};

class PremiumCar : public Car {
public:
    PremiumCar(const std::string& model) : Car(model, 300, 5) {}

    double calculatePrice(int days) override {
        return days * basePrice;
    }

    double calculateExtraDayCharge(int extraDays) override {
        return extraDays * (basePrice * 1.2);
    }
};

class SUVCar : public Car {
public:
    SUVCar(const std::string& model) : Car(model, 150, 3) {}

    double calculatePrice(int days) override {
        if (days <= 7) return days * basePrice;
        if (days <= 30) return 7 * basePrice + (days - 7) * basePrice * 0.8;
        return 7 * basePrice + 23 * basePrice * 0.8 + (days - 30) * basePrice * 0.5;
    }

    double calculateExtraDayCharge(int extraDays) override {
        return extraDays * (basePrice + 60); // 60% of small car price
    }
};

class SmallCar : public Car {
public:
    SmallCar(const std::string& model) : Car(model, 50, 1) {}

    double calculatePrice(int days) override {
        if (days <= 7) return days * basePrice;
        return 7 * basePrice + (days - 7) * basePrice * 0.6;
    }

    double calculateExtraDayCharge(int extraDays) override {
        return extraDays * (basePrice * 1.3);  // 30% extra for small cars
    }
};
