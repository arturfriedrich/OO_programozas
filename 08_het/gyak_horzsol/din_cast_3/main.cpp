/* din_cast/pointer-rel, kiir_rajt() kiváltással, absztrakt osztály */
#include "1.cpp"

int main(void)
{
	tri_race* alap=new tri_race; cout << "alap = " << alap << endl;
	tri_race* A_tri=new tri_race("M_V_1357",1200,4200,2300,123,60); cout << "A_tri = " << A_tri << endl;
	tri_race* B_tri=new tri_race("V_G_2468",1300,4300,2400,125,0); cout << "B_tri = " << B_tri << endl;
	tri_race* C_tri=new tri_race("B_G_9048",1400,4400,2400,130,90); cout << "C_tri = " << C_tri << endl;
	in_ch* D_tri=new in_ch("C_H_1234",1450,4400,2400,130,30,5); cout << "D_tri = " << D_tri << endl;
	in_gr_ch* E_tri=new in_gr_ch("G_R_4321",1500,4450,2350,120,0,4,'F'); cout << "E_tri = " << E_tri << endl;
	mind1(alap); mind1(A_tri); mind1(B_tri); mind1(C_tri); mind1(D_tri); mind1(E_tri);
	felsz(E_tri); felsz(D_tri); felsz(C_tri); felsz(B_tri); felsz(A_tri); felsz(alap);
	return 0;
}