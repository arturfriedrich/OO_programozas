#include <iostream>
#include <string>
#include <vector>
using namespace std;

//#include "/home/szeke/projects/sze_oo_programozas/mintavizsga/2022-01/megoldas_dorian.hpp"
#include "/home/g14/uni/sze_oo_programozas/mintavizsga/2022-01/megoldas_dani.hpp"

/* ####Kettesért####
Keszitse el a "Sports(distance, time)", "Swimming(distance,time)", "Cycling(distance,time)", "Running(distance,time)" osztalyokat ugy, hogy az alabbi kod forduljon.

Az argumentum-listakban a tavolsagok meterben, az idok masodpercben vannak megadva.

A képletekben ne literalokat (konkret valtoszamokat, mint 100, vagy 3600), hanem konstans tagvaltozokat hasznaljon!

Az atlagok kiszamitasahoz szukseges kepletek, literalokkal:

    - uszasnal (mp / meter) kiszamitasa: time / (distance / 100)
    - bicajnal (km / ora) kiszamitasa: (distance / 1000) / (time / 3600)
    - futasnal (perc / km) kiszamitasa: (time / 60) / (distance / 1000)

Elvárt kimenet 2 - es jegyert :

Az uszas atlaga: 96.0667 s / 100 m
A kerekparozas atlaga: 29.9938 km / h
A futas atlaga: 4.00167 min / km
*/

/* ####Hármasért####
    - irassa ki az osztalyokban eltarolt atlagokat az alabbi sorrendben:

    Az uszas atlaga: 96.0667 s / 100 m
    A kerekparozas atlaga: 29.9938 km / h
    A futas atlaga: 4.00167 min / km
    96.0667 - 29.9938 - 4.00167
*/

/* ####Négyesért####
- irassa ki mindegyik sportag nevet is az atlagok utan a kovetkezo modon (ez legyen a kimenet):

    Az uszas atlaga: 96.0667 s / 100 m
    A kerekparozas atlaga: 29.9938 km / h
    A futas atlaga: 4.00167 min / km
    Uszas
    Kerekpar
    Futas
*/

//----------------------------------------------------------

int main()
{

    Sports *sp1 = new Swimming(1500, 1441);
    Sports *sp2 = new Cycling(40000, 4801);
    Sports *sp3 = new Running(10000, 2401);

    sp1->computeSaveAndPrintAverage();
    sp2->computeSaveAndPrintAverage();
    sp3->computeSaveAndPrintAverage();

    vector<Sports *> allSports = {sp1, sp2, sp3}; // HÁRMASÉRT
    printAverages(allSports);

    //vector<Sports *> allSports = {sp1, sp2, sp3}; // NÉGYESÉRT
    printNamesOfSports(allSports);

    delete sp1;
    delete sp2;
    delete sp3;
}