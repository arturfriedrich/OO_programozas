// 2019-vizsgafeladat-1.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include "megoldas/csapo/termekek.h"

// a megoldott feladatoknal allitsa 1-re a megfelelo pelda kodreszek bekapcsolasahoz
#define KETTES_SZINT 1
#define HARMAS_SZINT 1
#define NEGYES_SZINT 1
#define OTOS_SZINT 1

int main()
{
#if KETTES_SZINT

  // van ketfele termek: Laptop es Mobil
  // Termek absztrakt ososztaly, uh nem peldanyosithato:
  // Termek t("Gyarto", 2);
  Termek *laptop = new Laptop("Asus", 1000);
  Termek *mobil1 = new Mobil("Samsung", 80, "15-372612-847221-1");
  Termek *mobil2 = new Mobil("Samsung", 800, "62-882612-847221-1");
  Termek *mobil3 = new Mobil("Apple", 3000, "75-262612-847221-1");

  // Keszlet keszlet; // nem mukodik mert Keszlet singleton
  Keszlet *keszlet = Keszlet::GetInstance(); // GetInstance statikus valtozot hoz letre es ad vissza
  // Keszlet keszlet2 = *keszlet; // nem mukodik mert copy es assignment le van tiltva
  // Keszlet keszlet2(*keszlet); // nem mukodik, mert copy le van tiltva
  Keszlet *keszlet2 = Keszlet::GetInstance(); // mivel statikus valtozot ad vissza, csak 1x hozza letre
  if (keszlet == keszlet2)
  {
    std::cout << "Eljen eljen: ugyanaz a cim!!" << std::endl;
  }
  keszlet->addTermek(laptop, 15);
  keszlet->addTermek(mobil1, 9);
  keszlet->addTermek(mobil2, 23);

  std::cout << laptop->getName() << " " << keszlet->getQuantity(laptop) << " mennyisegben all rendelkezesre" << std::endl; // 15
  std::cout << mobil3->getName() << " " << keszlet->getQuantity(mobil3) << " mennyisegben all rendelkezesre" << std::endl; // 0

#if HARMAS_SZINT
  std::cout << "done" << std::endl;

  if (keszlet->getQuantity(laptop) > 5)
  {
    keszlet->rendel(laptop, 5);
    std::cout << laptop->getName() << " mar csak " << keszlet->getQuantity(laptop) << " mennyisegben all rendelkezesre" << std::endl; // 10
  }

#if NEGYES_SZINT
  try
  {
    keszlet->checkedRendel(laptop, 12);
  }
  catch (OutOfKeszletError e)
  {
    std::cout << e.getMsg() << std::endl; // kiirja h "nincs tobb a keszleten"
  }

#if OTOS_SZINT
  // u.az mint mobil2
  Termek *mobil4 = new Mobil("Samsung", 800, "62-882612-847221-1");
  // egyszer mar hozzadtunk mobil2-bol 23-at:
  keszlet->addTermekChecked(mobil4, 5); // vajon most 28 van belole?
  // az implementaciohoz operator== fv megvalositasa szukseges
  // + okosabb getQuantity is kell...
  std::cout << mobil4->getName() << " " << keszlet->getQuantity(mobil4) << " mennyisegben all rendelkezesre" << std::endl; // 28

  delete mobil4;
#endif

#endif

#endif

  delete laptop;
  delete mobil1;
  delete mobil2;
  delete mobil3;

#endif
  std::cin.get();
  return 0;
}
