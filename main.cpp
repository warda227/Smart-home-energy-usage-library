#include <iostream>
#include "EnergyTracker.h"
using namespace std;

int main() {

    cout << "====================================================\n";
    cout << "     SMART HOME ENERGY USAGE TRACKING LIBRARY      \n";
    cout << "====================================================\n\n";

    cout << "--- Function Overloading: EnergyDevice Constructors ---\n";
    EnergyDevice d1;
    EnergyDevice d2("Heater");
    EnergyDevice d3("AC", 1500, 5);
    EnergyDevice d4(d3);
    cout << "Default      : " << d1 << "\n";
    cout << "Name only    : " << d2 << "\n";
    cout << "Full params  : " << d3 << "\n";
    cout << "Copy of d3   : " << d4 << "\n\n";

    cout << "--- Function Overloading: setDevice ---\n";
    d1.setDevice("Fan");
    cout << "After setDevice(name)        : " << d1 << "\n";
    d1.setDevice("Fan", 75);
    cout << "After setDevice(name, watts) : " << d1 << "\n";
    d1.setDevice("Fan", 75, 8);
    cout << "After setDevice(name, w, h)  : " << d1 << "\n\n";

    cout << "--- Function Overloading: EnergyRoom Constructors ---\n";
    EnergyRoom r1;
    EnergyRoom r2("Bedroom");
    EnergyRoom r3("Living Room", 2000, 4);
    cout << "Default     : " << r1 << "\n";
    cout << "Name only   : " << r2 << "\n";
    cout << "Full params : " << r3 << "\n\n";

    cout << "--- Function Overloading: EnergyBill Constructors ---\n";
    EnergyBill b1;
    EnergyBill b2("March");
    EnergyBill b3("April", 320, 25);
    cout << "Default     : " << b1 << "\n";
    cout << "Month only  : " << b2 << "\n";
    cout << "Full params : " << b3 << "\n\n";

    cout << "====================================================\n";
    cout << "              DEVICE DETAILS                        \n";
    cout << "====================================================\n";
    cout << "Device 1 (Fan):\n";
    d1.display();
    cout << "Device 2 (AC):\n";
    d3.display();

    cout << "====================================================\n";
    cout << "           OPERATOR OVERLOADING DEMOS               \n";
    cout << "====================================================\n\n";

    cout << "--- Operator + : Total energy of Fan + AC ---\n";
    cout << "Fan energy  : " << d1.getEnergyKWh() << " kWh\n";
    cout << "AC energy   : " << d3.getEnergyKWh() << " kWh\n";
    cout << "Combined    : " << (d1 + d3) << " kWh\n\n";

    cout << "--- Operator - : Energy difference between AC and Fan ---\n";
    cout << "Difference  : " << (d3 - d1) << " kWh\n\n";

    cout << "--- Operator * : Scale Fan energy by factor 3 ---\n";
    cout << "Fan x3      : " << (d1 * 3) << " kWh\n\n";

    cout << "--- Operator == : Compare two devices ---\n";
    cout << "d3 == d4 ?  " << (d3 == d4 ? "YES (equal energy)" : "NO (different)") << "\n";
    cout << "d1 == d3 ?  " << (d1 == d3 ? "YES (equal energy)" : "NO (different)") << "\n\n";

    cout << "--- Operator < : Which device uses less energy ---\n";
    cout << "d1 < d3 ?   " << (d1 < d3 ? "YES  Fan uses less than AC" : "NO") << "\n\n";

    cout << "--- Operator << : Print device info ---\n";
    cout << d1 << "\n";
    cout << d3 << "\n\n";

    cout << "--- Operator + : Merge two rooms ---\n";
    EnergyRoom kitchen("Kitchen", 1800, 3);
    EnergyRoom bedroom("Bedroom", 900, 2);
    EnergyRoom combined = kitchen + bedroom;
    cout << "Kitchen     : " << kitchen  << "\n";
    cout << "Bedroom     : " << bedroom  << "\n";
    cout << "Combined    : " << combined << "\n\n";

    cout << "--- Operator < : Compare rooms by wattage ---\n";
    cout << "bedroom < kitchen ?  " << (bedroom < kitchen ? "YES" : "NO") << "\n\n";

    cout << "--- Operator + : Add two monthly bills ---\n";
    EnergyBill march("March", 280, 25);
    EnergyBill april("April", 320, 25);
    EnergyBill total = march + april;
    cout << "March bill  : " << march << "\n";
    cout << "April bill  : " << april << "\n";
    cout << "Combined    : " << total << "\n\n";

    cout << "--- Operator < : Compare bills ---\n";
    cout << "March < April ?  " << (march < april ? "YES (March cheaper)" : "NO") << "\n\n";

    cout << "====================================================\n";
    cout << "                 PROGRAM COMPLETE                   \n";
    cout << "====================================================\n";

    return 0;
}
