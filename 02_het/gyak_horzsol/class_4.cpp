#include <iostream>
using namespace std;

#define SK 4				/* Kiírandó sorok száma */

class sor_minta 			/* Osztály deklarációja */
 {
   	private:
		char kar; 			/* kiirandó karakter */
		int ism;  			/* soron belüli ismétlődések száma */
		int sor;  			/* sorok száma, amennyiben megjelenjen */
   	public:
		sor_minta() { kar='A'; ism=1; sor=1; }  	/* Alapértelmezett konstruktor */
		sor_minta(char kr, int im, int sr)			/* Alapérték beállító konstruktor */
			{ kar=kr; ism=im; sor=sr; }
		void kiir(int i);
		void elemek() { cout << kar <<ism <<sor << endl; }
 };

void sor_minta::kiir(int i)
{
	for (int j=0; j<ism; j++)			/* Soron belüli kiírás */
	{
		if (i<sor) cout << kar;
		else cout << "-";
	}
 }

int main(void)
{
	sor_minta nyzj('[',2,2), es('&',3,3), zzj(']',4,1), alap;		/* Objektumok példányosítása, beállítása */
	alap.elemek(); es.elemek(); cout << "\n" << endl; 
	for (int i=0; i<SK; i++)			/* Sorok kiírása */
	{
		nyzj.kiir(i); es.kiir(i); zzj.kiir(i);
		cout << "\n" << endl;
	}
	es.elemek(); 
	alap.elemek();
	return 0;
}