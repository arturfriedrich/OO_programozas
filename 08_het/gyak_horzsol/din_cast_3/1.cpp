#include "Decl.hpp"

void tri_race::kiir_i1() const
 { cout << h << ":" << p << ":" << mp  << " [h:m:s]\n"; }

void tri_race::kiir_i2() const
 { cout << "Licence: " << lic << "\nÚ: " << swim << "\nB: " << cycle << "\nD: " << depo; }

void tri_race::kiir_i3() const
 { cout << "\nF: " << run  << "\nT-: " << ij << "\nCél idő: "; }

void in_ch::kiir_i4() const
 { kiir_i2();
   cout << "\nÚ+B+D: " << swim+cycle+depo;
   kiir_i3(); kiir_i1();
   cout << "Kategória: " << kat << endl; }
 
tri_race& tri_race::kiir_cel()
 { kiir_i2(); kiir_i3(); kiir_i1(); return *this; }
 
in_ch& in_ch::kiir_cel()
 { kiir_i4(); return *this; }

in_gr_ch& in_gr_ch::kiir_cel()
 { kiir_i4();
   cout << "Nem: " << nem << endl;
   return *this; }
  
tri_race& tri_race::setSum(int t)
 { sum=swim+cycle+run+depo-t;
   h=sum/oRA; p=(sum%oRA)/pRC; mp=(sum%oRA)%pRC;
   return *this; }

void mind1(tri_race* x_tri)
 { cout << endl;
   in_gr_ch* rp = dynamic_cast<in_gr_ch*>(x_tri);
   if(rp!=nullptr) { cout << "\nUnoka ";  }
   else
     {
      in_ch* rp = dynamic_cast<in_ch*>(x_tri); 
      if(rp!=nullptr) { cout << "\nGyerek "; }
      else
       {
        tri_race* rp = dynamic_cast<tri_race*>(x_tri);
        cout << "\nSzülő ";
       }
     }
   cout << "rajt idő: ";
   x_tri->kiir_i1();
   x_tri->setSum(x_tri->getIj()).kiir_cel();
   
 }
   
void felsz(tri_race* x_tri)
 { delete x_tri; cout << x_tri; x_tri=0; }