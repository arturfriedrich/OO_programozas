// OOP-gyakorlat-13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "registry.h" // ez a header meg include-olja az election.h-t is

void f() {
    ValasztasiJegyzek vj; // VotingRegistry

    vj.addValaszto(new Valaszto("Paul Szabo", "New York City", 41, 103410));
    vj.addValaszto(new Valaszto("Aaron Rosenfeldt", "Syracuse", 32, 444512));
    vj.addValaszto(new Valaszto("Sarah Smith", "Buffalo", 24, 471832));
    vj.addValaszto(new Valaszto("Carla Boyce", "Rochester", 22, 471832)); // same id!
    vj.printValasztok();

    Valasztas election2020("Valasztas-2020", 3); // jeloltek szama
    vj.initializeValasztas(election2020);

    Valasztas referendum2020("Nepszavazas-2020", 2); // jeloltek szama
    vj.initializeValasztas(referendum2020);
    vj.initializeValasztas(referendum2020);

    //// ezutan valami ilyesmi lesz:
    vj.szavaz(471832, election2020, 1); // adott id-ju szavazo adott valasztason adott jeloltre szavaz
    vj.szavaz(999999, election2020, 2); // ilyen id-ju szavazo nincs!!
    vj.szavaz(471832, election2020, 1); // 2x nem lehet szavazni!!
    vj.szavaz(444512, election2020, 2);
    vj.szavaz(103410, election2020, 2);

    // Feladat: ez is mukodjon!
    vj.szavaz(471832, referendum2020, 1);
    vj.szavaz(444512, referendum2020, 0);
    vj.szavaz(103410, referendum2020, 0);

    // Feladat: akkor is ok ha nincs regisztralva ilyen valasztas!
    Valasztas something2020("nincs-regisztralva", 2); // jeloltek szama
    vj.szavaz(471832, something2020, 1);
    vj.szavaz(444512, something2020, 0);
    vj.szavaz(103410, something2020, 0);

    election2020.eredmenyHirdetes();
    referendum2020.eredmenyHirdetes();
    something2020.eredmenyHirdetes();
}

int main()
{
    char c;
    for (int i = 0; i < 10; i++) {
        f(); // ha f kilep, a mem.nek fel kell szabadulnia!
        std::cin >> c; // heap profiling celjabol!
    }
}
