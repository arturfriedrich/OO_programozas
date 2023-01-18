#pragma once
#include <iostream>
#include <vector>
using namespace std;

// Kettes szint
class Sports
{
protected:
    const int calc0 = 60;
    const int calc1 = 100;
    const int calc2 = 1000;
    const int calc3 = 3600;
    double time;
    double distance;

public:
    Sports(double distance, double time)
    {
        this->distance = distance;
        this->time = time;
    }
    Sports()
    {
        distance = 0.0;
        time = 0.0;
    }
    virtual ~Sports()
    {
    }
    virtual void computeSaveAndPrintAverage(){};
    virtual string getNameOfSports(){};
    virtual double getAverage(){};

    // Otos szint
    double getTime()
    {
        return time;
    }
    double getDist()
    {
        return distance;
    }
    Sports &operator+=(Sports &name) // Overloading += operator
    {
        distance = distance + name.getDist();
        time = time + name.getTime();
        return *this;
    }
    void printTotal()
    {
        cout << "\nA teljes táv: " << getDist() << " [km]" << endl;
        cout << "\nA cel ido: " << int(getDist() / calc3) << ':' << int(getDist()) % calc3 / calc0 << ':' << int(getDist()) % calc3 % calc0 << "[h:m:s]" << endl;
    }
};

class Swimming : public Sports
{
private:
    double swimdata;

public:
    Swimming(double distance, double time) : Sports(distance, time)
    {
    }
    Swimming() : Sports(distance, time)
    {
        swimdata = 0.0;
    }
    ~Swimming()
    {
    }
    void computeSaveAndPrintAverage()
    {
        swimdata = time / (distance / calc1);
        // cout << "Az uszas atlaga: " << swimdata << " s / 100 m" << endl;
    }
    string getNameOfSports()
    {
        return "Uszas";
    }
    double getAverage()
    {
        return swimdata;
    }
};

class Cycling : public Sports
{
private:
    double cycldata;

public:
    Cycling(double distance, double time) : Sports(distance, time)
    {
    }
    Cycling() : Sports(distance, time)
    {
        cycldata = 0.0;
    }
    ~Cycling()
    {
    }
    void computeSaveAndPrintAverage()
    {
        cycldata = (distance / calc2) / (time / calc3);
        // cout << "A kerekparozas atlaga: " << cycldata << " s / 100 m" << endl;
    }
    string getNameOfSports()
    {
        return "Kerekpar";
    }
    double getAverage()
    {
        return cycldata;
    }
};

class Running : public Sports
{
private:
    double rundata;

public:
    Running(double distance, double time) : Sports(distance, time)
    {
    }
    Running() : Sports(distance, time)
    {
        rundata = 0.0;
    }
    ~Running()
    {
    }
    void computeSaveAndPrintAverage()
    {
        rundata = (time / calc0) / (distance / calc2);
        // cout << "A futas atlaga: " << rundata << " s / 100 m" << endl;
    }
    string getNameOfSports()
    {
        return "Futas";
    }
    double getAverage()
    {
        return rundata;
    }
};

void felszabadit(Sports *torol)
{
    delete torol;
    torol = 0;
}

// Harmas szint
void printNamesOfSports(vector<Sports *> check)
{
    cout << endl;
    for (auto i : check)
    {
        if (Swimming *swp = dynamic_cast<Swimming *>(i))
            cout << swp->getNameOfSports() << endl;
        else if (Cycling *cp = dynamic_cast<Cycling *>(i))
            cout << cp->getNameOfSports() << endl;
        else if (Running *runp = dynamic_cast<Running *>(i))
            cout << runp->getNameOfSports() << endl;
    }
}

// Negyes szint
void printAverages(vector<Sports *> check)
{
    cout << endl;
    int counter = 0;
    for (auto i : check)
    {
        if (counter < 2)
            cout << i->getAverage() << " - ";
        else
            cout << i->getAverage() << endl;
        counter++;
    }
}