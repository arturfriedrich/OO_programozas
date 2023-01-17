#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

class Oktato
{
    protected:
        std::string lastName, firstName;
    public:
        Oktato(std::string lastName, std::string firstName) : lastName(lastName), firstName(firstName) { }
        virtual ~Oktato() { }
        virtual void print() = 0;
};

class Professzor : public Oktato
{
    public:
        Professzor(std::string lastName, std::string firstName) : Oktato(lastName, firstName) { }
        void print() {
            std::cout << "Professzor: " << lastName << ", " << firstName << std::endl;
        }
};

class Tanarseged : public Oktato
{
    public:
        Tanarseged(std::string lastName, std::string firstName) : Oktato(lastName, firstName) { }
        void print() {
            std::cout << "Tanarseged: " << lastName << ", " << firstName << std::endl;
        }
};