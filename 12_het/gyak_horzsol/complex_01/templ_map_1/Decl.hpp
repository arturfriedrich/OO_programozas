#include <iostream>
#include <map> // asszociatív tömb
#include <algorithm>

using namespace std;

typedef pair<string, int> sps;      // ez egy osztály, objektum, nem konténer, struktúra sablon, amit be tudok építeni egy konténerbe vagy map-be
map<string, int> hpmp;              // asszociatív tömb létrehozása, kulcsokon keresztül lehet elérni az adatokat
map<string, int>::iterator ke;      // a string a kulcs, az int az adat