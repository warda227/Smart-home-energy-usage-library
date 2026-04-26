#ifndef ENERGYTRACKER_H
#define ENERGYTRACKER_H

#include <iostream>
#include <string>
using namespace std;

class EnergyDevice {
private:
    string deviceName;
    double wattage;
    double hoursUsed;

public:
    EnergyDevice() {
        deviceName = "Unknown";
        wattage    = 0.0;
        hoursUsed  = 0.0;
    }

    EnergyDevice(string name) {
        deviceName = name;
        wattage    = 0.0;
        hoursUsed  = 0.0;
    }

    EnergyDevice(string name, double w, double h) {
        deviceName = name;
        wattage    = w;
        hoursUsed  = h;
    }

    EnergyDevice(const EnergyDevice& other) {
        deviceName = other.deviceName;
        wattage    = other.wattage;
        hoursUsed  = other.hoursUsed;
    }

    void setDevice(string name) {
        deviceName = name;
    }

    void setDevice(string name, double w) {
        deviceName = name;
        wattage    = w;
    }

    void setDevice(string name, double w, double h) {
        deviceName = name;
        wattage    = w;
        hoursUsed  = h;
    }

    string getName()     const { return deviceName; }
    double getWattage()  const { return wattage; }
    double getHours()    const { return hoursUsed; }
    double getEnergyKWh() const { return (wattage * hoursUsed) / 1000.0; }

    void display() const {
        cout << "  Device   : " << deviceName       << "\n";
        cout << "  Wattage  : " << wattage          << " W\n";
        cout << "  Hours    : " << hoursUsed        << " hrs\n";
        cout << "  Energy   : " << getEnergyKWh()   << " kWh\n";
        cout << "\n";
    }

    double operator+(const EnergyDevice& other) const {
        return getEnergyKWh() + other.getEnergyKWh();
    }

    double operator-(const EnergyDevice& other) const {
        double diff = getEnergyKWh() - other.getEnergyKWh();
        return diff < 0 ? -diff : diff;
    }

    double operator*(double factor) const {
        return getEnergyKWh() * factor;
    }

    bool operator==(const EnergyDevice& other) const {
        return getEnergyKWh() == other.getEnergyKWh();
    }

    bool operator<(const EnergyDevice& other) const {
        return getEnergyKWh() < other.getEnergyKWh();
    }

    friend ostream& operator<<(ostream& os, const EnergyDevice& d) {
        os << d.deviceName << " | " << d.wattage << "W | "
           << d.hoursUsed << "hrs | " << d.getEnergyKWh() << " kWh";
        return os;
    }
};


class EnergyRoom {
private:
    string roomName;
    double totalWattage;
    int    deviceCount;

public:
    EnergyRoom() {
        roomName     = "Unnamed Room";
        totalWattage = 0.0;
        deviceCount  = 0;
    }

    EnergyRoom(string name) {
        roomName     = name;
        totalWattage = 0.0;
        deviceCount  = 0;
    }

    EnergyRoom(string name, double watts, int count) {
        roomName     = name;
        totalWattage = watts;
        deviceCount  = count;
    }

    void addDevice(double watts) {
        totalWattage += watts;
        deviceCount++;
    }

    string getName()        const { return roomName; }
    double getTotalWattage() const { return totalWattage; }
    int    getDeviceCount()  const { return deviceCount; }

    void display() const {
        cout << "  Room          : " << roomName     << "\n";
        cout << "  Total Wattage : " << totalWattage << " W\n";
        cout << "  Device Count  : " << deviceCount  << "\n\n";
    }

    EnergyRoom operator+(const EnergyRoom& other) const {
        EnergyRoom merged(roomName + " + " + other.roomName,
                          totalWattage + other.totalWattage,
                          deviceCount  + other.deviceCount);
        return merged;
    }

    bool operator==(const EnergyRoom& other) const {
        return totalWattage == other.totalWattage;
    }

    bool operator<(const EnergyRoom& other) const {
        return totalWattage < other.totalWattage;
    }

    friend ostream& operator<<(ostream& os, const EnergyRoom& r) {
        os << r.roomName << " | " << r.totalWattage << "W | "
           << r.deviceCount << " devices";
        return os;
    }
};


class EnergyBill {
private:
    string month;
    double unitsConsumed;
    double ratePerUnit;

public:
    EnergyBill() {
        month         = "Unknown";
        unitsConsumed = 0.0;
        ratePerUnit   = 0.0;
    }

    EnergyBill(string m) {
        month         = m;
        unitsConsumed = 0.0;
        ratePerUnit   = 0.0;
    }

    EnergyBill(string m, double units, double rate) {
        month         = m;
        unitsConsumed = units;
        ratePerUnit   = rate;
    }

    double getTotalBill() const { return unitsConsumed * ratePerUnit; }
    string getMonth()     const { return month; }
    double getUnits()     const { return unitsConsumed; }

    void display() const {
        cout << "  Month    : " << month                 << "\n";
        cout << "  Units    : " << unitsConsumed         << " kWh\n";
        cout << "  Rate     : Rs " << ratePerUnit        << " per unit\n";
        cout << "  Total    : Rs " << getTotalBill()     << "\n\n";
    }

    EnergyBill operator+(const EnergyBill& other) const {
        return EnergyBill(month + "/" + other.month,
                          unitsConsumed + other.unitsConsumed,
                          (ratePerUnit + other.ratePerUnit) / 2.0);
    }

    bool operator==(const EnergyBill& other) const {
        return getTotalBill() == other.getTotalBill();
    }

    bool operator<(const EnergyBill& other) const {
        return getTotalBill() < other.getTotalBill();
    }

    friend ostream& operator<<(ostream& os, const EnergyBill& b) {
        os << b.month << " | " << b.unitsConsumed
           << " kWh | Rs " << b.getTotalBill();
        return os;
    }
};

#endif
