#include "httplib.h"
#include <iostream>
#include <string>

// Estructura para almacenar información del coche (para simplicidad)
struct Car {
    std::string model;
    double dailyRate;
};

// Crear un coche de ejemplo
Car exampleCar{"BMW 7", 300.0};

// Manejar la solicitud de alquiler
void handle_rent(const httplib::Request& req, httplib::Response& res) {
    if (req.method == "POST") {
        // Aquí podrías añadir lógica para procesar el alquiler
        res.set_content("Car rented: " + exampleCar.model, "text/plain");
    } else {
        res.status = 405;  // Method Not Allowed
        res.set_content("Method Not Allowed", "text/plain");
    }
}

// Manejar la solicitud de devolución
void handle_return(const httplib::Request& req, httplib::Response& res) {
    if (req.method == "POST") {
        // Aquí podrías añadir lógica para procesar la devolución
        res.set_content("Car returned: " + exampleCar.model, "text/plain");
    } else {
        res.status = 405;  // Method Not Allowed
        res.set_content("Method Not Allowed", "text/plain");
    }
}

int main() {
    httplib::Server svr;

    svr.Post("/rent", handle_rent);
    svr.Post("/return", handle_return);

    std::cout << "Starting server on http://localhost:8080" << std::endl;
    svr.listen("localhost", 8080);

    return 0;
}
