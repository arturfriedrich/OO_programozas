#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

#include "negyesert.hpp"

int main() {
    static_assert(std::is_abstract<TriRace>(), "Hiba! TriRace osztaly nem absztrakt!");
    TriRace* dist1 = new Sprint(750, 20000, 5000);
    TriRace* dist2 = new Olympic(1500, 40000, 10000);
    TriRace* dist3 = new Ironman(3800, 180000, 42195);

    MultiRace* dist4 = new MultiRace();
    *dist4 += *dist1;
    *dist4 += *dist2;
    dist4->saveAndPrintRaceDistance();

    MultiRace* dist5 = new MultiRace();
    *dist5 += *dist2;
    *dist5 += *dist3;
    dist5->saveAndPrintRaceDistance();

    delete dist1;
    delete dist2;
    delete dist3;
    delete dist4;
    delete dist5;

    return 0;
}
