#pragma once
#include <iostream>

using namespace std;

class tri_race
 {
   protected:
    string lic;
    int swim, cycle, run, depo, ij, h, p, mp, sum;
   private:
    const int oRA, pRC;
   public:
    tri_race() : oRA(3600), pRC(60), h(0), p(0), mp(0), sum(0)
      { lic="--------"; swim=0; cycle=0; run=0; depo=0; ij=0;
        cout << "\nAz alapértelmezett szülő-objektum létrejött: ";}  
    tri_race(string lc, int sw, int cyc, int rn, int dp, int t) : oRA(3600), pRC(60),\
             h(0), p(0), mp(0), sum(0)
     { lic=lc; swim=sw; cycle=cyc; run=rn; depo=dp; ij=t;
      cout << "\nA paraméteres szülő-objektum létrejött: "; }
   int getIj() const { return ij; }
   string getLic() const { return lic; }
   void kiir_i1() const;
   void kiir_i2() const;
   void kiir_i3() const;                /* innen eltűnk a kiir_rajt(), és eltűnt minden szintről */
   virtual tri_race& kiir_cel()=0;      // absztrakt osztály, tisztán virtuális
	 tri_race& setSum(int t);           /* 8====3 */
   virtual ~tri_race()
    { cout << "\nFelszabadítottam a szülő-objektum memóriacímét: "; }
   tri_race(const tri_race&) = delete;
   tri_race& operator=(const tri_race&) = delete;	
	};  
	
class in_ch : public tri_race
 {
    int kat;
   public:
    in_ch() : tri_race() { kat=0; }
    in_ch(string lc, int sw, int cyc, int rn, int dp, int t, int kt) : \
           tri_race(lc, sw, cyc, rn, dp, t)
     { kat=kt; cout << "\nA paraméteres gyerek-objektum létrejött: "; }
   void kiir_i4() const;
   virtual in_ch& kiir_cel();
   virtual ~in_ch()
    { cout << "\nFelszabadítottam a gyerek-objektum saját adatának a memóriacímét: "; }
 };
 
class in_gr_ch : public in_ch
 {
   private:
    char nem;
   public:
    in_gr_ch() : in_ch(), nem('N') {  }
    in_gr_ch(string lc, int sw, int cyc, int rn, int dp, int t, int kt, char nm) : \
           in_ch(lc, sw, cyc, rn, dp, t, kt), nem(nm)
     { cout << "\nA paraméteres unoka-objektum létrejött: "; }
   virtual in_gr_ch& kiir_cel();
   virtual ~in_gr_ch()
    { cout << "\nFelszabadítottam az unoka-objektum saját adatának a memóriacímét: "; }
 };

void mind1(tri_race* x_tri);
void felsz(tri_race* x_tri);