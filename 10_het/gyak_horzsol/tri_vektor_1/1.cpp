#include "Decl.hpp"

void h_m_s::kiir_i1() const
 { int f=0;
   for(auto itb : hpmp)
      {
       cout << setw(2) << itb;
       if(f!=2) { cout << ":"; f++; }
       else cout << " [h:m:s]\n";
      }
 }

void in_ch::kiir_i4()
 { sps = {tagok.getSwim(),tagok.getCycle(),tagok.getDepo(),tagok.getSwim()+tagok.getCycle()+tagok.getDepo(),\
             tagok.getRun(),tagok.getIj(),getSum()};  
   cout << "Licence: " << tagok.getLic() << endl;
   for(it=sps.begin(), j_it=jelek.begin(); it!=sps.end(); it++, j_it++)
    {
     hpmp.clear(); s_hms(*it);
     cout << *j_it << " "; 
     kiir_i1();
    }
   cout << "Kategória: " << kat << endl;
 }
 
in_ch& in_ch::kiir_cel()
 { kiir_i4(); return *this; }

in_gr_ch& in_gr_ch::kiir_cel()
 { kiir_i4();
   cout << "Nem: " << nem << endl;
   return *this; }
  
tri_race& tri_race::setSum()
 { sum=tagok.getSwim()+tagok.getCycle()+tagok.getRun()+tagok.getDepo()-tagok.getIj();
   return *this; }

void mind1(vector<in_ch*> x_tri)
 { cout << endl;
   for(auto it : x_tri) {
   in_gr_ch* rp=dynamic_cast<in_gr_ch*>(it);
   if(rp!=nullptr) { cout << "\nUnoka ";  }
   else
     {
      in_ch* rp=dynamic_cast<in_ch*>(it); 
      if(rp!=nullptr) { cout << "\nGyerek "; }
      else
       {
        tri_race* rp=dynamic_cast<tri_race*>(it);
        cout << "\nSzülő ";
       }
     }
   cout << "rajt idő: ";
   it->kiir_i1();
   it->setSum().kiir_cel(); } 
 }
   
void felsz(vector<in_ch*> x_tri)
 { for(vector<in_ch*>::reverse_iterator it=x_tri.rbegin();
   it != x_tri.rend(); it++)
    { delete *it; cout << *it << endl; *it=0; } 
 }