#include "Decl.hpp"

/* itt fejtjük ki az Decl.hpp-ben definiált függvényeket és eljárásokat, 
   itt felhasználhatjuk a példányosítésban megadott értékeket */
tri_race& tri_race::kiir_rajt() {
    cout << "Rajt idő: " << o << ":" << p << ":" << mp << " [o:p:mp]" << endl;
    return *this;
}

tri_race& tri_race::kiir_cel() {
    cout << "Licensz: " << licensz << endl
         << "Úszás: " << uszas << endl
         << "Bicikli: " << bicikli << endl
         << "Futás: " << futas << endl
         << "Depó:" << depo << endl
         << "T-: " << ij << endl;
    cout << "Cél idő: " << o << ":" << p << ":" << mp << " [o:p:mp]" << endl << endl;
    return *this;

}

tri_race& tri_race::setSum(int t) {
    sum = uszas + bicikli + futas + depo - t;
    o = sum/ora;
    p = (sum%ora)/perc;
    mp =  (sum%ora)%perc;
    return *this;
}