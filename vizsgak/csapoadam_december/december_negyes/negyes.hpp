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
    virtual EtlapElem *copy() = 0;
};

class Leves : public EtlapElem
{
public:
    Leves(std::string nev, int ar) : EtlapElem(nev, ar) {}
    void print()
    {
        std::cout << nev << " - " << ar << " Ft" << std::endl;
    }
    Leves *copy()
    {
        return new Leves(nev, ar);
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
    Foetel *copy()
    {
        return new Foetel(nev, koret, ar);
    }
};

class Etlap
{
    std::vector<EtlapElem *> elemek;

public:
    ~Etlap()
    {
        for (EtlapElem *ee : elemek)
        {
            delete ee;
        }
    }
    Etlap() {}
    Etlap(Etlap &other)
    {
        for (EtlapElem *ee : other.elemek)
        {
            elemek.push_back(ee->copy());
        }
    }
    void hozzaad(EtlapElem *ee)
    {
        elemek.push_back(ee);
    }
    void print()
    {
        std::cout << "Etlap:" << std::endl;
        for (EtlapElem *ee : elemek)
        {
            ee->print();
        }
    }
};