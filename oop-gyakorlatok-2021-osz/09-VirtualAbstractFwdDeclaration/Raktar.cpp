// Raktar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Raktar osztaly:
// TermekCsalad tipusu pointereket tarol el
// TermekCsalad legyen absztrakt osztaly!
// mindegyik termekhez szamon tart mennyiseget (hibatlan es hibas darabszam)
// A termek lehet garancialis v. csereszavatos (csere garancialis?)
// ezen belul legyen Laptop, Mobilkeszulek

// A raktar kiad(TermekCsalad*, dbszam) metodusa csokkenti a hibatlan darabok szamat
// A raktar visszavesz(TermekCsalad*) metodusa meghivja a TermekCsalad osztaly
// javit(Raktar*) pure virtual metodusat es attol fuggoen hogy a termek milyen
// tipusu, a Raktarban megnovekedhet a hibas darabok szama es csokkenhet a
// hibatlan darabok szama, vagy: nem valtozik semmi mert javitjak garancialisan

#include <iostream>
#include <string>
#include <vector>

#include "termekek.h"
#include "raktarak.h"

void f() {
    Raktar* r = new Raktar;
    Laptop l1("ASUS TUF Gaming", 2020);
    Laptop l2("Lenovo Legion Y520", 2018);
    Mobilkeszulek m1("Xperia Hypersuper", 2019);
    r->add(&l1, 2).add(&l2, 3).add(&m1, 4);
    r->print();
    std::cout << "-----" << std::endl;

    r->kiad(&l1, 2);
    r->kiad(&l2, 1);
    r->kiad(&m1, 3);
    r->print();
    std::cout << "-----" << std::endl;

    r->visszavesz(&l1, 1);
    r->visszavesz(&m1, 1);
    r->print();
    std::cout << "-----" << std::endl;

    delete r;
    // breakpoint es memory snapshot:
    std::cout << "bye bye raktar!" << std::endl;
}

int main()
{
    for (int i = 0; i < 10; i++) {
        std::cout << i + 1 << std::endl; // ide breakpoint!
        f();
    }


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
