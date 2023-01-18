// OOP Próba vizsgaZh

#include "/home/g14/uni/sze_oo_programozas/gyakorlati_orak/horzsol/minta_vizsga_2/megoldas_dani.hpp"

int main()
{
    // Keszitse el a "Sports", "Swimming(distance,time)", "Cycling(distance,time)", "Running(distance,time)"
    // osztalyokat ugy, hogy az alabbi kod forduljon.
    // Az argumentum-listakban a tavolsagok meterben, az idok masodpercben vannak megadva.

    // A képletekben ne literalokat (konkret valtoszamokat, mint pl.: 100, vagy 3600), hanem konstans tagvaltozokat hasznaljon!
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
    // A kerekparozas atlaga: 32.3523 km / h
    // A futas atlaga: 4.0017 min / km

    // A 3-as jegyert irassa ki a sportagak neveit egymas ala, az argumentum alapjan.

    printNamesOfSports(sp1);
    printNamesOfSports(sp2);
    printNamesOfSports(sp3);

    // Az elvart kimenet a 3-as jegyert:
    //
    // Uszas
    // Kerekpar
    // Futas

    delete sp1;
    delete sp2;
    delete sp3;

    return 0;
}