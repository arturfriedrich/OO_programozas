#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

#include "harmas.hpp"

int main()
{
    static_assert(std::is_abstract<EtlapElem>(), "Hiba! EtlapElem osztaly nem absztrakt!");     // ellenőrzi, hogy a megadott osztály absztrakt-e
    EtlapElem *ee1 = new Leves("Magocskas leves", 450);                         // példányosítás
    EtlapElem *ee2 = new Leves("Frankfurti leves", 800);
    EtlapElem *ee3 = new Foetel("Paprikas csirke", "rizs", 1200);
    EtlapElem *ee4 = new Foetel("Paprikas csirke", "hasabburgonya", 1500);
    ee1->print();           // a példányosított osztáylokat kiírja
    ee2->print();
    ee3->print();
    ee4->print();

    delete ee1;             // felszabadítja a memóriát
    delete ee2;
    delete ee3;
    delete ee4;
    return 0;
}