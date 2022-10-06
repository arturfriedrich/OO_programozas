#pragma once                        /* csak egyszer linkelje be a headert a projektbe */
#include <iostream>

using namespace std;

class tri_race {                    /* az osztály deklarációja */
    private:                        
        /* privát tagváltozók, ezeket csak a class-on belül lehet elérni */
        string licensz;
        int uszas, bicikli, futas, depo, ij;
        int sum, o, p, mp;
        const int ora, perc;
    public:                         
        /* publikus változók, ezeket el lehet és el is kell érni a class-on kívül is
           itt deklarálom az első versenyzőt
           ezek a metódusok elérik a privát tagváltozókat */
        tri_race() : ora(3600), perc(60) {
            licensz = "--------"; uszas = 0; bicikli = 0; futas = 0; depo = 0; ij = 0; sum = 0; o = 0; p = 0; mp = 0;
        }

        /* itt deklaráljuk a többi versenyzőt, azok az adatok alapján amit a példányosításnál kapunk
           ne felejtsük el a konstansokat is deklarálni a konstruktorok végén */
        tri_race(string licensz_, int uszas_, int bicikli_, int futas_, int depo_, int ij_) : ora(3600), perc(60) {
            /* a példányosításban megadott értékek itt lesznek egyenlőek a class privát részében definiált tagváltozókkal */ 
            licensz = licensz_; uszas = uszas_; bicikli = bicikli_; futas = futas_; depo = depo_; ij = ij_;
            sum = 0; o = 0; p = 0; 
        }

        /* deklaráljuk az általunk használni kívánt függvényeket és eljárásokat */
        int getIj() const { return ij; }
        /* a & azért kell, mert a láncolt hívásnál az objektumra kell mutatnia */
        /* ez csak a moodle vizsga miatt van így */
        tri_race& kiir_rajt() {
            cout << "Rajt idő: " << o << ":" << p << ":" << mp << " [o:p:mp]" << endl;
            /* referencia visszatérési érték, az objektum nevét adja vissza */
            return *this;
        }
        tri_race& kiir_cel();
        /* ez csak a moodle vizsga miatt van így */
        tri_race& setSum(int t) {
            sum = uszas + bicikli + futas + depo - t;
            o = sum/ora;
            p = (sum%ora)/perc;
            mp =  (sum%ora)%perc;
            /* referencia visszatérési érték, az objektum nevét adja vissza */
            return *this;
        }

        /* destruktor */
        ~tri_race() {
            cout << "Felszabadítottam az objektum memóriacímét!" << endl;
        }
};

tri_race& tri_race::kiir_cel() {
    cout << "Licensz: " << licensz << endl
         << "Úszás: " << uszas << endl
         << "Bicikli: " << bicikli << endl
         << "Futás: " << futas << endl
         << "Depó:" << depo << endl
         << "T-: " << ij << endl;
    cout << "Cél idő: " << o << ":" << p << ":" << mp << " [o:p:mp]" << endl << endl;
    /* referencia visszatérési érték, az objektum nevét adja vissza, ehhez osztáy referencia típusra kell beállítani a metódust */
    return *this;

}
