#include <iostream>
using namespace std;

#define SK 4                           /* Kiírandó sorok száma */

class sor_minta /* Osztály deklarációja */
 {
   private:
    char kar; /* kiirandó karakter */
    int ism;  /* soron belüli ismétlődések száma */
    int sor;  /* sorok száma, amennyiben megjelenjen */
    int v_m;  /* változtatás mértéke az "ism"-re */
   public:
    sor_minta() { kar='A'; ism=1; sor=1; }  /* Alapértelmezett konstruktor */
    sor_minta(char kr, int im, int sr)          /* Alapérték beállító konstruktor */
     { kar=kr; ism=im; sor=sr; }
    sor_minta(int v_m);                            /* v_m beállító konstruktor */
    void kiir(int i);
    void elemek() { cout << kar <<ism <<sor << endl; }
    void v_i();
    ~sor_minta()                                       /* Destruktor */
     { cout << "A program hibátlanul lefutott!\n"; }
 };
void sor_minta::kiir(int i)
 {
  for(int j=0; j<ism; j++)                /* Soron belüli kiírás */
   {
    if(i<sor) cout << kar;
    else cout << "-";
   }
 }
 sor_minta::sor_minta(int v_m)        /* v_m beállító konstruktor külső impl. */
  { v_m=1; }
void sor_minta::v_i()
 {
  do {
      cout << "\n Kérem a változtatás mértékét [+/-]: ";
      cin >> v_m;
     } while((ism+v_m)<=0);
  ism+=v_m;
 }

int main(void)
 {
  sor_minta nyzj('[',2,2), es('&',3,3), zzj(']',4,1), alap;     /* Objektumok példányosítása, beállítása */
  alap.elemek(); es.elemek(); cout << "\n" << endl; 
  for(int i=0; i<SK; i++)              /* Sorok kiírása */
   {
    nyzj.kiir(i); es.kiir(i); zzj.kiir(i);
    cout << "\n" << endl;
   }
  es.elemek(); alap.elemek();
  es.v_i();
  es.elemek();
  return 0;
}