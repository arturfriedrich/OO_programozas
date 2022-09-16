#include <iostream>
#include <string>

using namespace std;

class Hallgato {
    string nev;
    string neptunkod;
    public:
        Hallgato(string neve, string neptunkodja) {         // Konstruktor
            nev = neve;
            neptunkod = neptunkodja;
        }
        void print() {
            cout << nev << " - " << neptunkod << endl;
        }
};