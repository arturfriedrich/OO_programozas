#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

#include "kettesert.hpp"

int main() {
    static_assert(std::is_abstract<TriRace>(), "Hiba! TriRace osztaly nem absztrakt!");
    TriRace* dist1 = new Sprint(750, 20000, 5000);
    TriRace* dist2 = new Olympic(1500, 40000, 10000);
    TriRace* dist3 = new Ironman(3800, 180000, 42195);

    std::vector<TriRace*> allRaceDistances = { dist1, dist2, dist3 };
    printRaceDistancesOfRaceTypes(allRaceDistances);

    std::vector<TriRace*> allRaceDistances2 = { dist2, dist3, dist1 };
    printRaceDistancesOfRaceTypes(allRaceDistances2);

    delete dist1;
    delete dist2;
    delete dist3;

    return 0;
}
