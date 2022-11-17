#include "1.cpp"

int main(void)
{
	vector<in_ch*> objs; 
	/* gyerek címeket tárolok ebben a vektorban,
	   olyan sorrendben fűzi be a címeket, amilyen sorrendben létrehozom őket */
	in_ch* alap=new in_ch; objs.push_back(alap); cout << "alap = " << alap << endl;
	in_ch* A_tri=new in_ch("M_V_1357",1200,4200,2300,123,60,6); objs.push_back(A_tri); cout << "A_tri = " << A_tri << endl;
	in_ch* B_tri=new in_ch("V_G_2468",1300,4300,2400,125,0,6); objs.push_back(B_tri); cout << "B_tri = " << B_tri << endl;
	in_ch* C_tri=new in_ch("B_G_9048",1400,4400,2400,130,90,6); objs.push_back(C_tri); cout << "C_tri = " << C_tri << endl;
	in_ch* D_tri=new in_ch("C_H_1234",1450,4400,2400,130,30,5); objs.push_back(D_tri); cout << "D_tri = " << D_tri << endl;
	/* egy gyerek címre hivatkozik, de egy unoka konstruktort hív meg */
	in_ch* E_tri=new in_gr_ch("G_R_4321",1500,4450,2350,120,0,4,'F'); objs.push_back(E_tri); cout << "E_tri = " << E_tri << endl;
	/* ez két új függvény, melyeknek bemeneti értéke egy vektor,
	   nem kell felsorolni ezeket a címeket mert a vektor tárolja őket,
	   azért töltjük fel push_back-el, mivel itt visszafelé kellenek a címek */
	mind1(objs);
	felsz(objs);
	return 0;
}