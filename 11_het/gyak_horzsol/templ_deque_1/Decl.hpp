#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

deque<int> hpmp(3);
deque<int>::iterator ke; // un. "bejárók", az elemek címzéséhez 

// komparátor/predikátum (összehasonlító/tulajdonság hozzárendelő) függvény
bool hasonlit(int i, int j) { return i<j; } 
bool szuro (int i) { return ((i%2)==1 or (i%2)==-1); }
bool szuro2 (int i) { return ((i%2)==0 and i!=0); }