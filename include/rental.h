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
    // Constructor
    Rental(Car* car, int daysRented);

    // Método para devolver el coche (añadiendo días extras si fue tarde)
    void returnCar(int extraDays);

    // Calcular el precio total (incluyendo cualquier recargo por días extras)
    double calculateTotalPrice();

    // Asignar puntos de lealtad al cliente
    void assignLoyaltyPoints(Customer& customer);

    int getLoyaltyPoints();
};

#endif