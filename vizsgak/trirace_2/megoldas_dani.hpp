#pragma once
#include <iostream>
#include <vector>
using namespace std;

// Kettes szint
class Sports
{
protected:
    const int cacl0 = 60;
    const int calc1 = 100;
    const int calc2 = 1000;
    const int calc3 = 3600;
    double time;
    double distance;
    // vector<Sports *> Averages;

public:
    Sports(int distance, int time)
    {
        this->distance = distance;
        this->time = time;
    }
    Sports()
    {
        distance = 0;
        time = 0;
    }
    virtual ~Sports()
    {
    }
    virtual void computeSaveAndPrintAverage() = 0;
    virtual string getNameOfSports() = 0;
    virtual double getAverage() = 0;
};

class Swimming : public Sports
{
private:
    double swimdata;

public:
    Swimming(int distance, int time) : Sports(distance, time)
    {
    }
    Swimming() : Sports(distance, time)
    {
        swimdata = 0;
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
    Cycling(int distance, int time) : Sports(distance, time)
    {
    }
    Cycling() : Sports(distance, time)
    {
        cycldata = 0;
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
    Running(int distance, int time) : Sports(distance, time)
    {
    }
    Running() : Sports(distance, time)
    {
        rundata = 0;
    }
    ~Running()
    {
    }
    void computeSaveAndPrintAverage()
    {
        rundata = (time / cacl0) / (distance / calc2);
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