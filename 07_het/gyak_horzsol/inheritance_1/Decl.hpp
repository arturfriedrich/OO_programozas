#pragma once
#include <iostream>

using namespace std;

class tri_race // szülő osztály deklarációja
 {
   protected:       /* védett szint: továbbra sem elérhető senkinke, csak a gyereknek */
    string lic;
    int swim, cycle, run, depo, ij, h, p, mp, sum;
   private:
    const int oRA, pRC;
   public:
    tri_race() : oRA(3600), pRC(60), h(0), p(0), mp(0), sum(0)
      { lic="--------"; swim=0; cycle=0; run=0; depo=0; ij=0;
        cout << "\nAz alapértelmezett szülő-objektum létrejött";}  
    tri_race(string lc, int sw, int cyc, int rn, int dp, int t) : oRA(3600), pRC(60),\
             h(0), p(0), mp(0), sum(0)
     { lic=lc; swim=sw; cycle=cyc; run=rn; depo=dp; ij=t;
      cout << "\nA paraméteres szülő-objektum létrejött"; }
   int getIj() const { return ij; }
   void kiir_i1();
   void kiir_i2();
   void kiir_i3();							/* beépülő metódusok */
   virtual tri_race& kiir_rajt();			/* ezt is virtuálissá tesszük, hogy a rajt idő kiírásnál jót írjon ki */
   virtual tri_race& kiir_cel();			/* joga van felüldefiniálni a szülő objektumot */
	 tri_race& setSum(int t);
   virtual ~tri_race()					/* ha ezt nem állítjuk át virtual-ra, akkor memóriaszivárgás lép fel */
    { cout << "\nFelszabadítottam a szülő-objektum memóriacímét!"; }
   tri_race(const tri_race&) = delete;
   tri_race& operator=(const tri_race&) = delete;	/* copy letiltása */
	};  
	
class in_ch : public tri_race /* származtatott gyerek osztály deklarációja (örölődés), meg lehet mondani milyen védettségi szinttel öröklődjön (public) */
 {
   protected:			/* védett szint: továbbra sem elérhető senkinke, csak a gyereknek */
    int kat;			/* kiírja a versenyzők kategóriáját */
   public:
    in_ch() : tri_race() { kat=0; }			/* alapértelmezett konstruktor */
    in_ch(string lc, int sw, int cyc, int rn, int dp, int t, int kt) : \
           tri_race(lc, sw, cyc, rn, dp, t) { kat=kt; }			/* paraméteres konstruktor, de meghívjuk a szülő konstruktorát */
   void kiir_i4();		/* beépülő metódus */
   in_ch& kiir_rajt();	/* ugyanaz a neve mint a szülőben */
   virtual in_ch& kiir_cel();
    ~in_ch()			/* dinamikus destruktor */
    { cout << "\nFelszabadítottam a gyerek-objektum saját adatának a memóriacímét!"; }
 };
 
class in_gr_ch : public in_ch  // származtatott unoka osztály deklarációja 
 {
   private:
    char nem;			/* kiírja a versenyzők nevét */
   public:
    in_gr_ch() : in_ch(), nem('N') {  }						/* a metódus törzs üresen van hagyva, fent van iniciáziós listában */
    in_gr_ch(string lc, int sw, int cyc, int rn, int dp, int t, int kt, char nm) : \
           in_ch(lc, sw, cyc, rn, dp, t, kt), nem(nm) {  }
   in_gr_ch& kiir_rajt();
   virtual in_gr_ch& kiir_cel();
    ~in_gr_ch()
    { cout << "\nFelszabadítottam az unoka-objektum saját adatának a memóriacímét!"; }
 };

void mind(tri_race& alap, tri_race& A_tri, tri_race& B_tri, tri_race& C_tri);		/* külső függvények deklarációi */
void mind1(tri_race& x_tri);														/* nem konkét szintet kap, lehet szülő, gyerek és unoka is */