#include <iostream>
#include "Decl.hpp"

void sor_minta::kiir(int i) const
 {
  for(int j=0; j<ism; j++)                /* Soron belüli kiírás */
   {
    if(i<sor) cout << kar;
    else cout << "-";
   }
 }

sor_minta& sor_minta::setIsm(int v_im)
 {
  if((ism+v_im)>0 and (ism+v_im)<=10) ism+=v_im;
  else ism=10;
  return *this;
 }
 sor_minta& sor_minta::setSor(int v_sr)
 {
  if((sor+v_sr)>0 and (sor+v_sr)<=sK) sor+=v_sr;
  else sor=sK;
  return *this;
 }
 sor_minta& sor_minta::setKar(char v_kr)
 {
  if(v_kr!=kar) kar=v_kr;
  else kar='!';
  return *this;
 }
 
 void mind(const sor_minta&  nyzj, sor_minta& es, sor_minta& zzj, int const s_K)
 {
  cout << "\n" << endl;
  for(int i=0; i<s_K; i++)              /* Sorok kiírása */
   {
    nyzj.kiir(i); es.kiir(i); zzj.kiir(i);
    cout << "\n" << endl;
   }
 }
 
int main(void)
 {
  sor_minta nyzj('[',2,2), es('&',3,3), zzj(']',4,1), alap;     /* Objektumok példányosítása, beállítása */
 //const sor_minta alap;
  mind(nyzj,es,zzj,alap.getsK());
  es.setIsm(4).setSor(-1).setKar('&');
  mind(nyzj,es,zzj,alap.getsK());
  return 0;
}