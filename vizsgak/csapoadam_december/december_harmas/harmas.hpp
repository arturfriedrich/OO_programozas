#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

class EtlapElem
{
    protected:
        std::string nev;
        int ar;
    public:
        EtlapElem(std::string nev, int ar) : nev(nev), ar(ar) {}
        virtual ~EtlapElem() {}
        virtual void print() = 0;
};

class Leves : public EtlapElem
{
    public:
        Leves(std::string nev, int ar) : EtlapElem(nev, ar) {}
        void print()
        {
            std::cout << nev << " - " << ar << " Ft" << std::endl;
        }
};

class Foetel : public EtlapElem
{
    std::string koret;
    public:
        Foetel(std::string nev, std::string koret, int ar) : EtlapElem(nev, ar), koret(koret) {}
        void print()
        {
            std::cout << nev;
            std::cout << " " << koret << " korettel - ";
            std::cout << ar << " Ft" << std::endl;
        }
};

/* 3-as szint */

class Etlap
{
    std::vector<EtlapElem *> elemek;        // vektor létrehozása az étlapon szereplő elemeknek

    public:
        void hozzaad(EtlapElem *ee) {       // metódus, ami hozzáadja az étlephoz az adott elemet
            elemek.push_back(ee);           // a vektorba pusholja
        }
        void print() {
            std::cout << "Etlap:" << std::endl;
            for (EtlapElem *ee : elemek) {  // végig iterál az étlap vektoron és kiírja az elemeit a print() metúdussal
                ee->print();
            }
        }
};
