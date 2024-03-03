#ifndef LAUNDRY_DRYER_HPP
#define LAUNDRY_DRYER_HPP

#include <iostream>
#include <string>
#include "LaundryMachine.hpp"

class Dryer : public LaundryMachine {
private:
    std::string dryingMode;

public:
    Dryer() : LaundryMachine(), dryingMode("Regular") {}
    Dryer(int id, const std::string& mode) : LaundryMachine(id), dryingMode(mode) {}

    void setDryingMode(const std::string& mode) {
        dryingMode = mode;
    }

    void startDrying() {
        std::cout << "Starting the dryer with mode: " << dryingMode << std::endl;
        // Simulate the drying process
        std::cout << "Drying clothes..." << std::endl;
        std::cout << "Drying completed. Please retrieve your clothes." << std::endl;
    }

    void displayInfo() const {
        std::cout << "Dryer ID: " << getID() << std::endl;
        std::cout << "Drying Mode: " << dryingMode << std::endl;
        std::cout << "Availability: " << (isAvailable() ? "Available" : "Occupied") << std::endl;
    }
};

#endif // LAUNDRY_DRYER_HPP
