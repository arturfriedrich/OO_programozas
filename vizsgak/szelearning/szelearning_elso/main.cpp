#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

#include "elso.hpp"

int main()
{
    std::vector<Oktato*> oktatok;

    static_assert(std::is_abstract<Oktato>(), "Hiba! Oktato osztaly nem absztrakt!");

    Oktato* tanar1 = new Professzor("Nagy", "Agnes");
    Oktato* tanar2 = new Tanarseged("Kis", "Bela");
    
    oktatok.push_back(tanar1);
    oktatok.push_back(tanar2);

    for (Oktato* op : oktatok) {
        op->print();
    }

    delete tanar1;
    delete tanar2;

    return 0;
}