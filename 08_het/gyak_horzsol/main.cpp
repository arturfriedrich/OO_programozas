#include "1.cpp"

int main(void)
 {
  tri_race alap, \
           A_tri("M_V_1357",1200,4200,2300,123,60), \
           B_tri("V_G_2468",1300,4300,2400,125,0), \
           C_tri("B_G_9048",1400,4400,2400,130,90);
  in_ch D_tri("C_H_1234",1450,4400,2400,130,30,5);
  in_gr_ch E_tri("G_R_4321",1500,4450,2350,120,0,4,'F');
  mind1(alap); mind1(A_tri); mind1(B_tri); mind1(C_tri);
  mind1(D_tri);
  mind1(E_tri);
  return 0;