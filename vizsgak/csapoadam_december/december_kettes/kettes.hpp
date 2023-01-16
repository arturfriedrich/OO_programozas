#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

class EtlapElem                 // osztáy deklarációja
{
    protected:                  // védett változók
        std::string nev;        // étel neve
        int ar;                 // étel ára
    public:                                                         // publikus változók
        EtlapElem(std::string nev, int ar) : nev(nev), ar(ar) {}    // konstruktor
        virtual ~EtlapElem() {}                                     // virtuális függvények
        virtual void print() = 0;
};

class Leves : public EtlapElem              // örököltetett gyerek osztály - Leves
{
    public:
        Leves(std::string nev, int ar) : EtlapElem(nev, ar) {}      // konstruktor
        void print()                                                // a Leves print() metódusa
        {
            std::cout << nev << " - " << ar << " Ft" << std::endl;  // ebben a formában írjuk ki a konzolra a leveseket
        }
};

class Foetel : public EtlapElem             // örökített gyerek osztály - Főétel
{
    std::string koret;                      // mivel itt plusz egy tagváltozó van, ezért azt itt hozzuk létre
    public:
        Foetel(std::string nev, std::string koret, int ar) : EtlapElem(nev, ar), koret(koret) {}        // konstruktor
        void print()                        // a Főétel print() metódusa
        {
            std::cout << nev;
            std::cout << " " << koret << " korettel - ";
            std::cout << ar << " Ft" << std::endl;
        }
};
