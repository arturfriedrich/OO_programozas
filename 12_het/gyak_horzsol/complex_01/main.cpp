#include "1.cpp"

int main(void)
 {
  in_ch* base=new in_ch(); base->b_mem(base,0); // Trükk_1!
  base->ch_objs();
  base->ch_objs("M_V_1357",1200,4200,2300,123,60,6);
  base->ch_objs("V_G_2468",1300,4300,2400,125,0,6);
  base->ch_objs("B_G_9048",1400,4400,2400,130,90,6);
  base->ch_objs("C_H_1234",1450,4400,2400,130,30,5);
  base->ch_objs("G_R_4321",1500,4450,2350,120,0,4,'F');
  base->mind1();
  delete base; base->b_mem(base,1); // Trükk_2!

  //in_ch A_Tri("V_G_2468",1300,4300,2400,125,0,6);
  //in_gr_ch gr_alap;
  //in_gr_ch E_tri("G_R_4321",1500,4450,2350,120,0,4,'F');
  
  return 0;
}