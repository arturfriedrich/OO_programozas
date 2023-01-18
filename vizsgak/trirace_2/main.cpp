#include <iostream>
#include <vector>
#include "/home/g14/uni/sze_oo_programozas/mintavizsga/minta_vizsga_4/megoldas_dani.hpp"
using namespace std;

int main()
{
    // Keszitse el a "Sports", "Swimming(distance,time)", "Cycling(distance,time)", "Running(distance,time)"
    // osztalyokat ugy, hogy az alabbi kod forduljon.
    // Az argumentum-listakban a tavolsagok meterben, az idok masodpercben vannak megadva.

    // A képletekben ne literalokat (konkret valtoszamokat, mint 100, vagy 3600), hanem konstans tagvaltozokat hasznaljon!
    // Az atlagok kiszamitasahoz szukseges kepletek, literalokkal:
    //  - uszasnal (mp / meter) kiszamitasa: time / (distance / 100)
    //  - bicajnal (km / ora) kiszamitasa: (distance / 1000) / (time / 3600)
    //  - futasnal (perc / km) kiszamitasa: (time / 60) / (distance / 1000)

    Sports *sp1 = new Swimming(1500, 1441);
    Sports *sp2 = new Cycling(40000, 4451);
    Sports *sp3 = new Running(10000, 2401);

    // a computeSaveAndPrintAverage kiszamitja az atlagot, eltarolja egy tagvaltozoban majd kiirja a konzolra
    sp1->computeSaveAndPrintAverage();
    sp2->computeSaveAndPrintAverage();
    sp3->computeSaveAndPrintAverage();

    // Az elvart kimenet a 2-es jegyert:
    //
    // Az uszas atlaga: 96.0667 s / 100 m
    // A kerekparozas atlaga: 29.9938 km / h
    // A futas atlaga: 4.00167 min / km

    // A 3-as jegyert:
    //  - irassa ki az osztalyokban eltarolt atlagokat az alabbi sorrendben:

    vector<Sports *> allSports = {sp1, sp2, sp3};
    printAverages(allSports);

    // Az elvart kimenet a 3-as jegyert:
    //
    // 96.0667 - 32.3523 - 4.00167

    // A 4-es jegyért irassa ki a sportagak neveit egymas ala, az argumentum alapjan.

    printNamesOfSports(allSports);

    // Az elvart kimenet a 4-es jegyert:
    //
    // Uszas
    // Kerekpar
    // Futas

    delete sp1;
    delete sp2;
    delete sp3;

    return 0;
}