# 2019. 01. 22.

10 perc felkészülési idő után 60 perc az alapfeladat, majd ellenőrzés után 60 perc a jobb jegyért.

Az alapfeladat helyes megoldása elégséges (2) érdemjegyet ér, és előfeltétele a jobb jegynek. A +1 feladatok helyes megoldása egyenként +1-gyel növelik az érdemjegy értékét max. jelesig (5).

## Alapfeladat

Készítsen objektum-orientált programot C++ nyelven, járművek állapotának nyilvántartásához.

### `Vehicle` absztrakt osztály

A különböző járművek a `Vehicle` absztrakt osztályból legyenek származtatva, amely a következőket tartalmazza:

- A jármű neve: létrehozáskor kell megadni, később nem módosítható, a `getName()` tagfüggvénnyel lekérdezhető
- A jármű nyilvántartott alkatrészei: tetszőleges számú alkatrész címét (`Part*` lásd alább) tudja tárolni, az `addPart(Part*)` tagfüggvénnyel lehessen újabbat hozzáadni, más módon viszont ne lehessen kívülről hozzáférni az alkatrészeihez
- Egy implementáció nélküli `print()` függvény, melyet a leszármazott osztályoknak kell majd megvalósítaniuk
- Egy `amortizeParts()` tagfüggvény, ami meghívja minden alkatrész `amortize()` függvényét
- Egy `repairParts()` tagfüggvény, ami a javításra szoruló (`!isHealthy()`) alkatrészeinek meghívja a `repair()` függvényét

### `Car` és `MotorBike` származtatott osztályok

A `Vehicle` osztályból származzanak a `Car` és `MotorBike` osztályok. Ezek példányosításkor hozzanak létre maguknak 4 ill. 2 db alkatrészt (kereket), különböző nevekkel (pl. front/rear left/right wheel), és a `Car` esetében 5 év, a `MotorBike`-nál 4 év élettartammal. Valósítsák meg a `print()` függvényt úgy, hogy standard kimenetre kiírják a típusukat (`Car`/`MotorBike`), nevüket, és listázzák az alkatrészeik nevét és állapotát. (Lásd példa kimenet.)

### `Part` osztály

A `Part` osztály tárolja egy alkatrész adatait:

- Név: létrehozáskor kell megadni, később nem módosítható, a `getName()` tagfüggvénnyel lekérdezhető
- Élettartam: létrehozáskor kell megadni egész években, később nem módosítható
- Életkor (egész években): létrehozáskor 0, az `amortize()` tagfüggvény 1-gyel növeli, a `repair()` tagfüggvény 0-ra állítja, más módon ne lehessen kívülről hozzáférni
- Egy `isHealthy()` tagfüggvény, ami akkor tér vissza `true`-val, ha az életkor nem haladja meg az élettartamot

### `VehiclePark` osztály

Készítsen egy `VehiclePark` osztályt járművek tárolására:

- Tetszőleges számú és típusú járművet tudjon tárolni, melyeket az `addVehicle(Vehicle*)` függvénnyel lehessen hozzáadni
- A `printVehicles()` tagfüggvény hívja meg minden tárolt jármű `print()` függvényét
- Az `amortize()` tagfüggvény hívja meg minden tárolt jármű `amortizeParts()` függvényét
- Egy `repairCars()` és egy `repairBikes()` tagfüggvény, melyek a megfelelő típusú járműveknek meghívja a `repairParts()` függvényét

A +1 jegyes feladatokban template-eket kell használni, ezért érdemes már az alapfeladatot úgy megoldani, hogy az osztályok implementciója is a header fájlokban legyen, ne külön fájlokban.

## Bónuszfeladatok

### +1 jegy

A `repairCars()` és `repairBikes()` függvényeket vonja össze egy `repairVehicles()` függvény template-be, ahol a template paraméterben lehessen megadni a javítandó járművek típusát: `Car`, `MotorBike`, vagy `Vehicle` hogy minden típust javítson.

### +1 jegy

Az osztályokat alakítsa át template-ekké, ahol a template paraméter (`T`) határozza meg az alkatrészek életkorának tárolásához használt típust (pl. `int`, `double`). Az `amortize()` függvényeket is egészítse ki egy T típusú paraméterrel, ami megadja az eltelt időt, alapértelmezett értéke legyen `1`.

### +1 jegy

Ha az elkészített osztályok maguk gondoskodnak a mutatóval átadott objektumok (járművek és alkatrészek) felszabadításáról. A „rule of three”-t követve, azt is oldja meg, hogy a tároló osztályok másolása során a tárolt objektumokból is másolat készüljön, és ne legyen többszöri felszabadításos hiba.

**Figyelem!** A járművek másolásakor a megfelelő típusú másolatot kell készíteni, amihez előbb ki kell deríteni a típust. Alternatív megoldásként virtuális `clone()` tagfüggvény is készíthető a `Vehicle` osztályhoz, amely az egyes leszármazottakban a megfelelő típusú másolattal tér vissza.
