#include "1.cpp"
 
int main(void)
{
	tri_race alap, \
			A_tri("M_V_1357",1200,4200,2300,123,60), \
			B_tri("V_G_2468",1300,4300,2400,125,0), \
			C_tri("B_G_9048",1400,4400,2400,130,90); /* példányosítások */
	alap.kiir_rajt().setSum(alap.getIj()).kiir_cel();
	A_tri.kiir_rajt().setSum(A_tri.getIj()).kiir_cel(); /* láncolt hívások */
	B_tri.kiir_rajt().setSum(B_tri.getIj()).kiir_cel(); /* láncolt hívások */
	C_tri.kiir_rajt().setSum(C_tri.getIj()).kiir_cel(); /* láncolt hívások */
	cout << "\n" << endl;
	return 0;
}

// h=sum/oRA; p=(sum%oRA)/pRC; mp=(sum%oRA)%pRC;
// Az oRA értéke 3600 míg a pRC értéke 60.