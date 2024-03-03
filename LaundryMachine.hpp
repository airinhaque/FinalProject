#ifndef LAUNDRY_MACHINE_HPP
#define LAUNDRY_MACHINE_HPP

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <ctime>
#include <cstdlib>

class LaundryMachine {
private:
    int machineID;
    bool available;
    int timeRemaining;
    int duration;
    std::string mode;
    time_t startTime;
    static double price;

public:
    // Constructor
    LaundryMachine() : machineID(rand() % 100), available(true), timeRemaining(0), duration(0), mode("Normal") {}

    // Accessor methods
    int getMachineID() const { return machineID; }
    double getPrice() const { return price; }
    int getDuration() const { return duration; }
    std::string getMode() const { return mode; }
    bool isAvailable() const { return available; }

    // Mutator methods
    void setMachineID(int ID) { machineID = ID; }
    void setPrice(double machinePrice) { price = machinePrice; }
    void setDuration(int dur) { duration = dur; }
    void setMode(const std::string& m) { mode = m; }
    void setAvailable(bool isAvailable) { available = isAvailable; }

    // Member functions
    void printInfo() const;
    void startCycle();
    bool checkFunds(double balance) const;
};

// Static member initialization
double LaundryMachine::price = 0.0;

// Member function definitions
void LaundryMachine::printInfo() const {
    std::cout << "Machine ID: " << machineID << std::endl;
    std::cout << "Mode: " << mode << std::endl;
    std::cout << "Available: " << (available ? "Yes" : "No") << std::endl;
}

void LaundryMachine::startCycle() {
    if (!available) {
        std::cout << "Machine is already in use." << std::endl;
        return;
    }
    available = false;
    startTime = time(nullptr);
    timeRemaining = duration;
    std::cout << "Cycle started. Duration: " << duration << " minutes." << std::endl;
    std::this_thread::sleep_for(std::chrono::minutes(duration));
    std::cout << "Cycle completed. Please collect your items." << std::endl;
    available = true;
}

bool LaundryMachine::checkFunds(double balance) const {
    return balance >= price;
}

#endif // LAUNDRY_MACHINE_HPP
