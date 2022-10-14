#include "Decl.hpp"

tri_race& tri_race::kiir_rajt()
{
	cout << "\nRajt idő: " << h << ":" << p << ":" << mp  << " [h:m:s]";
	return *this;
}

tri_race& tri_race::kiir_cel()
{
	cout << "\nLicence: " << lic << "\nÚ: " << *swim /* az értékére hivatkozunk */ << "\nB: " << cycle \
		 << "\nF: " << run << "\nD: " << depo << "\nT-: " << ij;
	cout << "\nCél idő: " << h << ":" << p << ":" << mp  << " [h:m:s]\n";
	return *this;
}

tri_race& tri_race::setSum(int t)
{ 
	sum=*swim+cycle+run+depo-t;                       		/* oda kell a *, mert itt érték szerint adjuk át */
	h=sum/oRA; p=(sum%oRA)/pRC; mp=(sum%oRA)%pRC;
	return *this;
}