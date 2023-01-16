#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

#include "harmas.hpp"

int main()
{
    static_assert(std::is_abstract<EtlapElem>(), "Hiba! EtlapElem osztaly nem absztrakt!");

    Etlap e1;       // létrehozza az Etlap menű vektort
    e1.hozzaad(new Leves("Magocskas leves", 450));              // hozzáadja az elemeket  hozzaad() metódussal
    e1.hozzaad(new Leves("Frankfurti leves", 800));
    e1.hozzaad(new Foetel("Paprikas csirke", "rizs", 1200));

    Etlap e2(e1);   // a második étlapot létrehozza, és azonnal meg is adja neki az elsőt
    e2.hozzaad(new Foetel("Paprikas csirke", "hasabburgonya", 1500));

    e2.print();     // kiírja a második étlapot

    return 0;
}