#include <iostream>
#include "class_1.hpp"

void sor_minta::kiir(int i)
 {
  for(int j=0; j<ism; j++)                /* Soron belüli kiírás */
   {
    if(i<sor) cout << kar;
    else cout << "-";
   }
 }

sor_minta& sor_minta::setIsm(int v_im)
 {
  if((ism+v_im)>0 and (ism+v_im)<11) ism+=v_im; 
  else ism=10;
  return *this;
 }
 sor_minta& sor_minta::setSor(int v_sr)
 {
  if((sor+v_sr)>0 and (sor+v_sr)<5) sor+=v_sr; 
  return *this;
 }
 sor_minta& sor_minta::setKar(char v_kr)
 {
  if(v_kr!=kar) kar=v_kr;
  return *this;
 }
 
 void mind(sor_minta nyzj, sor_minta es, sor_minta zzj)
 {
  cout << "\n" << endl;
  for(int i=0; i<SK; i++)              /* Sorok kiírása */
   {
    nyzj.kiir(i); es.kiir(i); zzj.kiir(i);
    cout << "\n" << endl;
   }
 }
 
int main(void)
 {
  sor_minta nyzj('[',2,2), es('&',3,3), zzj(']',4,1), alap;     /* Objektumok példányosítása, beállítása */
  mind(nyzj,es,zzj);
  es.setIsm(4).setSor(-1).setKar('@');
  zzj.setKar('}').setSor(es.getSor()-zzj.getSor());
  nyzj.setKar('{').setIsm(2*es.getIsm()-nyzj.getIsm());
  mind(nyzj,es,zzj);
  return 0;
}