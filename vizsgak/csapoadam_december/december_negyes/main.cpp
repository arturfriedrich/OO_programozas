#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

#include "negyes.hpp"

int main()
{
    static_assert(std::is_abstract<EtlapElem>(), "Hiba! EtlapElem osztaly nem absztrakt!");

    Etlap e1;
    e1.hozzaad(new Leves("Magocskas leves", 450));
    e1.hozzaad(new Leves("Frankfurti leves", 800));
    e1.hozzaad(new Foetel("Paprikas csirke", "rizs", 1200));

    Etlap e2(e1);
    e2.hozzaad(new Foetel("Paprikas csirke", "hasabburgonya", 1500));

    e2.print();

    return 0;
}