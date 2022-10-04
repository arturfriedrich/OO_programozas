#pragma once
#include <iostream>

using namespace std;

class tri_race {                    /* az osztály deklarációja */
    private:                        
        /* privát változók, ezeket csak a class-on belül lehet elérni */
        string licensz;
        int uszas, bicikli, futas, depo, ij;
        int sum, o, p, mp;
        const int ora, perc;
    public:                         
        /* publikus változók, ezeket el lehet és el is kell érni a class-on kívül is */
        /* itt deklarálom az első versenyzőt */
        tri_race() : ora(3600), perc(60) {
            licensz = "--------"; uszas = 0; bicikli = 0; futas = 0; depo = 0; ij = 0; sum = 0; o = 0; p = 0; mp = 0;
        }
        /* itt deklaráljuk a többi versenyzőt, azok az adatok alapján amit a példányosításnál kapunk */
        tri_race(string licensz_, int uszas_, int bicikli_, int futas_, int depo_, int ij_) : ora(3600), perc(60) {
            /* a példányosításban megadott értékek itt lesznek egyenlőek a class privát részében definiált tagváltozókkal */ 
            licensz = licensz_; uszas = uszas_; bicikli = bicikli_; futas = futas_; depo = depo_; ij = ij_;
            sum = 0; o = 0; p = 0; 
        }
        /* deklaráljuk az általunk használni kívánt függvényeket és eljárásokat */
        int getIj() const { return ij; }
        tri_race& kiir_rajt();
        tri_race& kiir_cel();
        tri_race& setSum(int t);
        /* még pontosítást igényel, de ha minden igaz ez az operátor biteket flippel */
        ~tri_race() {
            cout << "Felszabadítottam az objektum memóriacímét!" << endl;
        }
};