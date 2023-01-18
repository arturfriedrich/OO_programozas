#include <iostream>
using namespace std;

class Tarstulajdonos
{
protected:
    string tulajnev;
    int tulajdonhanyad;

public:
    virtual void print() = 0;

    virtual ~Tarstulajdonos()
    {
    }
};

class BekesTulajdonos : public Tarstulajdonos
{
public:
    BekesTulajdonos(string tulajnev, int tulajdonhanyad)
    {
        this->tulajnev = tulajnev;
        this->tulajdonhanyad = tulajdonhanyad;
    }

    BekesTulajdonos()
    {
        tulajnev = "NA!";
        tulajdonhanyad = 0;
    }

    ~BekesTulajdonos()
    {
    }

    // Print
    void print()
    {
        cout << "Bekes tulajdonos: " << tulajnev << " - " << tulajdonhanyad << " / 10000" << endl;
    }
};

class PereskedoTulajdonos : public Tarstulajdonos
{
public:
    PereskedoTulajdonos(string tulajnev, int tulajdonhanyad)
    {
        this->tulajnev = tulajnev;
        this->tulajdonhanyad = tulajdonhanyad;
    }

    PereskedoTulajdonos()
    {
        tulajnev = "NA!";
        tulajdonhanyad = 0;
    }

    ~PereskedoTulajdonos()
    {
    }

    // Print
    void print()
    {
        cout << "Pereskedo tulajdonos: " << tulajnev << " - " << tulajdonhanyad << " / 10000" << endl;
    }
};

class Kozgyules : public Tarstulajdonos
{
protected:
    int ev;
    int honap;
    int nap;
    Tarstulajdonos *resztvevok[15];
    int actmember = 0;

public:
    Kozgyules(int ev, int honap, int nap)
    {
        this->ev = ev;
        this->honap = honap;
        this->nap = nap;
    }

    Kozgyules()
    {
        ev = 0;
        honap = 0;
        nap = 0;
    }

    ~Kozgyules()
    {
    }

    void addJelenlevo()
    {
        for (int i = 0; i < 6; i += 3) // Bekes
        {
            resztvevok[actmember] = 0;
            actmember++;
        }
        for (int i = 0; i < 5; i += 2) // Pereskedo
        {
            resztvevok[actmember] = 0;
            actmember++;
        }
    }

    void printJelenlevok()
    {
        for (int i = 0; i < 5; i++) // Bekes
        {
            resztvevok[i]->print();
        }
    }

    // Print
    void print()
    {
    }
};

class Tarsashaz : public Kozgyules
{
private:
    Tarstulajdonos *tulajdonosok[15];
    int membernum = 0;

public:
    // Print
    void print()
    {
    }

    void addTulajdonos(Tarstulajdonos *tulajdonos)
    {
        *tulajdonosok[membernum] = *tulajdonos;
        membernum++;
    }

    void holdKozgyules(Kozgyules *gyules)
    {
    }
};
