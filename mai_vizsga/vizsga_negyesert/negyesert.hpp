#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

class TriRace
{
    private:
        const int swimming, cycling, running;
        double cache;
    
    public:
        TriRace(int swimming, int cycling, int running) : swimming(swimming), cycling(cycling), running(running) {}
        virtual void saveAndPrintRaceDistance() = 0;
        virtual ~TriRace() { }

    double getCache() { return this->cache; }
    void setCache( double cache ) { this->cache = cache; }
    int getSwimming() { return this->swimming; }
    int getCycling() { return this->cycling; }
    int getRunning() { return this->running; }
};

class Sprint : public TriRace
{
    public:
        Sprint(int swimming, int cycling, int running) : TriRace(swimming, cycling, running ){}

        void saveAndPrintRaceDistance() override {
            std::cout << "Az Sprint tavu verseny hossza:" << this->setAndGetCache() << std::endl;
        }
        double setAndGetCache() {
            this->setCache((this->getSwimming() + this->getCycling() + this->getRunning()) / 1000.0);
            return this->getCache();
        }
        ~Sprint() {}
};

class Olympic: public TriRace  
{
    public:
        Olympic(int swimming, int cycling, int running) : TriRace(swimming, cycling, running ){}

        void saveAndPrintRaceDistance() override {
            std::cout << "Az Olimpiai tavu verseny hossza:" << this->setAndGetCache() << std::endl;
        }
        double setAndGetCache() {
            this->setCache((this->getSwimming() + this->getCycling() + this->getRunning()) / 1000.0);
            return this->getCache();
        }
        ~Olympic() {}
};

class Ironman : public TriRace
{
    public:
        Ironman(int swimming, int cycling, int running) : TriRace(swimming, cycling, running ){}

        void saveAndPrintRaceDistance() override {
            std::cout << "A Hosszu tavu verseny hossza:" << this->setAndGetCache() << std::endl;
        }

        double setAndGetCache() {
            this->setCache((this->getSwimming() + this->getCycling() + this->getRunning()) / 1000.0);
            return this->getCache();
        }
        ~Ironman() {}  
};

void printRaceDistancesOfRaceTypes(std::vector<TriRace*>& versenyek) {
    unsigned int n = 0;
    for ( TriRace* verseny : versenyek ) {
      	if ( Sprint* sprint = dynamic_cast<Sprint*>(verseny) ) {
        	std::cout << sprint->setAndGetCache() << " [km]";
        	if ( n < versenyek.size() - 1 ) {
            	std::cout << " => ";
        	} else {
            	std::cout << std::endl;
    		}
      	n++;  
	} 
		else if (Olympic* olympic = dynamic_cast<Olympic*>(verseny)) {
			std::cout << olympic->setAndGetCache() << " [km]";
			if ( n < versenyek.size() - 1 ) {
				std::cout << " => ";
			} else {
				std::cout << std::endl;
			}
			n++;  
	}
	else if (Ironman* ironman = dynamic_cast<Ironman*>(verseny)) {
		std::cout << ironman->setAndGetCache() << " [km]";
		if ( n < versenyek.size() - 1 ) {
			std::cout << " => ";
		} else {
			std::cout << std::endl;
		}
		n++;  
	}
    }
}

void printNamesofRaceTypes(std::vector<TriRace*>& versenyek) {
    for(TriRace* verseny : versenyek) {
        if(dynamic_cast<Sprint*>(verseny) ) {
        std::cout << "Sprint tav" << std::endl;
        }
        else if(dynamic_cast<Olympic*>(verseny) ) {
        std::cout << "Olimpiai tav" << std::endl;
        }
        else if(dynamic_cast<Ironman*>(verseny)) {
        std::cout << "Hosszu tav" << std::endl;
        }
    }
}