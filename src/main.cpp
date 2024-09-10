#include "httplib.h"
#include <iostream>
#include <string>
#include <sstream>
#include "rentalService.h"
#include "customer.h"
#include "car.h"


RentalService rentalService;

Car* getCarFromType(const std::string& type, const std::string& model) {
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

void handle_rent(const httplib::Request& req, httplib::Response& res) {
    if (req.method == "POST") {
        auto model = req.get_param_value("model");
        auto type = req.get_param_value("type");
        auto customerName = req.get_param_value("customer");
        auto days_str = req.get_param_value("days");
        int days = std::stoi(days_str);

        Customer customer(customerName);
        Car* car = getCarFromType(type, model);

        rentalService.rentCar(customer, car, days);
        
        std::stringstream responseStream;
        responseStream << "Car rented: " << car->getModel() << " for " << days << " days.";
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

        Customer customer(customerName);
        double totalPrice = rentalService.returnCar(customer, extraDays);
    
        if (totalPrice >= 0) {
            std::stringstream responseStream;
            responseStream << "Car returned. Total cost: " << totalPrice << " €";
            res.set_content(responseStream.str(), "text/plain");
        } else {
            res.status = 400;  
            res.set_content("Error: No car rented for this customer.", "text/plain");
        }
    } else {
        res.status = 405;  
        res.set_content("Method Not Allowed", "text/plain");
    }
}

void handle_showcars(const httplib::Request& req, httplib::Response& res) {
    if (req.method == "POST") {
        std::stringstream responseStream;

        rentalService.showInventory(responseStream);
        res.set_content(responseStream.str(), "text/plain");
    } else {
        res.status = 405;  // Method Not Allowed
        res.set_content("Method Not Allowed", "text/plain");
    }
}

int main() {
    httplib::Server svr;

    rentalService.addCar(new PremiumCar("BMW 7"));
    rentalService.addCar(new SUVCar("Kia Sorento"));
    rentalService.addCar(new SUVCar("Nissan Juke"));
    rentalService.addCar(new SmallCar("Seat Ibiza"));

    svr.Post("/rent", handle_rent);
    svr.Post("/return", handle_return);
    svr.Post("/cars", handle_showcars);

    std::cout << "Starting server on http://localhost:8080" << std::endl;
    svr.listen("localhost", 8080);

    return 0;
}
