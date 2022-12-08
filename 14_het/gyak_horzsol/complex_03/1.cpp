#include "Decl.hpp"

void in_ch::ch_objs()
 	{ in_ch* alap=new in_ch(); fuz(alap); }

void in_ch::ch_objs(string lc, int sw, int cyc, int rn, int dp, int t, int kt)
 	{ in_ch* x_tri=new in_ch(lc, sw, cyc, rn, dp, t, kt); fuz(x_tri); }

void in_ch::ch_objs(string lc, int sw, int cyc, int rn, int dp, int t, int kt, char nm)
 	{ in_gr_ch* x_tri=new in_gr_ch(lc, sw, cyc, rn, dp, t, kt, nm); fuz(x_tri); }

void in_ch::fuz(in_ch* x_tri)
 	{ objs.push_back(x_tri); cout << ", a címe: " << x_tri << endl; }

void in_ch::kiir_i4()           // szótárkonténer
{ 
	const int &tgS=tagok.getSwim(), &tgC=tagok.getCycle(), &tgD=tagok.getDepo(), &tgR=tagok.getRun(),  &tgI=tagok.getIj();
	cout << "\nLicence: " << tagok.getLic() << endl;
	cplx = {{0, {"Rajt idő:", {0,           {0, {0, 0}}}}},\
			{1, {"Ú:\t\t ",   {tgS,         {0, {0, 0}}}}},\
			{2, {"B:\t\t ",   {tgC,         {0, {0, 0}}}}},\
			{3, {"D:\t\t ",   {tgD,         {0, {0, 0}}}}},\
			{4, {"Ú+B+D:\t ", {tgS+tgC+tgD, {0, {0, 0}}}}},\
			{5, {"F:\t\t ",   {tgR,         {0, {0, 0}}}}},\
			{6, {"T-:\t\t ",  {tgI,         {0, {0, 0}}}}},\
			{7, {"Cél idő: ", {getSum(),    {0, {0, 0}}}}}};
	for (auto it=cplx.begin(); it!=cplx.end(); it++) { 
		string &m_ris = it->second.first;
		int &m_s =  it->second.second.first,\
			&m_h =  it->second.second.second.first,\
			&m_p =  it->second.second.second.second.first,\
			&m_mp = it->second.second.second.second.second;
		s_hms(m_s, &m_h, &m_p, &m_mp);
		cout << m_ris << " ";
		cout << setw(2) << m_h << ":" << setw(2) << m_p << ":"\
			 << setw(2) << m_mp  << " [h:m:s]\n"; 
	}
	cout << "Kategória: " << getKat() << endl; 
}
 
in_ch& in_ch::kiir_cel()
 	{ kiir_i4(); return *this; }

in_gr_ch& in_gr_ch::kiir_cel() { 
	kiir_i4();
	cout << "Nem: " << getNem() << endl;
	return *this; 
}
  
tri_race& tri_race::setSum() { 
	sum=tagok.getSwim()+tagok.getCycle()+tagok.getRun()+tagok.getDepo()-tagok.getIj();
   	return *this; 
}

void in_ch::mind1()
{ 
	cout << endl;
	for (auto it : objs) {
		in_gr_ch* rp=dynamic_cast<in_gr_ch*>(it);
		if (rp!=nullptr) { cout << "\nUnoka ";  }
		else
		{ 
			in_ch* rp=dynamic_cast<in_ch*>(it); 
			if (rp!=nullptr) { cout << "\nGyerek "; } 
		}
		if (it->getKat()<0) cout << "csapat ";			// ha a kategória negatív, akkor írja ki, hogy csapat
		cout << "objektum;";
		it->setSum().kiir_cel(); 
	} 
}

in_ch::~in_ch()
{ 
	string info=":"; 
	for (vector<in_ch*>::reverse_iterator it=objs.rbegin(); it!=objs.rend(); it++) {
		if ((*it)->getKat()>=0) info=": ";
		else info=" csapat: ";            				// amikor csapatcímet szabadít fel, akkor kiírom, hogy csapat
		delete *it; cout << ", amely" << info << *it << endl; *it=0; 
	}
	cout << "\nFelszabadítottam a gyerek-objektum saját adatának a memóriacímét. "; 
}

void in_ch::b_mem(in_ch* b, bool ev) { 
	cout << ", base = " << b << endl;
   	if(ev) b=0; 
}
   
in_ch* in_ch::operator+(in_ch* m_v)
{
	in_ch* csap=new in_ch; cout << ", a csapat címe: " << csap;           		// dinamikus memóriában hozzuk létre a csapatot
	csap->tagok.setLic((tagok.getLic() + " & ") + m_v->tagok.getLic());   		// összefűzzük a licenszeket + operátorral
	csap->tagok.setSwim(tagok.getSwim() + m_v->tagok.getSwim());
	csap->tagok.setCycle(tagok.getCycle() + m_v->tagok.getCycle());
	csap->tagok.setDepo(tagok.getDepo() + m_v->tagok.getDepo());
	csap->tagok.setRun(tagok.getRun() + m_v->tagok.getRun());
	csap->tagok.setIj(tagok.getIj() + m_v->tagok.getIj());
	csap->setKat(-2);
	return csap; 
}

in_ch& in_ch::operator=(const in_ch& cs)
{
	cout << "\n\n\t\t this= " << this << "  cs= " << &cs << endl;     			// kiírjuk a this címét pointerként, utána a csapat 
	tagok.setLic(cs.tagok.getLic());          									// ez a setter a this-re vonatkozik, a getter pedig az objektum cs-re
	tagok.setSwim(cs.tagok.getSwim());       								 	// a this feltöltésre került a setterekkel a cs adataival
	tagok.setCycle(cs.tagok.getCycle());
	tagok.setDepo(cs.tagok.getDepo());
	tagok.setRun(cs.tagok.getRun());
	tagok.setIj(cs.tagok.getIj());
	setKat(-3);
	return *this; 
}

in_ch& in_ch::operator+=(in_ch* m_v)        	// bejön egy ember pluszban, ezt hozzá kell adnom a csapat eddigi tagjaihoz
{
	cout << endl;
	in_ch* csapp=new in_ch; cout << ", amely csapat+= dinamikus címe: " << csapp << endl;       // a dinamikus memóriában hozzuk létre a csapp nevű pointert
	delete csapp; cout << " amely csapat+= dinamikus címe: " << csapp << endl;					/* felszabadítjuk, de a pointer továbbra is mutat erre a 
																								   memória területre */
	csapp = *this + m_v; 		// pointer helyett referenvciával, a visszatérési érték pedig egy átmeneti tárolót határoz meg
	*this = *csapp;           	// az assignment és copy konstruktor az = felüldefiniálása, ha le van tiltva akkor nem tud működni
	delete csapp; cout << ", amely csapat+= címe: " << csapp;         // itt szabadítjuk fel véglegesen
	return *this; 
}

void in_ch::ossz_csap()			// metódus
{
	in_ch* csapat = *objs[1] + objs[2];			// az első a indirekt, a második direkt
	//in_ch* csapat = objs[1]->operator+(objs[2]);
	objs.push_back(csapat);
	*csapat += objs[3];
}