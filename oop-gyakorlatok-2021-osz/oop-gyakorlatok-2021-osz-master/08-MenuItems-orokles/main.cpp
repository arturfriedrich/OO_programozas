// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "menu.h"

int main()
{
    int main()
{
    MenuItem item1("Coca cola", 1.5);
    MenuItem item2("Lemonaade, 0.5L", 1);
    DiscountedItem item3("Soproni Aszok, 0.33L", 1.2, 0.7);
    Buy1Get1Free item4("Arizona Iced Tea, 0.5L", 2.3);
    Buy1Get1Free item5("Balatonic Classic, 0.5L", 2.0);
    Buy1Get1Free item6("HB Munchen Buza, 0.5L", 2.5);
    Menu m;
    m.addItem(&item1);
    m.addItem(&item2);
    m.addItem(&item3);
    m.addItem(&item4);
    m.addItem(&item5);
    m.addItem(&item6);
    m.print();

    std::cout << std::endl << " ---" << std::endl;

    Rendeles r;
    r.rendel(&m, 1);
    r.rendel(&m, 3);
    r.rendel(&m, 4);
    r.rendel(&m, 4);
    r.rendel(&m, 5);
    r.rendel(&m, 6);
    r.fizet();
}
