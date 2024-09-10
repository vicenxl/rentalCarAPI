#include "httplib.h"
#include <iostream>
#include <string>
#include <sstream>
#include "rentalService.h"
#include "customer.h"

// Estructura para almacenar información del coche
struct Car {
    std::string model;
    double dailyRate;
};

RentalService rentalService;

// Crear un coche de ejemplo
Car exampleCar{"BMW 7", 300.0};

/*Car* getCarFromType(const std::string& type, const std::string& model) {
    if (type == "Premium") {
        return new PremiumCar(model);
    } else if (type == "SUV") {
        return new SUVCar(model);
    } else if (type == "Small") {
        return new SmallCar(model);
    } else {
        return nullptr;
    }
}
*/

void handle_rent(const httplib::Request& req, httplib::Response& res) {
    if (req.method == "POST") {
        auto model = req.get_param_value("model");
        auto type = req.get_param_value("type");
        auto customerName = req.get_param_value("customer");
        auto days_str = req.get_param_value("days");
        int days = std::stoi(days_str);

        Customer customer(customerName);

        rentalService.rentCar(customer, car, days);
        
        std::stringstream responseStream;
        responseStream << "Car rented: " << exampleCar.model << " at rate " << exampleCar.dailyRate << " per day. Initial price:" << exampleCar.dailyRate*days;
        res.set_content(responseStream.str(), "text/plain");
    } else {
        res.status = 405;  // Method Not Allowed
        res.set_content("Method Not Allowed", "text/plain");
    }
}

void handle_return(const httplib::Request& req, httplib::Response& res) {
    if (req.method == "POST") {
        auto customerName = req.get_param_value("customer");
        auto days_str = req.get_param_value("extraDays");
        int extraDays = std::stoi(days_str);

        std::stringstream responseStream;
        responseStream << "Car returned: " << exampleCar.model << "Final cost: ";
        res.set_content(responseStream.str(), "text/plain");
    } else {
        res.status = 405;  // Method Not Allowed
        res.set_content("Method Not Allowed", "text/plain");
    }
}

int main() {
    httplib::Server svr;

    Car exampleCar{"BMW 7", 300.0};
    Car exampleCar{"Kia Sorento", 150.0};
    Car exampleCar{"Nissan Juke", 150.0};
    Car exampleCar{"Seat Ibiza", 50.0};

    rentalService.addCar();

    svr.Post("/rent", handle_rent);
    svr.Post("/return", handle_return);

    std::cout << "Starting server on http://localhost:8080" << std::endl;
    svr.listen("localhost", 8080);

    return 0;
}
