Student Name   : Warda
Roll Number    : 67
Course         : Object Oriented Programming (CLO2)
Assignment     : 03

============================================================
PROBLEM
============================================================
Smart Home Energy Usage Tracking Library

============================================================
DESCRIPTION
============================================================
This project is a C++ header library called EnergyTracker.h that
tracks energy usage in a smart home. It has three classes:
EnergyDevice which stores a single appliance with its wattage and
hours used, EnergyRoom which groups devices in one room, and
EnergyBill which calculates monthly electricity cost. All three
classes use function overloading through multiple constructors and
operator overloading for arithmetic, comparison, and output.

============================================================
FILES INCLUDED
============================================================
  1. EnergyTracker.h  - Header library with 3 classes
  2. main.cpp         - Tests all functions and operators
  3. README.txt       - This file

============================================================
HOW TO COMPILE AND RUN
============================================================
  Visual Studio:
    1. Create empty C++ project
    2. Add EnergyTracker.h and main.cpp
    3. Press Ctrl+F5

  Command line:
    g++ main.cpp -o energy
    ./energy

============================================================
SAMPLE OUTPUT
============================================================

====================================================
     SMART HOME ENERGY USAGE TRACKING LIBRARY
====================================================

--- Function Overloading: EnergyDevice Constructors ---
Default      : Unknown | 0W | 0hrs | 0 kWh
Name only    : Heater | 0W | 0hrs | 0 kWh
Full params  : AC | 1500W | 5hrs | 7.5 kWh
Copy of d3   : AC | 1500W | 5hrs | 7.5 kWh

--- Function Overloading: setDevice ---
After setDevice(name)        : Fan | 0W | 0hrs | 0 kWh
After setDevice(name, watts) : Fan | 75W | 0hrs | 0 kWh
After setDevice(name, w, h)  : Fan | 75W | 8hrs | 0.6 kWh

--- Function Overloading: EnergyRoom Constructors ---
Default     : Unnamed Room | 0W | 0 devices
Name only   : Bedroom | 0W | 0 devices
Full params : Living Room | 2000W | 4 devices

--- Function Overloading: EnergyBill Constructors ---
Default     : Unknown | 0 kWh | Rs 0
Month only  : March | 0 kWh | Rs 0
Full params : April | 320 kWh | Rs 8000

====================================================
              DEVICE DETAILS
====================================================
Device 1 (Fan):
  Device   : Fan
  Wattage  : 75 W
  Hours    : 8 hrs
  Energy   : 0.6 kWh

Device 2 (AC):
  Device   : AC
  Wattage  : 1500 W
  Hours    : 5 hrs
  Energy   : 7.5 kWh

====================================================
           OPERATOR OVERLOADING DEMOS
====================================================

--- Operator + : Total energy of Fan + AC ---
Fan energy  : 0.6 kWh
AC energy   : 7.5 kWh
Combined    : 8.1 kWh

--- Operator - : Energy difference between AC and Fan ---
Difference  : 6.9 kWh

--- Operator * : Scale Fan energy by factor 3 ---
Fan x3      : 1.8 kWh

--- Operator == : Compare two devices ---
d3 == d4 ?  YES (equal energy)
d1 == d3 ?  NO (different)

--- Operator < : Which device uses less energy ---
d1 < d3 ?   YES  Fan uses less than AC

--- Operator + : Merge two rooms ---
Kitchen     : Kitchen | 1800W | 3 devices
Bedroom     : Bedroom | 900W | 2 devices
Combined    : Kitchen + Bedroom | 2700W | 5 devices

--- Operator < : Compare rooms by wattage ---
bedroom < kitchen ?  YES

--- Operator + : Add two monthly bills ---
March bill  : March | 280 kWh | Rs 7000
April bill  : April | 320 kWh | Rs 8000
Combined    : March/April | 600 kWh | Rs 15000

--- Operator < : Compare bills ---
March < April ?  YES (March cheaper)

====================================================
                 PROGRAM COMPLETE
====================================================

============================================================
OPERATORS I USED
============================================================

In this project I overloaded operators on all three classes.

For EnergyDevice I used + to add the energy of two devices
together, - to find the difference between them, and * to scale
a device's energy by a factor. I added == to check if two devices
consume the same energy and < to compare which one uses less.
The << operator prints the device details in a single line.

For EnergyRoom I used + to merge two rooms into one combined room
which adds up their total wattage and device count. I used == and
< to compare rooms by total wattage and << to display room info.

For EnergyBill I used + to combine two monthly bills, == to check
if two bills are equal, and < to compare which month had a lower
bill. The << operator shows the month, units and total cost.

============================================================
CIPHERS I IMPLEMENTED
============================================================

EnergyDevice  - tracks one appliance by wattage and hours used
EnergyRoom    - groups multiple devices in a single room
EnergyBill    - calculates total electricity cost for a month

