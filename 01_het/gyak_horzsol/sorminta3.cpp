/* Sorminta készítése függvénnyel, amely egy globális struktúra tömböt kezel
és nem csak változókat, hanem egy egy tömböt is tatalmaz. */
#include <iostream>
using namespace std;

#define SK 4			/* Kiírandó sorok száma */
#define T_E 3			/* A tömb elemeinek a száma */

struct sor_minta 		/* Struktúra deklarációja */
 {
   char kar; 			/* kiirandó karakter */
   int ism;  			/* soron belüli ismétlődések száma */
   bool sor[SK];  		/* mely sorokban jelenjen meg */
 };

 struct sor_minta str_tb[T_E] = {		/* Struktúra tömb definíciója és az elemeinek a kezdőértékei */
							{ '[', 2, { 1, 0, 1, 0} },
							{ '&', 3, { 1, 1, 1, 0} },
							{ ']', 4, { 0, 0, 1, 1} }
};

void kiir(int kfv)
{
	int j, k;
	cout << kfv+1 << ". sor: ";
	for (k=0; k<T_E; k++)					/* Soron belüli kiírás */
	{
		for (j=0; j<str_tb[k].ism; j++)		/* Soron belüli adott karakter kiírása */
		{
			if(str_tb[k].sor[kfv]) cout << str_tb[k].kar;
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
	for (i=0; i<SK; i++)					/* Sorok kiírása */
		{ kiir(i); }
	return 0;
}