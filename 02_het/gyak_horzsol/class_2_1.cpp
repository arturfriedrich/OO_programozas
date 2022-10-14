#include <iostream>
using namespace std;

#define SK 4                           /* Kiírandó sorok száma */

class sor_minta /* Osztály deklarációja */
 {
   private:
    char kar; /* kiirandó karakter */
    int ism;  /* soron belüli ismétlődések száma */
    int sor;  /* sorok száma, amennyiben megjelenjen */
   public:
    void kiir(int i, char kr, int im, int sr);
 };

void sor_minta::kiir(int i, char kr, int im, int sr)
 {
  kar=kr; ism=im; sor=sr;
  int j;
  for(j=0; j<ism; j++)                /* Soron belüli kiírás */
   {
    if(i<sor) cout << kar;
    else cout << "-";
   }
 }

int main(void)
 {
  int i; 
  sor_minta nyzj, es, zzj;          /* Objektumok példányosítása */
  cout << "\n" << endl; 
  for(i=0; i<SK; i++)              /* Sorok kiírása */
   {
    nyzj.kiir(i,'[',2,2);
    es.kiir(i,'&',3,3);
    zzj.kiir(i,']',4,1);
    cout << "\n" << endl;
   }
  return 0;
}