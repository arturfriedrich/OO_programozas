#include "Decl.hpp"

int main(void)
{
    hpmp[5] = { "F: ", 2300 };
    for (auto it : hpmp)
     { cout << it.second.first << it.second.second << "\n\n"; } // it.first illetve it.second  //az iterátorokkal érem el az elemeket
    hpmp = { { 1, {"Ú: ",1200} }, { 2, {"B: ",4200} } }; // Felüldefiniálás!
    for (auto it : hpmp)
     { cout << it.second.first << it.second.second << "\n"; }
    cout << "\n" << hpmp.size();
    hpmp.clear();
    cout << "\n" << hpmp.size() << "\n\n";
    hpmp = { { 1, {"Ú: ",1200} }, { 2, {"B: ",4200} },\
             { 5, {"F: ",0} } };
    for (auto it : hpmp)
     { cout << it.second.first << it.second.second << "\n"; }
    cout << "\n" << hpmp.size() << "\n\n";
    hpmp[3] = { "D: ", 123 }; // Beszúrás!
    hpmp[5] = { "F: ", 2300 };   // Felülírás!
    hpmp.insert(make_pair(4, sps("Ú+B+D: ", 1200 + 4200 + 123))); // Dupla pair! //többszintű beágyazás
    for (auto it : hpmp)
     { cout << it.second.first << it.second.second << "\n"; }
    cout << "\n" << hpmp.size() << "\n\n";
    hpmp.find(5)->second.second = 2200; // Nem kell felüldefiniálni a teljes pair-t!
    for (auto r_it = hpmp.rbegin(); r_it != hpmp.rend(); r_it++)
     { cout << r_it->second.first << r_it->second.second << "\n"; }
    cout << "\n";
    hpmp.erase(hpmp.find(3));
    for (auto it : hpmp)
     { cout << it.second.first << it.second.second << "\n"; }
    if (hpmp.count(5)) cout << "\nLétezik az elem!";
    else cout << "Nem létezik az elem!";
    hpmp.clear();
    if (hpmp.empty()) cout << "\nÜres a szótár!\n";
    return 0;
}