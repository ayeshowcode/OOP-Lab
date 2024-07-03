#include <iostream>
#include <string>

using namespace std;

class Customer {
private:
    string name;
    string address;
    string driverLicense;
    int age;
    string creditCardInfo; // Simplified, normally you'd store multiple cards

public:
    Customer(string name, string address, string driverLicense, int age, string creditCardInfo)
        : name(name), address(address), driverLicense(driverLicense), age(age), creditCardInfo(creditCardInfo) {}

    void printDetails() const {
        cout << "Customer: " << name << ", Address: " << address << ", Age: " << age << endl;
    }

    bool isYoungDriver() const {
        return age <= 25;
    }

    bool isValidForRental() const {
        return age >= 18;
    }
};

class Vehicle {
protected:
    string make;
    string model;
    int year;
    int odometer;
    string vin;

public:
    Vehicle(string make, string model, int year, int odometer, string vin)
        : make(make), model(model), year(year), odometer(odometer), vin(vin) {}

    virtual void printVehicleType() const = 0;
};

class CompactCar : public Vehicle {
public:
    CompactCar(string make, string model, int year, int odometer, string vin)
        : Vehicle(make, model, year, odometer, vin) {}

    void printVehicleType() const override {
        cout << "Compact Car: " << make << " " << model << endl;
    }
};

class StandardCar : public Vehicle {
public:
    StandardCar(string make, string model, int year, int odometer, string vin)
        : Vehicle(make, model, year, odometer, vin) {}

    void printVehicleType() const override {
        cout << "Standard Car: " << make << " " << model << endl;
    }
};

class LuxuryCar : public Vehicle {
public:
    LuxuryCar(string make, string model, int year, int odometer, string vin)
        : Vehicle(make, model, year, odometer, vin) {}

    void printVehicleType() const override {
        cout << "Luxury Car: " << make << " " << model << endl;
    }
};

class RentalContract {
private:
    string startDate;
    string endDate;
    double rate;
    bool youngDriverFeeApplied;

public:
    RentalContract(string startDate, string endDate, double rate, bool youngDriverFeeApplied)
        : startDate(startDate), endDate(endDate), rate(rate), youngDriverFeeApplied(youngDriverFeeApplied) {}

    void printContract() const {
        cout << "Rental from " << startDate << " to " << endDate << " at rate $" << rate;
        if (youngDriverFeeApplied) cout << " with young driver fee";
        cout << endl;
    }
};

class Reservation {
private:
    string startDate;
    string endDate;
    string vehicleType;
    double quotedRate;

public:
    Reservation(string startDate, string endDate, string vehicleType, double quotedRate)
        : startDate(startDate), endDate(endDate), vehicleType(vehicleType), quotedRate(quotedRate) {}

    void printReservation() const {
        cout << "Reservation for a " << vehicleType << " from " << startDate << " to " << endDate << " at $" << quotedRate << endl;
    }
};

int main() {
    // Create a customer
    Customer ash("ayesh qureshi", "Mera address", "D231241", 22, "141512541451251");
    ash.printDetails();

    // Create vehicles
    CompactCar myCompact("Toyota", "Yaris", 2024, 15000, "VIN12345678901234567890");
    myCompact.printVehicleType();

    // Create a rental contract
    RentalContract contract("2024-04-01", "2024-04-07", 300.00, ash.isYoungDriver());
    contract.printContract();

    // Create a reservation
    Reservation res("2024-05-01", "2024-05-08", "Compact", 350.00);
    res.printReservation();

    return 0;
}