#include "Decl.hpp"
 
int main(void)
 {
  int i=0;
  auto it=hpmp.cbegin(); //Típus felismerés a fordítóra bízva!
  //hpmp[0]=-1; // Nincs [] operátor! Kiváltása:
  hpmp.pop_front(); hpmp.push_front(-1); // lst: x.pop/.push_front();
  hpmp.push_back(6);
  //for(i=0; i<10; i++) { cout << hpmp[i] << " "; hpmp.push_back(7+i); }
  for(it; i<10; it++, i++) { cout << *it << " "; hpmp.push_back(7+i); }
  cout << "\n";
  /* tartomány alapú for ciklus a lista kiírására,
     az it egy címet, de itt egy tartományra van szükségünk,
     tehát használnunk kell az auto szot, hogy felismerje a fordító,
     nem felülírjuk hanem elfedjük */
for( auto it : hpmp) { cout << it << " "; } // kell az "auto"!
/* kkiírjuk a lista méretét */
  cout << "\n" << hpmp.size() << "\n";
  hpmp.pop_back();
  cout << "\n" << hpmp.size() << "\n";
  /* átméretezzük majd a végére fűzzük az új elemet */
  hpmp.resize(19); hpmp.push_back(20);
  /* fordított iterátor */
  for(it=hpmp.cbegin(); it!=hpmp.cend(); it++) { cout << *it << " "; }
  cout << "\n";
  for(list<int>::reverse_iterator it=hpmp.rbegin(); it!=hpmp.rend(); it++)
   { cout << *it << " "; }
  //sort(hpmp.begin(), hpmp.end()); // Nincs sort fgv. csak metódus!
  /* a sort nem függvény, hanem metódus */
  hpmp.sort(hasonlit); cout << "\n";  // lst: x.sort();
  for(auto it : hpmp) { cout << it << " "; } cout << "\n";
  /* ha felüldefiniálunk eg operátort, akkor definiáljuk felül az összeset,
     például ha a + operátort felülírjuk akkor a ++ is, ezt a list nem tudja */
     /* nincsen indexálás a list-nél, nem tudja értelmezni a +4-et,
        csak az elehére vagy a végére lehet beilleszteni */
  //hpmp.insert(hpmp.begin()+4,42); // Csak az elejére/végére lehet!
  //hpmp.insert(hpmp.end(),42);    // egy 42-est beszúr az elejére
  /* ha vesszővel elválasztjuk, akkor a végére fog négy elemet beszúrni */
    hpmp.insert(hpmp.begin()/*,4*/,42);
//  hpmp.insert(hpmp.end()/*,2*/,42); 
    for(auto it : hpmp) { cout << it << " "; } cout << "\n";
    /* meghatározott indexű helyre akarunk beszúrni,
    kerüljük a list-et, ha adott helyre szeretnénk beszúrni */
  auto itb = hpmp.begin(); for(i=0;i<4;itb++,i++);
  hpmp.insert(itb,42);
  auto ite = hpmp.end(); for(i=0;i<2;ite--,i++);
  hpmp.insert(ite,42);
  for(auto it : hpmp) { cout << it << " "; } cout << "\n";
  //hpmp.insert(hpmp.begin(),hpmp.begin()+9,hpmp.begin()+15);
  /* ezek a ciklusok beszúrnak adott intervallumba értékeket */
  for(i=0;i<5;itb++,i++);
  for(i=0;i<5;ite--,i++);
  hpmp.insert(hpmp.begin(),itb,ite);
  for(auto it : hpmp) { cout << it << " "; } cout << "\n";
  //remove(hpmp.begin(), hpmp.end(), 0); // NINCS törlés!
  //remove_if(hpmp.begin(), hpmp.end(), szuro); // NINCS törlés!
  //hpmp.erase((remove(hpmp.begin(), hpmp.end(), 0)),hpmp.end());
  hpmp.erase((remove_if(hpmp.begin(), hpmp.end(), szuro)),hpmp.end());  
  for(auto it : hpmp) { cout << it << " "; } cout << "\n\n";
  // Tartományalapú (ranged) for ciklus:    */
  /* érték szerint kiírjuk */
  for(auto/*&*/ it : hpmp)  { cout << it << " "; } cout << "\n";
  /* értéket növelünk, majd feldolgozunk (kiírás),
     ebben a sorban velő it felüldefiniálja az előző sorét,
     ha itt használjuk a címkéző operátort (&) és it++, 
     akkor a harmadik sor megváltozik, de a második nem */
  for(auto& it : hpmp)  { cout << it++ << " "; } cout << "\n";
  /* itt a régi it értékei maradnak */
  for(auto/*&*/ it : hpmp)  { cout << it << " "; } cout << "\n";
  /* megkeresünk egy maximum és minimum értéket */
  ke=find(hpmp.begin(), hpmp.end(), 20);
  if(ke!=hpmp.end()) cout << "\n" << *ke << "\n";
  cout << *max_element(hpmp.begin(), hpmp.end(), hasonlit) << "\n";
  cout << *min_element(hpmp.begin(), hpmp.end(), hasonlit) << "\n";
  cout << *minmax_element(hpmp.begin(), hpmp.end()).first << "\n";
  cout << *minmax_element(hpmp.begin(), hpmp.end()).second << "\n\n";
  /* megszámolja az 1-es értékeket */
  cout << count(hpmp.begin(), hpmp.end(),1) << endl;
  cout << count_if(hpmp.begin(), hpmp.end(),szuro2) << "\n";
  /* ugyanúl törölhető mint a vektor */
  hpmp.clear();
  cout << "\n" << hpmp.size() << "\n";
  if(hpmp.empty()) cout << "Üres a lista!\n";
  return 0; 
}