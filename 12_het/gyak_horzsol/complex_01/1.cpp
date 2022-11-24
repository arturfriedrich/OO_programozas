#include "Decl.hpp"

void in_ch::ch_objs()
 { in_ch* alap=new in_ch(); fuz(alap); }

void in_ch::ch_objs(string lc, int sw, int cyc, int rn, int dp, int t, int kt)
 { in_ch* x_tri=new in_ch(lc, sw, cyc, rn, dp, t, kt); fuz(x_tri); }

void in_ch::ch_objs(string lc, int sw, int cyc, int rn, int dp, int t, int kt, char nm)
 { in_gr_ch* x_tri=new in_gr_ch(lc, sw, cyc, rn, dp, t, kt, nm); fuz(x_tri); }

void in_ch::fuz(in_ch* x_tri)
 { objs.push_back(x_tri); cout << ", a címe: " << x_tri << endl; }

void h_m_s::kiir_i1() const
 { int f=0;
   for(auto itb : hpmp)
      { cout << setw(2) << itb;
        if(f!=2) { cout << ":"; f++; }
        else cout << " [h:m:s]\n"; } }

void in_ch::kiir_i4()
 { sps = {tagok.getSwim(),tagok.getCycle(),tagok.getDepo(),tagok.getSwim()+tagok.getCycle()+tagok.getDepo(),\
             tagok.getRun(),tagok.getIj(),getSum()};  
   cout << "Licence: " << tagok.getLic() << endl;
   for(it=sps.begin(), j_it=jelek.begin(); it!=sps.end(); it++, j_it++)
    { hpmp.clear(); s_hms(*it);
      cout << *j_it << " "; 
      kiir_i1(); }
   cout << "Kategória: " << getKat() << endl; }
 
in_ch& in_ch::kiir_cel()
 { kiir_i4(); return *this; }

in_gr_ch& in_gr_ch::kiir_cel()
 { kiir_i4();
   cout << "Nem: " << getNem() << endl;
   return *this; }
  
tri_race& tri_race::setSum()
 { sum=tagok.getSwim()+tagok.getCycle()+tagok.getRun()+tagok.getDepo()-tagok.getIj();
   return *this; }

void in_ch::mind1()     // megnézi, hogy melyik hívás micsoda
 { cout << endl;
   for(auto it : objs) {
   in_gr_ch* rp=dynamic_cast<in_gr_ch*>(it);
   if(rp!=nullptr) { cout << "\nUnoka ";  }
   else
     { in_ch* rp=dynamic_cast<in_ch*>(it); 
       if(rp!=nullptr) { cout << "\nGyerek "; }
       else
        { tri_race* rp=dynamic_cast<tri_race*>(it);
          cout << "\nSzülő "; } }
   cout << "rajt idő: ";
   it->kiir_i1();
   it->setSum().kiir_cel(); } }

in_ch::~in_ch()   // a gyerek destruktura ide került, ugyanaz a tartalma mint a felsz()-nek
 { 
  for(vector<in_ch*>::reverse_iterator it=objs.rbegin();
   it!=objs.rend(); it++)
    { delete *it; cout << ", amely: " << *it << endl; *it=0; }
  cout << "\nFelszabadítottam a gyerek-objektum saját adatának a memóriacímét. ";  
   }

void in_ch::b_mem(in_ch* b, bool ev)
 { cout << ", base = " << b << endl;
   if(ev) b=0; }