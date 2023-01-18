# 2020. 01. 22.

Keszitsen programot egy társasházi lakóközösség modellezésére az alábbiak szerint.

## 2-es szinthez

### `Tarstulajdonos` osztály:

- tárolja a tulajdonos nevét es tulajdoni hányadat (egész szam, tízezredek száma).
- van még egy `print()` metódusa, ami nincs implementálva
- absztrakt osztály, ezért nem példányosítható

### `BekesTulajdonos` osztály (egyfajta `Tarstulajdonos`)

Implementálja a `print()` metódust (hogy mit ír ki, ahhoz ld. a `Kozgyules.printJelenlevok()` kimenetét)

### `PereskedoTulajdonos` osztály (egyfajta `Tarstulajdonos`)

Implementálja a `print()` metódust (hogy mit ír ki, ahhoz ld. a `Kozgyules.printJelenlevok()` kimenetét)

### `Kozgyules` osztály

- eltárolja `int`-ekként a közgyűlés évszámát, hónapját es napját
- eltárolja STL konténerben a közgyűlés résztvevőinek pointereit
- megvalósítja az `addJelenlevo()` metódust
- megvalósítja a `printJelenlevok()` metódust, amely az összes jelenlévőre meghívja a saját `print()` metódusát

### `Tarsashaz` osztaly

- STL konténerben, hozzáadás sorrendjében tárolja a tulajdonosokra hivatkozó pointereket
- a `Tarstulajdonos`ok pointereit az `addTulajdonos()` metódussal lehet hozzáadni
- megvalósítja még a `holdKozgyules()` metódust. Ez a metódus gondoskodik róla, hogy minden 2. pereskedő tulajdonos, es minden 3. békés tulajdonos részt vegyen a közgyűlésen (ehhez a `Kozgyules` `addJelenlevo()` metódusát lehet használni)

## 3-as szinthez

Készítsen a `Kozgyules` osztályban egy `printLetszam()` metódust, amely a `<numeric>` headerben található
`std::accumulate` függvény segítségével kiírja a közgyűlésen résztvevők tulajdonosi hányadainak összegét.

**Figyelem**: az `std::accumulate` `BinaryOperation` paramétere egy kézileg definiált osztály példanya kell, hogy legyen. A kézileg definiált osztály neve legyen `SumJelenlevos()`. Ez az osztály meg kell, hogy valósítsa a következő metódust: `int operator()(int acc, Tarstulajdonos* tp)`, ami visszaadja az `acc` es a tulajdonosi hányad összegét.

## 4-es szinthez

Készítsen `Meghatalmazas` osztályt, amely nyilvántartja, hogy melyik meghatalmazó melyik meghatalmazottnak adott meghatalmazást.

Készítsen a `Kozgyules` osztályhoz egy `submitMeghatalmazas()` metódust, amely lehetőve teszi egy adott meghatalmazás benyújtásat. A `Kozgyules` osztály tárolja el a meghatalmazások pointereit.

Ezt követően készítse el a `Kozgyules` osztály `printJelenlevokWithProxies()` metódusát úgy, hogy a jelenlévők tulajdoni hányada mellett az összes általuk képviselt tulajdoni hányad is kiírásra kerüljön.
A `printJelenlevokWithProxies()` metódusban szintén az `std::accumulate()` függvényt használja az eltárolt meghatalmazás-lista / vector fölött végig iterálva. Ehhez szüksége lesz egy `SumMeghatis` osztályra is.

## 5-os szinthez

Valósítsa meg a `PereskedoTulajdonos` osztály `orditozik()` metódusát.

A `Kozgyules` tárolja el az ordítozók pointereit, ennek hozzáadásához készítsen segédmetódust.
Ha egy közgyűlésen legalább ketten ordítoznak, a `BekesTulajdonos`oknak elmegy a kedvük a részvételtől, és legközelebb csak minden 4. `BekesTulajdonos` megy el a közgyűlésre.
