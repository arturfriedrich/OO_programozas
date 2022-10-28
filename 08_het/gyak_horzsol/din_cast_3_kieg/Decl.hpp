#pragma once
#include <iostream>

using namespace std;

class tri_race
{
   	protected:
		string lic;
		int swim, cycle, run, depo, ij, sum;
	public:
		tri_race() : sum(0) { 
			lic="--------"; swim=0; cycle=0; run=0; depo=0; ij=0;
			cout << "\nAz alapértelmezett szülő-adatszerkezet létrejött: ";
		}  
		tri_race(string lc, int sw, int cyc, int rn, int dp, int t) : sum(0) { 
			lic=lc; swim=sw; cycle=cyc; run=rn; depo=dp; ij=t;
			cout << "\nA paraméteres szülő-adatszerkezet létrejött: "; 
		}
		int getIj() const { return ij; }
		string getLic() const { return lic; }
		virtual tri_race& kiir_cel()=0;
		tri_race& setSum(int t);
		virtual ~tri_race()
			{ cout << "\nFelszabadítottam a szülő-adatszerkezet memóriacímét: "; }
};

class h_m_s					/* átszámoló osztály deklarációja */
{
	const int oRA, pRC;
	protected:
		int h, p, mp;
	public:
		h_m_s() : oRA(3600), pRC(60), h(0), p(0), mp(0)
			{ cout << "\nAz alapértelmezett átszámoló szülő-adatszerkezet létrejött: "; }
		void kiir_i1() const;
		void s_hms(int s) { h=s/oRA; p=(s%oRA)/pRC; mp=(s%oRA)%pRC; }		/* ebben a sorban számolja ki */
		virtual h_m_s& kiir_cel()=0; 	/* megvalósított gyerek metódus lehet csak! */
		~h_m_s()   						/* "virtual" nem kötelező! */
			{ cout << "\nFelszabadítottam az átszámoló szülő-adatszerkezet memóriacímét: "; }
 };
	
class in_ch : public tri_race, public h_m_s
{
	int kat;
	public:
		in_ch() : tri_race() { kat=0; cout << "\nAz alapértelmezett gyerek-objektum létrejött: "; }
		in_ch(string lc, int sw, int cyc, int rn, int dp, int t, int kt) : \
				tri_race(lc, sw, cyc, rn, dp, t) { 
			kat=kt; cout << "\nA paraméteres gyerek-objektum létrejött: "; 
		}
		void kiir_i2();
		void kiir_i3();
		void kiir_i4();
		virtual in_ch& kiir_cel();
		virtual ~in_ch()
			{ cout << "\nFelszabadítottam a gyerek-objektum saját adatának a memóriacímét: "; }
		in_ch(const in_ch&) = delete;				/* másoló konstruktorok tiltásai */
		in_ch& operator=(const in_ch&) = delete;	
};
 
class in_gr_ch : public in_ch
{
   	private:
    	char nem;
   	public:
		in_gr_ch() : in_ch(), nem('N') {  }
		in_gr_ch(string lc, int sw, int cyc, int rn, int dp, int t, int kt, char nm) : \
				in_ch(lc, sw, cyc, rn, dp, t, kt), nem(nm) { 
			cout << "\nA paraméteres unoka-objektum létrejött: "; 
		}
		virtual in_gr_ch& kiir_cel();
		virtual ~in_gr_ch()
			{ cout << "\nFelszabadítottam az unoka-objektum saját adatának a memóriacímét: "; }
};

void mind1(in_ch* x_tri);							/* már gyerek objektumokat ír ki */
void felsz(tri_race* x_tri);