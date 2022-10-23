#include "Decl.hpp"

tri_race& tri_race::kiir_rajt()
{
	cout << "\nRajt idő: ";
	kiir();
	return *this;
}

tri_race& tri_race::kiir_cel()
{
	cout << "Licence: " << lic << "\nÚ: " << swim << "\nB: " << cycle \
	     << "\nF: " << run << "\nD: " << depo << "\nT-: " << ij;
	cout << "\nCél idő: ";
	/* metódust hívunk meg függvény szintaktikával, csak akkor tehetjük meg, 
		ha az objektum rendelkezik olyan szülővel, amihez hozzkötöttük a tagfüggvényt */
	kiir();
	return *this;
}

void tri_race::kiir()
 	{ cout << h << ":" << p << ":" << mp  << " [h:m:s]\n"; }

tri_race& tri_race::setSum(int t)
{ 
	sum=swim+cycle+run+depo-t;
	h=sum/oRA; p=(sum%oRA)/pRC; mp=(sum%oRA)%pRC;
	return *this;
}