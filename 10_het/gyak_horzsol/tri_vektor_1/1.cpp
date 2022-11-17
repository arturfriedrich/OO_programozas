#include "Decl.hpp"

void h_m_s::kiir_i1() const
 { int f=0;
   for(auto itb : hpmp)
      {
        /* beállítom a mezőszélességet, hogy a helyiértékek jó helyen legyenek */
       cout << setw(2) << itb;
       /* az idők között : van, azonban a sor végén mást kell kiírni */
       if(f!=2) { cout << ":"; f++; }
       else cout << " [h:m:s]\n";
      }
 }

void in_ch::kiir_i4()
/* kiolvasgatjuk a tagváltozókat és feltöltjük ezt a vektort */
 { sps = {tagok.getSwim(),tagok.getCycle(),tagok.getDepo(),tagok.getSwim()+tagok.getCycle()+tagok.getDepo(),\
             tagok.getRun(),tagok.getIj(),getSum()};  
   cout << "Licence: " << tagok.getLic() << endl;
   /* az sps vektort járja be ez a for ciklus, mindkét vektor ugyanolyan hosszú,
      ezért mindegy melyiket vizsgáljuk, HA két olyan vektor van aminek a hossza,
      nem egyezik meg, akkor a rövidebb végénél kell megállítani, különben memória
      szeméttel kezdené el feltölteni */
   for(it=sps.begin(), j_it=jelek.begin(); it!=sps.end(); it++, j_it++)
    {
        /* itt megkapja az első értéket */
     hpmp.clear(); s_hms(*it);
     /* kiírja az éppen aktuális jelet */
     cout << *j_it << " ";
     kiir_i1();
    }
    /* ha végigért a sportágakon, akkor egy getteren keresztül kiírja a kategóriákat is */
   cout << "Kategória: " << getKat() << endl;
 }
 
in_ch& in_ch::kiir_cel()
 { kiir_i4(); return *this; }

in_gr_ch& in_gr_ch::kiir_cel()
/* itt  is hasonló ami történek, csak itt a kiir_i4-et hívja meg, ami getteli a nemet */
 { kiir_i4();
   cout << "Nem: " << getNem() << endl;
   return *this; }
 
tri_race& tri_race::setSum()
 { sum=tagok.getSwim()+tagok.getCycle()+tagok.getRun()+tagok.getDepo()-tagok.getIj();
   return *this; }

/* nem pointert kap hanem vektort */
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
   
   /* ez nem egy tagfüggvény */
void felsz(vector<in_ch*> x_tri)
 { for(vector<in_ch*>::reverse_iterator it=x_tri.rbegin();
   it != x_tri.rend(); it++)
   /* a delete utasítás hívogatja az osztályok destruktorát */
    { delete *it; cout << *it << endl; *it=0; }
 }