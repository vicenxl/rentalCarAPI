
# Car Rental Service API

## Description

This project is a car rental service system that provides an API for managing car rentals, calculating prices, and tracking customer loyalty points. It uses C++ and various libraries to implement the core functionalities.

## Key Features

- **Car Inventory Management**: Add and manage different types of cars in the inventory.
- **Rental Price Calculation**: Calculate the rental price based on the type of car and the number of days rented.
- **Customer Loyalty Points Tracking**: Keep track of customer loyalty points and allow customers to check their points.

## Decisions Made

- **HTTP Server with `httplib`**: Chose `httplib` for simplicity and ease of use in handling HTTP requests.

## Focus Areas

- **Car and Customer Management**: Implemented classes for cars and customers with necessary attributes and methods.
- **Rental Calculation**: Provided methods to calculate rental prices and additional charges based on the type of car.
- **Simple loyalty points**: managing customers and loyalty points.
- **API Endpoints**: Created HTTP endpoints to handle car rentals, returns, loyalty points and inventory queries.

## What Was Not Focused On

- **Complex Error Handling**: Basic error handling is implemented; more advanced error handling could be added.
- **User Authentication**: This API does not include user authentication or authorization.
- **Use of dinamic memory**: We could use smart pointers or improve it to manage dynamic memory more safely and avoid memory leaks.

## How to Run

1. **Build the Project**: 
   - Ensure you have a C++ compiler (e.g., MSVC, GCC) and `httplib` library.
   - Use the provided build configuration or compile manually using `cl.exe` or another compiler.
   - The repository contain configuration for VSCode.

2. **Run the Server**:
   - Execute the compiled `CarRentalSystem.exe` file.
   - The server will start and listen on `http://localhost:8080`.

3. **API Endpoints**:
   - **Rent a Car**: `POST /rent` with parameters `model`, `type`("Premium","SUV","Small"), `customer`, and `days`.
   - **Return a Car**: `POST /return` with parameters `customer` and `extraDays`.
   - **Show Available Cars**: `POST /cars`.
   - **Check Loyalty Points**: `POST /loyalty` with parameter `customer`.

## Dependencies

- **`httplib`**: For HTTP server and client functionalities.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
