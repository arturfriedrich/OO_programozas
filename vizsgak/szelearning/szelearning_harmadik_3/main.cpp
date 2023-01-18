#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

#include "harmadik_3.hpp"

int main()
{
    Kosar s;
    s.add(new Barack(5.2, 1800, "kg")); // 5.2kg barack, 480 Ft / kg
    s.add(new Tej(3.0, 2.8, 800, "l")); // 3 liter 2.8 szazalekos, 800 Ft / liter
    s.add(new TrappistaSajt(0.5, 2205, "kg", 0.2)); // 0.5kg, 2205 Ft / kg, de 20%-os kedvezmeny jon ra
    s.remove("TrappistaSajt");
    s.total();

    return 0;
}