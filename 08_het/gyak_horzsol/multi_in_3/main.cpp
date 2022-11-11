#include "1.cpp"

int main(void)
{
	in_ch* alap=new in_ch; cout << "alap = " << alap << endl;
	in_ch* A_tri=new in_ch("M_V_1357",1200,4200,2300,123,60,6); cout << "A_tri = " << A_tri << endl;
	in_ch* B_tri=new in_ch("V_G_2468",1300,4300,2400,125,0,6); cout << "B_tri = " << B_tri << endl;
	in_ch* C_tri=new in_ch("B_G_9048",1400,4400,2400,130,90,6); cout << "C_tri = " << C_tri << endl;
	in_ch* D_tri=new in_ch("C_H_1234",1450,4400,2400,130,30,5); cout << "D_tri = " << D_tri << endl;
	in_ch* E_tri=new in_gr_ch("G_R_4321",1500,4450,2350,120,0,4,'F'); cout << "E_tri = " << E_tri << endl;
	mind1(alap); mind1(A_tri); mind1(B_tri); mind1(C_tri); mind1(D_tri); mind1(E_tri);
	felsz(E_tri); felsz(D_tri); felsz(C_tri); felsz(B_tri); felsz(A_tri); felsz(alap);
	return 0;
}