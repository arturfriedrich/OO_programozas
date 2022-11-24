#include "Decl.hpp"
 
int main(void)
{
	hpmp["F: "] = 2300;
	for (auto it : hpmp)
	{ cout << it.first << it.second << "\n\n"; }
	hpmp = { {"Ú: ",1200}, {"B: ",4200} }; // Felüldefiniálás!
	for (auto it : hpmp)
	 {	cout << it.first << it.second << "\n"; }
	cout << "\n" << hpmp.size();
	hpmp.clear();
	cout << "\n" << hpmp.size() << "\n\n";
	hpmp = { {"F: ",0}, {"Ú: ",1200}, {"B: ",4200} };
	for (auto it : hpmp)
	 {	cout << it.first << it.second << "\n"; }
	cout << "\n" << hpmp.size() << "\n\n";
	hpmp["D: "] = 123; // Beszúrás!
	hpmp["D: "] = 123; // Nem lehet ismétlődés! => Ez egy felülírás!
	hpmp["F: "] = 2300;   // Felülírás!
	auto it = hpmp.begin();
	//hpmp.insert(it,pair<string, int>("Ú+B+D: ", 1200 + 4200 + 123));
	//hpmp.insert(make_pair("Ú+B+D: ",1200+4200+123));
	hpmp.insert(sps("Ú+B+D: ",1200+4200+123));
	for (auto it : hpmp)
	 {	cout << it.first << it.second << "\n"; }
	cout << "\n" << hpmp.size() << "\n\n";
	for (auto r_it = hpmp.rbegin(); r_it != hpmp.rend(); r_it++)
	 { cout << r_it->first << r_it->second << "\n";	} cout << "\n";
	hpmp.erase(hpmp.find("D: "));
	for (auto it : hpmp)
	 {	cout << it.first << it.second << "\n"; }
	if (hpmp.count("Ú: ")) {
      cout << "\nLétezik az elem!\n";
      ke=hpmp.find("Ú: ");
      cout << ke->first << ke->second << "\n";
      ke->second = 1100; // Nem kell felüldefiniálni a teljes pair-t!
      cout << ke->first << ke->second << "\n";}
	else cout << "\nNem létezik az elem!";
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