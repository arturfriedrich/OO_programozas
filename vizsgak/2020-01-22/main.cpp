#include <iostream>

//#include "megoldas/csapo/lakokozosseg.h"
#include "/home/szeke/projects/sze_oo_programozas/mintavizsga/2020-01-22/megoldas_dani.hpp"

#define SZINT_2 1
#define SZINT_3 0
#define SZINT_4 0
#define SZINT_5 0

int main()
{
#if SZINT_2

  Tarstulajdonos *tulaj1 = new BekesTulajdonos("Kisimult P.", 1230);
  Tarstulajdonos *tulaj2 = new PereskedoTulajdonos("Veszekedo I.", 2660);
  Tarstulajdonos *tulaj3 = new BekesTulajdonos("Okos B.", 370);
  Tarstulajdonos *tulaj4 = new BekesTulajdonos("Sima O.", 1050);
  Tarstulajdonos *tulaj5 = new BekesTulajdonos("Rendes C.", 230);
  Tarstulajdonos *tulaj6 = new BekesTulajdonos("Aranyos K.", 410);
  Tarstulajdonos *tulaj7 = new PereskedoTulajdonos("Goromba B.", 970);
  Tarstulajdonos *tulaj8 = new PereskedoTulajdonos("Kiabalos H.", 1220);
  Tarstulajdonos *tulaj9 = new PereskedoTulajdonos("Duhongo K.", 1020);
  Tarstulajdonos *tulaj10 = new PereskedoTulajdonos("Baratsagtalan P.", 320);
  Tarstulajdonos *tulaj11 = new BekesTulajdonos("Baratsagos A.", 520);

  Tarsashaz chicago;
  chicago.addTulajdonos(tulaj1);
  chicago.addTulajdonos(tulaj2);
  chicago.addTulajdonos(tulaj3);
  chicago.addTulajdonos(tulaj4);
  chicago.addTulajdonos(tulaj5);
  chicago.addTulajdonos(tulaj6);
  chicago.addTulajdonos(tulaj7);
  chicago.addTulajdonos(tulaj8);
  chicago.addTulajdonos(tulaj9);
  chicago.addTulajdonos(tulaj10);
  chicago.addTulajdonos(tulaj11);

  Kozgyules kgy1(2019, 5, 12);
  chicago.holdKozgyules(&kgy1);
  kgy1.printJelenlevok(); // minden 3. bekes, es minden 2. pereskedo tulajdonos reszt vesz
  // Kiirja, hogy:
  // Bekes tulajdonos : Sima O. - 1050 / 10 000
  // Pereskedo tulajdonos : Goromba B. - 970 / 10 000
  // Pereskedo tulajdonos : Duhongo K. - 1020 / 10 000
  std::cout << " ---------------------------- " << std::endl;
  std::cout << " Elvart kimenet:" << std::endl;
  std::cout << " Bekes tulajdonos : Sima O. - 1050 / 10 000" << std::endl;
  std::cout << " Pereskedo tulajdonos : Goromba B. - 970 / 10 000" << std::endl;
  std::cout << " Pereskedo tulajdonos : Duhongo K. - 1020 / 10 000" << std::endl;
  std::cout << " Bekes tulajdonos: Baratsagos A. - 520 / 10 000" << std::endl;
  std::cout << std::endl
            << std::endl
            << std::endl;

#if SZINT_3

  kgy1.printLetszam(); // kiirja, hogy Letszam: 3040
  std::cout << " ---------------------------- " << std::endl;
  std::cout << " Elvart kimenet:" << std::endl;
  std::cout << " Letszam: 3560" << std::endl;
  std::cout << std::endl
            << std::endl
            << std::endl;

#if SZINT_4

  Kozgyules kgy2(2020, 1, 12);
  chicago.holdKozgyules(&kgy2);
  Meghatalmazas meghati1(tulaj1, tulaj4);
  Meghatalmazas meghati2(tulaj3, tulaj4);
  kgy2.submitMeghatalmazas(&meghati1);
  kgy2.submitMeghatalmazas(&meghati2);
  kgy2.printJelenlevokWithProxies(); // minden 3. bekes, es minden 2. pereskedo tulajdonos reszt vesz
  // viszont most mar Sima O.-nak joval tobb tulajdoni hanyada van!!
  // azt kell kiirnia, hogy:
  // Bekes tulajdonos: Sima O. - 2650 / 10 000
  // Pereskedo tulajdonos : Goromba B. - 970 / 10 000
  // Pereskedo tulajdonos : Duhongo K. - 1020 / 10 000
  std::cout << " ---------------------------- " << std::endl;
  std::cout << " Elvart kimenet:" << std::endl;
  std::cout << " Bekes tulajdonos: Sima O. - 2650 / 10 000" << std::endl;
  std::cout << " Pereskedo tulajdonos : Goromba B. - 970 / 10 000" << std::endl;
  std::cout << " Pereskedo tulajdonos : Duhongo K. - 1020 / 10 000" << std::endl;
  std::cout << " Bekes tulajdonos: Baratsagos A. - 520 / 10 000" << std::endl;
  std::cout << std::endl
            << std::endl
            << std::endl;

#if SZINT_5
  PereskedoTulajdonos *newPereskedo1 = new PereskedoTulajdonos("Vendeg a szomszedbol", 0);
  PereskedoTulajdonos *newPereskedo2 = new PereskedoTulajdonos("Vendeg a szomszedbol felesege", 0);
  newPereskedo1->orditozik(&kgy2);
  newPereskedo2->orditozik(&kgy2);

  Kozgyules kgy3(2020, 02, 13);
  chicago.setPreviousKozgyules(&kgy2);
  chicago.holdKozgyules(&kgy3);
  kgy3.printJelenlevok(); // minden 4. bekes, es minden 2. pereskedo tulajdonos reszt vesz
  std::cout << " ---------------------------- " << std::endl;
  std::cout << " Elvart kimenet:" << std::endl;
  std::cout << " Bekes tulajdonos : Rendes C. - 230 / 10 000" << std::endl;
  std::cout << " Pereskedo tulajdonos : Goromba B. - 970 / 10 000" << std::endl;
  std::cout << " Pereskedo tulajdonos : Duhongo K. - 1020 / 10 000" << std::endl;
  std::cout << std::endl
            << std::endl
            << std::endl;

  delete newPereskedo1;
  delete newPereskedo2;
#endif

#endif

#endif

  delete tulaj1;
  delete tulaj2;
  delete tulaj3;
  delete tulaj4;
  delete tulaj5;
  delete tulaj6;
  delete tulaj7;
  delete tulaj8;
  delete tulaj9;
  delete tulaj10;

#endif

  std::cin.get();
  return 0;
}
