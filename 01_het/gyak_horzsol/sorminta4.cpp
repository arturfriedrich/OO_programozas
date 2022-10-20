/* Sorminta készítése függvénnyel, amely egy globális struktúra tömböt kezel
és nem csak változókat, hanem egy-egy tömböt és egy alstruktúrát is tatalmaz. */
#include <iostream>
using namespace std;

#define SK 4				/* Kiírandó sorok száma */
#define T_E 3  				/* A tömb elemeinek a száma */

struct veg_sor   			/* Struktúra deklarációja */
 {
   string vs_tb;    		/* végzáró karakterek */
 };   

struct sor_minta 			/* Struktúra deklarációja */
{
	char kar; 				/* kiirandó karakter */
	int ism;  				/* soron belüli ismétlődések száma */
	bool sor[SK];  			/* mely sorokban jelenjen meg */
	struct veg_sor zk; 		/* sorvégi karakterek */
 };

struct sor_minta str_tb[T_E] = {			/* Struktúra tömb definíciója és az elemeinek a kezdőértékei */
							{ '[', 2, { 1, 0, 1, 0}, "╦╦╗" },
							{ '&', 3, { 1, 1, 1, 0}, "OUT" },
							{ ']', 4, { 0, 0, 1, 1}, "END" }
};

void kiir(int kfv)
{
	int j, k, l;
	cout << kfv+1 << ". sor: ";
	for (k=0; k<T_E; k++)					/* Soron belüli kiírás */
	{
		for (j=0; j<str_tb[k].ism; j++)		/* Soron belüli adott karakter kiírása */
		{
			if (str_tb[k].sor[kfv]) cout << str_tb[k].kar;
			else cout << "-";
		}
	}
	if (kfv>=T_E) kfv%=3;
	cout <<  str_tb[kfv].zk.vs_tb << "\n";
	return;
 }

int main(void)
{
	int i=0, ksz;
	cout << "\n" << endl;
	for (i=0; i<SK; i++)	/* Sorok kiírása */
		{ kiir(i); }
	return 0;
}