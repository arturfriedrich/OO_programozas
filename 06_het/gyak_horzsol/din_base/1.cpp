#include "Decl.hpp"

void dm_kiir::kiir(int i) const
{
	for (int j=0; j<mutat->getIsm(); j++)     				/* Soron belüli kiírás */
	{
		if (i<mutat->getSor()) cout << mutat->getKar();
		else cout << "-";
   	}
}

sor_minta& sor_minta::setIsm(int v_im)
{
	if ((ism+v_im)>0 and (ism+v_im)<11) ism+=v_im;
	else ism=10;
	return *this;
}

sor_minta& sor_minta::setSor(int v_sr)
{
	if ((sor+v_sr)>0 and (sor+v_sr)<5) sor+=v_sr;
	else sor=4;
	return *this;
}

 sor_minta& sor_minta::setKar(char v_kr)
{
	if (v_kr!=kar) kar=v_kr;
	else kar='!';
	return *this;
}
 
void mind(const dm_kiir& nyzj, dm_kiir& es, dm_kiir& zzj, int s_K)
{
	cout << "\n" << endl;
	for (int i=0; i<s_K; i++)              					/* Sorok kiírása */
	{
	nyzj.kiir(i); es.kiir(i); zzj.kiir(i);
	cout << "\n" << endl;
	}
}
