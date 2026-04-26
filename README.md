# Smart-home-energy-usage-library
Home Energy Usage Tracking Library (C++)   A reusable C++ library to track and analyze household energy consumption. It uses OOP concepts like function overloading and operator overloading to manage appliance data, calculate total usage, and estimate energy costs efficiently.
A C++ header library designed to monitor and track energy 
consumption across different devices and rooms in a smart home. 
The library is built around three core classes that each handle 
a different part of the tracking system.

EnergyDevice represents a single home appliance like a fan, AC, 
or heater. It stores the device name, wattage, and how many hours 
it was used, and calculates the total energy consumed in kilowatt 
hours. EnergyRoom groups multiple devices together under one room 
and keeps track of the combined wattage and device count. 
EnergyBill handles the monthly electricity cost by taking the 
total units consumed and the rate per unit to calculate what the 
final bill amount will be.

The project demonstrates function overloading through three 
different constructors in each class covering default, partial, 
and full initialization. Operator overloading is shown using 
arithmetic operators like plus, minus and multiply, comparison 
operators like equal and less than, and the output stream 
operator for printing object details directly.

All three classes are tested in main.cpp with clear input values 
and readable output so every operator and constructor can be 
verified easily.
