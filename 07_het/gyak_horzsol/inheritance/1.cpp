#include "Decl.hpp"

void tri_race::kiir_i1()
 { cout << h << ":" << p << ":" << mp  << " [h:m:s]\n"; }

void tri_race::kiir_i2()
 { cout << "Licence: " << lic << "\nÚ: " << swim << "\nB: " << cycle << "\nD: " << depo; }

void tri_race::kiir_i3()
 { cout << "\nF: " << run  << "\nT-: " << ij << "\nCél idő: "; }

void in_ch::kiir_i4()
 { kiir_i2();
   cout << "\nÚ+B+D: " << swim+cycle+depo;
   kiir_i3(); kiir_i1();
   cout << "Kategória: " << kat << endl; }

tri_race& tri_race::kiir_rajt()
 { cout << "\nSzülő rajt idő: "; kiir_i1(); return *this; }
 
tri_race& tri_race::kiir_cel()
 { kiir_i2(); kiir_i3(); kiir_i1(); return *this; }
 
in_ch& in_ch::kiir_rajt()
 { cout << "\nGyerek rajt idő: "; kiir_i1(); return *this; }
 
in_ch& in_ch::kiir_cel()          /* beépülő metódus */
 { kiir_i4(); return *this; }
  
in_gr_ch& in_gr_ch::kiir_rajt()									/* unoka */
 { cout << "\nUnoka rajt idő: "; kiir_i1(); return *this; }

in_gr_ch& in_gr_ch::kiir_cel()									/* unoka */
 { kiir_i4();
   cout << "Nem: " << nem << endl;								/* kiírja a versenyző nemét */
   return *this; }
  
tri_race& tri_race::setSum(int t)
 { sum=swim+cycle+run+depo-t;
   h=sum/oRA; p=(sum%oRA)/pRC; mp=(sum%oRA)%pRC;
   return *this; }
 
void mind(tri_race& alap, tri_race& A_tri, tri_race& B_tri, tri_race& C_tri)
 { cout << endl;
   alap.kiir_rajt().setSum(alap.getIj()).kiir_cel();
   A_tri.kiir_rajt().setSum(A_tri.getIj()).kiir_cel();
   B_tri.kiir_rajt().setSum(B_tri.getIj()).kiir_cel();
   C_tri.kiir_rajt().setSum(C_tri.getIj()).kiir_cel();  
   cout << "\n" << endl; }
 
void mind1(tri_race& x_tri)										/* átveszi a referenciát */
 { cout << endl;
   x_tri.kiir_rajt().setSum(x_tri.getIj()).kiir_cel(); }		/* itt nem tud bekeverni mert virtualizációval megoldottuk */