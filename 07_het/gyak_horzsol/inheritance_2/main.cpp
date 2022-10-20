#include "1.cpp"

int main(void)
{
	tri_race* alap=new tri_race;											/* dinamikus memóriát hozunk az adatszerkezetek létrehozására */
	tri_race* A_tri=new tri_race("M_V_1357",1200,4200,2300,123,60);			/* itt nem egy név lesz, hanem egy memóriacím */
	tri_race* B_tri=new tri_race("V_G_2468",1300,4300,2400,125,0);
	tri_race* C_tri=new tri_race("B_G_9048",1400,4400,2400,130,90);
	in_ch* D_tri=new in_ch("C_H_1234",1450,4400,2400,130,30,5);
	in_gr_ch* E_tri=new in_gr_ch("G_R_4321",1500,4450,2350,120,0,4,'F');
	mind1(alap); mind1(A_tri); mind1(B_tri); mind1(C_tri);
	mind1(D_tri); mind1(E_tri);
	// delete alap;											/* a delete hozza működésbe a destruktort */
	// delete A_tri; delete B_tri; delete C_tri;			/* szülők felszabadítása */
	// delete D_tri;										/* gyerek felszabadítása */
	// delete E_tri;										/* unoka felszabadítása */
	felsz(alap); felsz(A_tri); felsz(B_tri); felsz(C_tri); felsz(D_tri); felsz(E_tri);		/* felszabadítások, a kapcsolatot a pointer biztosítja */
	return 0;
}