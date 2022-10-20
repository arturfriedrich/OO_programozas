/* Sorminta készítése függvénnyel, amely egy LOKÁLIS(!) struktúra tömböt kezel.
    A függvény, paraméterként kapja meg a struktúra tömb címét.
    Alstruktúra hívása. */
#include <iostream>
using namespace std;

#define SK 4				/* Kiírandó sorok száma */
#define T_E 3				/* A tömb elemeinek a száma */

struct veg_sor   			/* Struktúra deklarációja */
{
	string vs_tb;    		/* végzáró karakterek */
};   

struct sor_minta 			/* Struktúra deklarációja */
{
   string kar; 				/* kiirandó karakter */
   int ism;  				/* soron belüli ismétlődések száma */
   bool sor[SK];  			/* mely sorokban jelenjen meg */
   struct veg_sor zk; 		/* sorvégi karakterek */
 };
 
void kiir(int kfv, struct sor_minta *pnt)
{
	int j, k;
	cout << kfv+1 << ". sor: ";
	for (k=0; k<T_E; k++, pnt++)				/* Soron belüli kiírás */
	{
	/*cout << "\n" << pnt << "\n";*/            /* Memória címek megjelenítése */
		for (j=0; j<pnt->ism; j++)    			/* Soron belüli adott karakter kiírása */
		{
			if (pnt->sor[kfv]) cout << pnt->kar;
			else cout << "-";
		}
	}
	if (kfv>=T_E) kfv%=3;
	if (kfv==0) pnt-=3;
	else if (kfv==1) pnt-=2;
	else if (kfv==2) pnt-=1;
	cout << pnt->zk.vs_tb << "\n";
	return;
 }

int main(void)
{
	int i=0;
	struct sor_minta str_tb[T_E] = {
									{ "▲", 2, { 1, 0, 1, 0}, "╦╦╗" },
									{ "▼", 3, { 1, 1, 1, 0}, "╬╬╣" },
									{ "►", 4, { 0, 0, 1, 1}, "╩╩╝" }
	};
	/* Struktúra tömb definíciója és az elemeinek a kezdőértékei */
	struct sor_minta *mutat;
	cout << "\n" << endl;
	for (i=0, mutat=str_tb; i<SK; i++)			/* Sorok kiírása */
		{ kiir(i,mutat); }
	return 0;
}