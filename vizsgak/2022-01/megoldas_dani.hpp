#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Ostream variables
bool cycleok = false;
bool swimok = false;
bool runok = false;

class Sports
{
protected:
    const int calc0 = 60;
    const int calc1 = 100;
    const int calc2 = 1000;
    const int calc3 = 3600;
    double swimdata;
    double cycledata;
    double rundata;

public:
    virtual void computeSaveAndPrintAverage() = 0;
    virtual ~Sports()
    {
    }
    double getSwim()
    {
        return swimdata;
    }
    double getCycle()
    {
        return cycledata;
    }
    double getRun()
    {
        return rundata;
    }
};

class Swimming : public Sports
{
private:
    double masodperc;
    double meter;

public:
    Swimming(double masodperc, double meter)
    {
        this->masodperc = masodperc;
        this->meter = meter;
        swimdata = 0;
    }
    Swimming()
    {
        masodperc = 0;
        meter = 0;
        swimdata = 0;
    }
    ~Swimming()
    {
    }
    void computeSaveAndPrintAverage()
    {
        swimdata = masodperc / (meter / calc1);
        cout << "Az uszas atlaga: " << swimdata << " s / 100 m" << endl;
    }
};

class Cycling : public Sports
{
private:
    double kilometer = 0;
    double ora = 0;

public:
    Cycling(double kilometer, double ora)
    {
        this->kilometer = kilometer;
        this->ora = ora;
        cycledata = 0;
    }
    Cycling()
    {
        kilometer = 0;
        ora = 0;
        cycledata = 0;
    }
    ~Cycling()
    {
    }
    void computeSaveAndPrintAverage()
    {
        cycledata = (kilometer / calc2) / (ora / calc3);
        cout << "A kerekparozas atlaga: " << cycledata << " km / h" << endl;
    }
};

class Running : public Sports
{
private:
    double perc = 0;
    double kilometer = 0;

public:
    Running(double perc, double kilometer)
    {
        this->perc = perc;
        this->kilometer = kilometer;
        rundata = 0;
    }
    Running()
    {
        perc = 0;
        kilometer = 0;
        rundata = 0;
    }
    ~Running()
    {
    }
    void computeSaveAndPrintAverage()
    {
        rundata = (perc / calc0) / (kilometer / calc2);
        cout << "A futas atlaga:: " << rundata << " min / km" << endl;
    }
};

ostream &operator<<(ostream &COUT, Sports &Sports) // Overloading << operator
{
    string data = "\0";
    if (Sports.getCycle() != 0 and cycleok == false)
    {
        cycleok = true;
        data += to_string(Sports.getCycle());
        data += " - ";
    };
    if (Sports.getSwim() != 0 and swimok == false)
    {
        swimok = true;
        data += to_string(Sports.getSwim());
        data += " - ";
    };
    if (Sports.getRun() != 0 and runok == false)
    {
        runok = true;
        data += to_string(Sports.getRun());
    };
    COUT << data;
    return COUT;
}

void printAverages(vector<Sports *> allSports)
{
    for (long unsigned i = 0; i < allSports.size(); i++)
    {
        cout << *allSports[i];
    }
}

void printNamesOfSports(vector<Sports *> allSports)
{
    cout << endl;
    for (long unsigned i = 0; i < allSports.size(); i++)
    {
        if (allSports[i]->getSwim())
        {
            cout << "Uszas" << endl;
        };
        if (allSports[i]->getCycle())
        {
            cout << "Kerekpar" << endl;
        };
        if (allSports[i]->getRun())
        {
            cout << "Futas" << endl;
        };
    }
}