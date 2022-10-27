#include "Decl.hpp"

void h_m_s::kiir_i1() const
 { cout << h << ":" << p << ":" << mp  << " [h:m:s]\n"; }

void in_ch::kiir_i2()
 { cout << "Licence: " << lic << "\nÚ: "; s_hms(swim); kiir_i1();
   cout << "B: "; s_hms(cycle); kiir_i1(); 
   cout << "D: "; s_hms(depo); kiir_i1(); }

void in_ch::kiir_i3()
 { cout << "F: "; s_hms(run); kiir_i1();      /* minden egyes idő előtt az átszámoló osztáy átszámolja, majd kiírja */
   cout << "T-: "; s_hms(ij); kiir_i1();
   cout << "Cél idő: "; }

void in_ch::kiir_i4()
 { kiir_i2(); s_hms(swim+cycle+depo);         /* nem túl kultúrált, ha a gyerek a szülő változóit kezelje */
   cout << "Ú+B+D: "; kiir_i1();
   kiir_i3(); s_hms(sum); kiir_i1();
   cout << "Kategória: " << kat << endl; }
 
/*tri_race& tri_race::kiir_cel()
 { kiir_i2(); kiir_i3(); kiir_i1(); return *this; }*/
 
in_ch& in_ch::kiir_cel()
 { kiir_i4(); return *this; }

in_gr_ch& in_gr_ch::kiir_cel()
 { kiir_i4();
   cout << "Nem: " << nem << endl;
   return *this; }
  
tri_race& tri_race::setSum(int t)         /* setterrel, eltűnk belőle az átszámolás */
 { sum=swim+cycle+run+depo-t; return *this; }

void mind1(in_ch* x_tri)
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