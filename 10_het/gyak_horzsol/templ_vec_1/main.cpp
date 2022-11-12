#include "Decl.hpp"
 
int main(void)
{
	int i;

	/* felülírjuk az adott indexű elemet */
	hpmp[0]=-1;

	/* ezzel a metódussal tudom növelni a konténert, a végére fűzi hozzá az adott elemet */
	hpmp.push_back(6);

	/* a .size metódus megadja a konténert hosszát */
	/* gyalog módszer - ha adott iterációs számot adunk meg */
	for(i=0; i</*hpmp.size()*/10; i++)
		/* ettől végtelen lesz a ciklus, mivel a folyamatosan bővíti a konténert */
		{ cout << hpmp[i] << " "; hpmp.push_back(7+i); } 
	cout << "\n";

	/* itt a size-ot haszáljuk, ezzel a tényleges méretet és az elemeket látjuk */
	for(i=0; i<hpmp.size(); i++) { cout << hpmp[i] << " "; }
	cout << "\n\n" << hpmp.size() << "\n";

	/* a .pop_back() metódus leveszi az utolsó elemet és erről a vektor tudni is fog, mivel a .size ezt vissza is fogja adni */
	hpmp.pop_back();
	cout << "\n" << hpmp.size() << "\n";

	/* ezzel újra tudjuk méretezni a konténert, 0-val feltölti az új helyeket */
	hpmp.resize(19);
	for(i=0; i<hpmp.size(); i++) { cout << hpmp[i] << " "; }
	cout << "\n";
	hpmp.push_back(20);

	//Típus felismerés a fordítóra bízva! Utolsó elem utánra mutat!
	/* a fordító automatikus felismeri */
	/* az iterátor egy mutatóra mutató mutató, az iterátor e vektor címére mutat, amire egy ponterre mutat */
	/* a feltétel azt mondja, hogy az utolsó elemet már ne írja ki, mert ott úgysincsen semmilyen értékes adat */
	/* a begin ad egy cípet, majd az it++ 4 biteosával iterálja */
	/* az it egy cím, de én a címen tarálható értékre vagyok kíváncsi, ezért kel *-ot használni */
	/* ha nem használunk *-ot, hanem &(*it)-t, akkor írja ki a címet */
	for(auto it = hpmp.begin(); it != hpmp.end(); it++) { cout << /**it*/&(*it) << " "; }
	cout << "\n";

	/* az utólsó címet adjuk meg, majd visszafele számolunk, fordított lesz a sorrend */
	for(auto it = --hpmp.end(); it != --hpmp.begin(); it--) { cout << *it << " "; }
	cout << "\n";

	/* ez is fordított kiíás, csak másik módszerrel */
	/* vektor típusú konténernek iterátort definiálni */
	/* itt egy fordított iterátorra van szükségünk, ezért használjuk a reverse_iterator kulcsszót, előtte egy scope-al */
	/* begin és end határok helyett rbegin és rend, ezért az auto majd fel fogja ismerni a fordított kiírást,
	ezért tehetjük meg, hogy az elejétől a végéig menjünk, mert a rendezés fordítva fog megtörténni */
	for(/*vector<int>::reverse_iterator*/auto it=hpmp.rbegin(); it!=hpmp.rend(); it++)
		{ cout << *it << " "; }

	/* osztályon kívüli függvények */
	/* ehhez szükséges az #include <algorithm> is */
	/* rendező algoritmus, a greater paraméter miatt lesz csökkenő */
	sort(hpmp.begin(), hpmp.end()/*, greater<int>()*/); cout << "\n";

	/* a hasonlit metódus szerint hasonlitja össze az elemeket, ez a Decl.hpp-ben található */
	/* szekvenciális konténer */
	sort(hpmp.begin(), hpmp.end(), hasonlit); cout << "\n";

	/* azért cbegin és cend, mert ezek const pointerrel */
	for(auto it = hpmp.cbegin(); it != hpmp.cend(); it++) { cout << *it << " "; }
	cout << "\n";

	/* a .insert() a kezdőcím elé szúrja be az adott értéket */
	/* ha nem csak egy értéket akarok beírni, akkor az érték elé be lehet írni egy darabszámot is */
	/* pozicionálás - beszúrja adott pozícióval arrébb */
	hpmp.insert(hpmp.begin()+4,4,42);
	/* a végére szúrok be */
	hpmp.insert(hpmp.end()-2,2,42);
	/* először megadjuk a kezdőcímet, megadjuk az intervallumot
	a kezdéstől adott intervallumig szírja be az adott értéket */
	hpmp.insert(hpmp.begin(),hpmp.begin()+9,hpmp.begin()+15);

	/* ugyan támaszkodik az iterátorra, de még automatikusabb, mint eddig */
	/* fordító keresse meg a változónak a koezdő és vég címét, és iteráljon végig */
	/* ez olyan mint egy inicializáló lista, azaz értékek adódnak át */
	for(auto it : hpmp) { cout << it << " "; } // Nincs '*'!
	cout << "\n";

	/* megkapja a kezdőcímet és a végcímet, nem törli ki az adott értékeket, csak tartományon kívülre mozgatja őket */
	// remove(hpmp.begin(), hpmp.end(), 0); // NINCS törlés!
	//remove_if(hpmp.begin(), hpmp.end(), szuro); // NINCS törlés!
	/* tényleg kitörli a megadott értékeket */
	//hpmp.erase((remove(hpmp.begin(), hpmp.end(), 0)),hpmp.end());
	/* megadott feltétel alapján töri az elemeket, itt éppen a páratlanokat törli */
	hpmp.erase((remove_if(hpmp.begin(), hpmp.end(), szuro)),hpmp.end());  
	for(auto it : hpmp) { cout << it << " "; }
	cout << "\n";
	for(auto it = hpmp.cbegin(); it != hpmp.cend(); it++) { cout << &*it << " "; }
	cout << "\n";

	/* megtalál egy adott értéke, mindig az elsőt */
	ke=find(hpmp.begin(), hpmp.end(), 0);

	/* visszaadja az értékét vagy a címét */
	if(ke!=hpmp.end()) cout << /**ke*/&(*ke) << "\n\n";

	/* minimum illetve maximum keresés */
	cout << *max_element(hpmp.begin(), hpmp.end(), hasonlit) << "\n";
	cout << *min_element(hpmp.begin(), hpmp.end(), hasonlit) << "\n";
	/* egyetlen elemben meg tudjuk határozni mindkettő */
	cout << *minmax_element(hpmp.begin(), hpmp.end()).first << "\n";
	cout << *minmax_element(hpmp.begin(), hpmp.end()).second << "\n\n";

	/* megszámolja az adott elemeket */
	cout << count(hpmp.begin(), hpmp.end(),42) << endl;

	/* összetett keresés, keressüg meg a páros számokat, de a 0 ne legyen benne */
	cout << count_if(hpmp.begin(), hpmp.end(),szuro2) << "\n";

	/* törli a teljes konténert */
	hpmp.clear();
	cout << "\n" << hpmp.size() << "\n";
	
	/* megnézi, hogy üres-e az adott vektor */
	if(hpmp.empty()) cout << "Üres a vektor!\n";
	return 0;
}