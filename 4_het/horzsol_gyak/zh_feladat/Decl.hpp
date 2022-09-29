#pragma once
#include <iostream>

using namespace std;

class tri_race {                    /* az osztály deklarációja */
    private:
        string licensz;
        int uszas, bicikli, futas, depo, ij;
        int sum, o, p, mp;
        const int ora, perc;
    public:
        tri_race() : ora(3600), perc(60) {
            licensz = "--------"; uszas = 0; bicikli = 0; futas = 0; depo = 0; ij = 0; sum = 0; o = 0; p = 0; mp = 0;
        }
        tri_race(string licensz_, int uszas_, int bicikli_, int futas_, int depo_, int ij_) : ora(3600), perc(60) {
            licensz = licensz_; uszas = uszas_; bicikli = bicikli_; futas = futas_; depo = depo_; ij = ij_;
            sum = 0; o = 0; p = 0; 
        }
        int getIj() const { return ij; }
        tri_race& kiir_rajt();
        tri_race& kiir_cel();
        tri_race& setSum(int t);
        ~tri_race() {
            cout << "Felszabadítottam az objektum memóriacímét!" << endl;
        }
};