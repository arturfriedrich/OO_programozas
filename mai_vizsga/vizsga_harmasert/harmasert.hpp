#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

class TriRace
{
    public:
 
    const int swimming, cycling, running;
    
    TriRace(int swimming, int cycling, int running) : swimming(swimming), cycling(cycling), running(running) { }
    virtual void saveAndPrintRaceDistance() = 0;
    virtual ~TriRace() { }
};

class Sprint : public TriRace
{
    public:
        Sprint(int swimming, int cycling, int running) : TriRace(swimming, cycling, running) { }
        void saveAndPrintRaceDistance() override {
            double cache = (swimming + cycling + running) / 1000.0; 
            std::cout << "Az Sprint tavu verseny hossza: " << cache << " [km]" << std::endl;
        }
};

class Olympic : public TriRace
{
    public:
        Olympic(int swimming, int cycling, int running) : TriRace(swimming, cycling, running) { }
        void saveAndPrintRaceDistance() {
            double cache = (swimming + cycling + running) / 1000.0; 
            std::cout << "Az Olimpiai tavu verseny hossza: " << cache << " [km]" << std::endl;
        }
};

class Ironman : public TriRace
{
    public:
        Ironman(int swimming, int cycling, int running) : TriRace(swimming, cycling, running) { }
        void saveAndPrintRaceDistance() {
            double cache = (swimming + cycling + running) / 1000.0; 
            std::cout << "A Hosszu tavu verseny hossza: " << cache << " [km]" << std::endl;
        }
};

void printRaceDistancesOfRaceTypes(std::vector) {

}