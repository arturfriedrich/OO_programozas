/* Sorminta készítése, első nekifutás :) */
#include <iostream>
using namespace std;

#define SK 4                           /* Kiírandó sorok száma */

struct sor_minta /* Struktúra deklarációja */
 {
   char kar; /* kiirandó karakter */
   int ism;  /* soron belüli ismétlődések száma */
   int sor;  /* sorok száma, amennyiben megjelenjen */
 };

int main(void)
 {
  int i, j; 
  struct sor_minta nyzj, es, zzj;          /* Struktúrák definíciói */
  nyzj.kar='['; nyzj.ism=2; nyzj.sor=2;    /* Struktúrák tagjainak a kezdőértékei */
  es.kar='&';   es.ism=3;   es.sor=3;      /* Struktúrák tagjainak a kezdőértékei */
  zzj.kar=']';  zzj.ism=4;  zzj.sor=1;     /* Struktúrák tagjainak a kezdőértékei */
  cout << "\n" << endl;
  for(i=0; i<SK; i++)                               /* Sorok kiírása */
   {
    for(j=0; j<nyzj.ism; j++)                /* Soron belüli kiírás */
     {
      if(i<nyzj.sor) cout << nyzj.kar;
      else cout << "-";
     }
    for(j=0; j<es.ism; j++)                 /* Soron belüli kiírás */
     {
      if(i<es.sor) cout << es.kar;
      else cout << "-";
     }
    for(j=0; j<zzj.ism; j++)                /* Soron belüli kiírás */
     {
      if(i<zzj.sor) cout << zzj.kar;
      else cout << "-";
     }
    cout << "\n" << endl;
   }
    return 0;
}