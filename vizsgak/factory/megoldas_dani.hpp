#include <type_traits>
#include <string>
#include <iostream>
using namespace std;

class Device
{
private:
    string name;

public:
    Device(string name)
    {
        this->name = name;
    }

    virtual void print() = 0;

    string getName()
    {
        return name;
    }
};

class Computer : public Device
{
public:
    Computer(string nev) : Device(nev) {} // Use ructor of Device
    void print()
    {
        cout << getName() << " gep vagyok" << endl;
    }
};

class Laptop : public Device
{
private:
    string megjegyzes;

public:
    Laptop(string nev) : Device(nev) {} // Use ructor of Device
    void print()
    {
        cout << getName() << " laptop vagyok (";
        cout << megjegyzes << ")" << endl;
    }
    void extraMegjegyzesek(string megjegyzes)
    {
        this->megjegyzes = megjegyzes;
    }
};

// Easy implementation to tell class type by "DeviceType::Computer OR DeviceType::Laptop"
enum class DeviceType
{
    Computer,
    Laptop
};

class DeviceFactory
{
public:
    static Device *NewDevice(DeviceType type, string name)
    {
        if (type == DeviceType::Computer)
        {
            return new Computer(name);
        }
        else if (type == DeviceType::Laptop)
        {
            Laptop *laptop = new Laptop(name);
            laptop->extraMegjegyzesek("Factory altal krealt laptop!");
            return laptop;
        }
        else
        {
            cout << "Ilyen tipusu device nincs!!";
            return nullptr;
        }
    }
};