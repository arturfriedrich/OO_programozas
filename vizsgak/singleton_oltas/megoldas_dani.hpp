#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Oltas
{
    string name;

public:
    Oltas(const string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    virtual string getType() = 0;
};

class Pfizer : public Oltas
{
    // Call mother constructor

    Pfizer(const string name) : Oltas(name) {}

    // Disable copy constructor and copy assigment => singleton

    Pfizer() = delete;
    Pfizer(const Pfizer &other) = delete;
    Pfizer &operator=(const Pfizer &other) = delete;
    static Pfizer *instance;

public:
    static Oltas *GetInstance()
    {
        static Pfizer instance("Pfizer");
        return &instance;
    }
    string getType()
    {
        return "mRNA";
    }
};

class Sinovac : public Oltas
{
    // Call mother constructor

    Sinovac(const string name) : Oltas(name) {}

    // Disable copy constructor and copy assigment => singleton

    Sinovac() = delete;
    Sinovac(const Sinovac &other) = delete;
    Sinovac &operator=(const Sinovac &other) = delete;
    static Sinovac *instance;

public:
    static Oltas *GetInstance()
    {
        static Sinovac instance("Sinovac");
        return &instance;
    }
    string getType()
    {
        return "adenovirus";
    }
};

class OltasiIgazolas
{
    vector<Oltas *> oltasok;

public:
    OltasiIgazolas(const vector<Oltas *> &oltasok)
    {
        this->oltasok = oltasok;
    }
    int getCount(Oltas *whichOltas)
    {
        int count = 0;
        for (Oltas *iterator : oltasok)
        {
            if (iterator == whichOltas)
            {
                count++;
            }
        }
        return count;
    }
};

typedef pair<Oltas *, int> Kovetelmeny;
typedef vector<Kovetelmeny> Kovetelmenyek;