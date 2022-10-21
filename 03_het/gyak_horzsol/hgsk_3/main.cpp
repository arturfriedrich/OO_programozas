#include <iostream>
#include "Decl.hpp"

void sor_minta::kiir(int i)
{
	for (int j=0; j<ism; j++)		/* Soron belüli kiírás */
	{
		if (i<sor) cout << kar;
		else cout << "-";
	}
}

void sor_minta::setIsm(int im)
{
	do {
		cout << "\n Kérem a változtatás mértékét [1-10]: " << im << " +-= ";
		cin >> v_m;
		} while ((im+v_m)<=0);
	ism+=v_m;
}
 
void mind(sor_minta nyzj, sor_minta es, sor_minta zzj)
{
	cout << "\n" << endl;
	for (int i=0; i<SK; i++)			/* Sorok kiírása */
	{
		nyzj.kiir(i); es.kiir(i); zzj.kiir(i);
		cout << "\n" << endl;
	}
}
 
int main(void)
{
	sor_minta nyzj('[',2,2), es('&',3,3), zzj(']',4,1), alap;		/* Objektumok példányosítása, beállítása */
	cout << alap.getIsm() << "\n" << es.getIsm()  << "\n" << endl; 
	mind(nyzj,es,zzj);
	es.setIsm(es.getIsm());
	mind(nyzj,es,zzj);
	return 0;
}