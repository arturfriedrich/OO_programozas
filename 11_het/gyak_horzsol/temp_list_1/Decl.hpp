#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

list<int> hpmp(3);
list<int>::iterator ke; // un. "bejárók", az elemek címzéséhez 

// komparátor/predikátum (összehasonlító/tulajdonság hozzárendelő) függvény
bool hasonlit(int i, int j) { return i<j; } 
bool szuro (int i) { return ((i%2)==1 or (i%2)==-1); }
bool szuro2 (int i) { return ((i%2)==0 and i!=0); }