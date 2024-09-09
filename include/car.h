#ifndef CAR_H
#define CAR_H

#include <iostream>  
#include <string>    

class Car {
protected:
    std::string model;
    double basePrice;
    int loyaltyPoints;

public:
    Car(const std::string& model, double basePrice, int loyaltyPoints);
    virtual ~Car();

    virtual double calculatePrice(int days) = 0;
    virtual double calculateExtraDayCharge(int extraDays) = 0;

    int getLoyaltyPoints() const;
    std::string getModel() const;
};

class PremiumCar : public Car {
public:
    PremiumCar(const std::string& model);
    double calculatePrice(int days) override;
    double calculateExtraDayCharge(int extraDays) override;
};

class SUVCar : public Car {
public:
    SUVCar(const std::string& model);
    double calculatePrice(int days) override;
    double calculateExtraDayCharge(int extraDays) override;
};

class SmallCar : public Car {
public:
    SmallCar(const std::string& model);
    double calculatePrice(int days) override;
    double calculateExtraDayCharge(int extraDays) override;
};


#endif
