#include "1.cpp"

int main(void)
{
	tri_race alap, \
			A_tri("M_V_1357",1200,4200,2300,123,60), \
			B_tri("V_G_2468",1300,4300,2400,125,0), \
			C_tri("B_G_9048",1400,4400,2400,130,90);
	// mind(alap, A_tri, B_tri, C_tri);
	in_ch D_tri("C_H_1234",1450,4400,2400,130,30,5);                  									/* gyerek példányosítás */
	// D_tri.kiir_rajt().setSum(D_tri.getIj()).kiir_cel();  cout << "\n" << endl;						/* hozzárendelés láncolt hívással */
	// D_tri.kiir_rajt().kiir_cel();																	/* ezt ne használjuk */
	// D_tri.tri_race::kiir_rajt().setSum(D_tri.getIj()).tri_race::kiir_cel();  cout << "\n" << endl;	/* a gyereket hozzákötöm a szülő kiir_rajt() és kiir_cel() metódusához */
	// C_tri.in_ch::kiir_rajt().setSum(D_tri.getIj()).in_ch::kiir_cel();  cout << "\n" << endl;			/* a szülőt nem tudom hozzákötni a gyerek metódusaihoz */
	in_gr_ch E_tri("G_R_4321",1500,4450,2350,120,0,4,'F');												/* unoka példányosítása */
	// E_tri.kiir_rajt().setSum(E_tri.getIj()).kiir_cel();												/* unoka hozzárendelése láncolt hívással */
	mind1(alap); mind1(A_tri); mind1(B_tri); mind1(C_tri);												/* mindegy milyen objektumot dolgoz fel, kiírja mindegyik öröklődési szintet */
	mind1(D_tri);
	mind1(E_tri);
	return 0;
}

/* vizsgán: dinamikus memóriában legyenek a metódusok adatszerkezetei */