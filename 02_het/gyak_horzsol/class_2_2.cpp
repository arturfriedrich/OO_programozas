#include <iostream>
using namespace std;

#define SK 4			/* Kiírandó sorok száma */

class sor_minta 		/* Osztály deklarációja */
{
   	private:
		char kar; 		/* kiirandó karakter */
		int ism;  		/* soron belüli ismétlődések száma */
		int sor;  		/* sorok száma, amennyiben megjelenjen */
   	public:
		void kezdo(char kr, int im, int sr) { kar=kr; ism=im; sor=sr; }
		void kiir(int i);
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
	sor_minta nyzj, es, zzj;			/* Objektumok példányosítása */
	nyzj.kezdo('[',2,2); es.kezdo('&',3,3); zzj.kezdo(']',4,1);
	cout << "\n" << endl; 
	for	(int i=0; i<SK; i++)			/* Sorok kiírása */
	{
		nyzj.kiir(i); es.kiir(i); zzj.kiir(i);
		cout << "\n" << endl;
	}
	return 0;
}