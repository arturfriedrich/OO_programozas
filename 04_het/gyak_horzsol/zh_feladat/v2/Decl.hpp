#pragma once
#include <iostream>

using namespace std;

class tri_race /* Osztály deklarációja */
{
	private:
		string lic;
		int swim, cycle, run, depo, ij;
		int sum, h, p, mp;
		const int oRA, pRC;
	public:
	/* ilyen módon is meg lehet adni a változók értékét valtozonev(ertek) */
		tri_race() : oRA(3600), pRC(60), h(0), p(0), mp(0), sum(0), swim(0)
		{ lic="--------"; cycle=0; run=0; depo=0; ij=0; }
		tri_race(string lc, int sw, int cyc, int rn, int dp, int t) : oRA(3600), pRC(60),\
				h(0), p(0), mp(0), sum(0)
			{ lic=lc; swim=sw; cycle=cyc; run=rn; depo=dp; ij=t; }
	int getIj() const { return ij; }
	void kiir();
	tri_race& kiir_rajt();
	tri_race& kiir_cel();
	tri_race& setSum(int t);
	~tri_race()
		{ cout << "Felszabadítottam az objektum memóriacímét!" << endl; }
};