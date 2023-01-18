#include <iostream>
using namespace std;

class Sports
{
protected:
    const int cacl0 = 60;
    const int calc1 = 100;
    const int calc2 = 1000;
    const int calc3 = 3600;

    double time;
    double distance;

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
        cout << "Az uszas atlaga: " << swimdata << " s / 100 m" << endl;
    }
    string getNameOfSports()
    {
        return "Uszas";
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
        cout << "A kerekparozas atlaga: " << cycldata << " s / 100 m" << endl;
    }
    string getNameOfSports()
    {
        return "Kerekpar";
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
        cout << "A futas atlaga: " << rundata << " s / 100 m" << endl;
    }
    string getNameOfSports()
    {
        return "Futas";
    }
};

void felszabadit(Sports *torol)
{
    delete torol;
    torol = 0;
}

/*
void printNamesOfSports(Sports *sportname) //Version 1
{
    cout << sportname->getNameOfSports() << endl;
}
*/

/*
void printNamesOfSports(Sports *check) // Version 2
{
    cout << endl;
    check->getNameOfSports();
    Sports *ptr = dynamic_cast<Sports *>(check);
    if (ptr != nullptr)
        cout << ptr->getNameOfSports();
    else
        cout << "Hiba!\n Nem gyerek osztály!" << endl;
}
*/
/*
void printNamesOfSports(Sports *check) // Version 3
{
    cout << endl;
    check->getNameOfSports();
    Swimming *ptr = dynamic_cast<Swimming *>(check);
    if (ptr != nullptr)
        cout << ptr->getNameOfSports();
    else
    {
        Cycling *ptr = dynamic_cast<Cycling *>(check);
        if (ptr != nullptr)
            cout << ptr->getNameOfSports();
        else
        {
            Running *ptr = dynamic_cast<Running *>(check);
            if (ptr != nullptr)
                cout << ptr->getNameOfSports();
            else
                cout << "Hiba!\n Nem gyerek osztály!" << endl;
        }
    }
}
*/
/*
void printNamesOfSports(Sports *check) // Version 4
{
    cout << endl;
    if (Swimming *swp = dynamic_cast<Swimming *>(check))
        cout << "Uszas" << endl;
    else if (Cycling *cp = dynamic_cast<Cycling *>(check))
        cout << "Kerekpar" << endl;
    else if (Running *runp = dynamic_cast<Running *>(check))
        cout << "Futas" << endl;
}
*/

void printNamesOfSports(Sports *check) // Version 5
{
    cout << endl;
    if (Swimming *swp = dynamic_cast<Swimming *>(check))
        cout << swp->getNameOfSports() << endl;
    else if (Cycling *cp = dynamic_cast<Cycling *>(check))
        cout << cp->getNameOfSports() << endl;
    else if (Running *runp = dynamic_cast<Running *>(check))
        cout << runp->getNameOfSports() << endl;
}