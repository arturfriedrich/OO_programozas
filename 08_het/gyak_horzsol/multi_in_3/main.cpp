#pragma once
#include <iostream>

using namespace std;

class tri_race
{
	int sum;
	protected:
   		class memb  /* tagok osztály */
		{
		/* privát védettség */
			string lic;
			int swim, cycle, run, depo, ij;
			public:  // protected?
			string getLic() const { return lic; }
			int getSwim() const { return swim; }
			int getCycle() const { return cycle; }
			int getRun() const { return run; }
			int getDepo() const { return depo; }
			int getIj() const { return ij; }
			void setLic(string lc) { lic=lc; }
			void setSwim(int sw) { swim=sw; }
			void setCycle(int cyc) { cycle=cyc; }
			void setRun(int rn) { run=rn; }
			void setDepo(int dp) { depo=dp; }
			void setIj(int t) { ij=t; }
			memb() { cout << "\nAz alapértelmezett szülő-tag adatszerkezet létrejött: "; }
			~memb() { cout << "\nFelszabadítottam a szülő-tag adatszerkezet memóriacímét: "; }
		};
		memb tagok;
		tri_race() : sum(0)
			{ tagok.setLic("--------"); tagok.setSwim(0); tagok.setCycle(0); tagok.setRun(0);
			tagok.setDepo(0); tagok.setIj(0);
			cout << "\nAz alapértelmezett szülő-adatszerkezet létrejött: ";}  
		tri_race(string lc, int sw, int cyc, int rn, int dp, int t) : sum(0)
			{ tagok.setLic(lc); tagok.setSwim(sw); tagok.setCycle(cyc); tagok.setRun(rn);
			tagok.setDepo(dp); tagok.setIj(t);
			cout << "\nA paraméteres szülő-adatszerkezet létrejött: "; }
		int getSum() const { return sum; }
		public:
		/* set szmmot nem tehetem protected szintre, külső szintről elérhetőek */
		tri_race& setSum();
		virtual tri_race& kiir_cel()=0;
		virtual ~tri_race()
			{ cout << "\nFelszabadítottam a szülő-adatszerkezet memóriacímét: "; }
};

class h_m_s
 {
   const int oRA, pRC;
   int h, p, mp;
   protected:
    h_m_s() : oRA(3600), pRC(60), h(0), p(0), mp(0)
	   { cout << "\nAz alapértelmezett átszámoló szülő-adatszerkezet létrejött: "; }
    void s_hms(int s) { h=s/oRA; p=(s%oRA)/pRC; mp=(s%oRA)%pRC; }
  public:
    void kiir_i1() const;
    virtual h_m_s& kiir_cel()=0;
    ~h_m_s()
     { cout << "\nFelszabadítottam az átszámoló szülő-adatszerkezet memóriacímét: "; }
 };
	
class in_ch : public tri_race, public h_m_s
/* hobb lenne, ha a kat is getteren lenne elérhető */
 {
   int kat;
   protected:
    void kiir_i4();
   public:
    in_ch() : tri_race() { kat=0; cout << "\nAz alapértelmezett gyerek-objektum létrejött: "; }
    in_ch(string lc, int sw, int cyc, int rn, int dp, int t, int kt) : \
           tri_race(lc, sw, cyc, rn, dp, t)
     { kat=kt; cout << "\nA paraméteres gyerek-objektum létrejött: "; }
   virtual in_ch& kiir_cel();
   virtual ~in_ch()
    { cout << "\nFelszabadítottam a gyerek-objektum saját adatának a memóriacímét: "; }
   in_ch(const in_ch&) = delete;
   in_ch& operator=(const in_ch&) = delete;	
 };
 
class in_gr_ch : public in_ch
 {
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

void mind1(in_ch* x_tri);
void felsz(tri_race* x_tri);