/* Sorminta készítése függvénnyel, amely egy globális struktúra tömböt kezel */
#include <iostream>
using namespace std;

#define SK 4                                    /* Kiírandó sorok száma */
#define T_E 3                                  /* A tömb elemeinek a száma */

struct sor_minta /* Struktúra deklarációja */
 {
   char kar; /* kiirandó karakter */
   int ism;  /* soron belüli ismétlődések száma */
   int sor;  /* sorok száma, amennyiben megjelenjen */
 };

 struct sor_minta str_tb[T_E] = {
                             { '[', 2, 2 },
                             { '&', 3, 3 },
                             { ']', 4, 1 }
                            };
   /* Struktúra tömb definíciója és az elemeinek a kezdőértékei */

void kiir(int kfv)
 {
  int j, k;
  for(k=0; k<T_E; k++)                    /* Soron belüli kiírás */
   {
    for(j=0; j<str_tb[k].ism; j++)    /* Soron belüli adott karakter kiírása */
     {
      if(kfv<str_tb[k].sor) cout << str_tb[k].kar;
      else cout << "-";
     }
   }
  cout << "\n" << endl;
  return;
 }

int main(void)
 {
  int i=0; 
  cout << "\n" << endl;
  for(i=0; i<SK; i++)                     /* Sorok kiírása */
   { kiir(i); }
  return 0;
}