#include "Decl.hpp"
 
int main(void)
{
	hpmp["F: "] = 2300;         		// létrehozás, meg kell adni a kulcsot, majd az értéket
	for (auto it : hpmp)        		// egy iterátorral végigmegyünk a hpmp-n, a first a kulcs a second az adat
		{ cout << it.first << it.second << "\n\n"; }
	hpmp = { {"Ú: ",1200}, {"B: ",4200} }; // Felüldefiniálás (megsemmisítés)
	for (auto it : hpmp)
		{ cout << it.first << it.second << "\n"; }
	cout << "\n" << hpmp.size();
	hpmp.clear();       // tudjuk törölni
	cout << "\n" << hpmp.size() << "\n\n";
	hpmp = { {"F: ",0}, {"Ú: ",1200}, {"B: ",4200} };
	for (auto it : hpmp)
		{ cout << it.first << it.second << "\n"; }
	cout << "\n" << hpmp.size() << "\n\n";      // .size -- méret lekérdezése
	hpmp["D: "] = 123; // Beszúrás!
	hpmp["D: "] = 123; // Nem lehet ismétlődés! => Ez egy felülírás!
	hpmp["F: "] = 2300;   // Felülírás!
	auto it = hpmp.begin();
	hpmp.insert(it,pair<string, int>("Ú+B+D: ", 1200 + 4200 + 123));        // itt definiálni kell, hogy string vagy int
	hpmp.insert(make_pair("Ú+B+D: ",1200+4200+123));            // nem kell definiálni, hogy string vagy int, auto-val működik
	hpmp.insert(sps("Ú+B+D: ",1200+4200+123));      // az insert paranccsal is be lehet szúrni, megadjuk azt, hogy hova szúrjuk be, aztán azt, hogy mikor
	for (auto it : hpmp)
		{ cout << it.first << it.second << "\n"; }
	cout << "\n" << hpmp.size() << "\n\n";
	for (auto r_it = hpmp.rbegin(); r_it != hpmp.rend(); r_it++)        // fordított kiírás
	{	 cout << r_it->first << r_it->second << "\n";	} cout << "\n";
	hpmp.erase(hpmp.find("D: "));                   // lehet törölni, a find-al megkeressük a kulcs alapján az elemet, a find visszaadja a címét, majd az erase törli
	for (auto it : hpmp)
		{	cout << it.first << it.second << "\n"; }
	if (hpmp.count("Ú: ")) {
		cout << "\nLétezik az elem!\n";
		ke=hpmp.find("Ú: ");      // az Ú címe
		cout << ke->first << ke->second << "\n";      // kiírjuk a kulcsot, majd az adatot
		ke->second = 1100; // Nem kell felüldefiniálni a teljes pair-t!       --- felülírjuk az adatot
		cout << ke->first << ke->second << "\n";
	} else cout << "\nNem létezik az elem!";
	ke=hpmp.find("B: ");
	cout << ke->first << ke->second << "\n";
	ke=hpmp.find("Ú+B+D: "); // Törölt "D: " esete!
	cout << ke->first << ke->second << "\n";
	ke=hpmp.find("F: ");
	cout << ke->first << ke->second << "\n";
	hpmp.clear();
	if (hpmp.empty()) cout << "\nÜres a szótár!\n";
	return 0;
}