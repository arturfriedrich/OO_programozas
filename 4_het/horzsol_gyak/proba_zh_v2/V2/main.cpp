#include "1.cpp"
 
int main(void)
 {
  tri_race* alap=new tri_race;        /* ez egy új pointer ami tri_race típusú */
  tri_race* A_tri=new tri_race("M_V_1357",1200,4200,2300,123,60);       /* paraméteres konstruktor, a heap-en hozzuk létre */
  tri_race B_tri("V_G_2468",1300,4300,2400,125,0), \
           C_tri("B_G_9048",1400,4400,2400,130,90); /* példányosítások */
  alap->kiir_rajt().setSum(alap->getIj()).kiir_cel(); /* mivel ez egy pointer, ezért használunk -> */
  A_tri->kiir_rajt().setSum(A_tri->getIj()).kiir_cel(); /* láncolt hívások */
  B_tri.kiir_rajt().setSum(B_tri.getIj()).kiir_cel(); /* láncolt hívások */
  C_tri.kiir_rajt().setSum(C_tri.getIj()).kiir_cel(); /* láncolt hívások */
  cout << "\n" << endl;
  delete alap;  // memória szivárgás: nincs "delete" és a mutatókat újrahasznosítom (új címre mutat)!
  alap=0;       // az alap legyen egyenlúő a NULL pointerrel
  delete A_tri; // dangling pointer, van "delete" és a felszabadított memória újrahasznosul, más adatszerkezettel (ám a mutató az új kiosztásra mutat)!
  A_tri=0;
  delete alap; // 2x!
  return 0;
}

// h=sum/oRA; p=(sum%oRA)/pRC; mp=(sum%oRA)%pRC;
// Az oRA értéke 3600 míg a pRC értéke 60.