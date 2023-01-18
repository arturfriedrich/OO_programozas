# 2020. 01. 08.

## 2-es jegyért

Készítsen programot mobiltelefonok és laptopok leltári nyilvántartására az alábbiak szerint:

- a `Laptop` és `Mobil` objektumok egyfajta `Termek`ek
- a `Laptop` példányosításakor meg kell adni a laptop nevét és árát
- a `Mobil` példányosításakor meg kell adni a mobil nevét, árát és IMEI számát

### `Keszlet` osztály

A `Keszlet` osztály úgynevezett singleton osztály:

- konstruktorát kívülről nem lehet meghívni
- copy konstruktor és assignment le van tiltva
- kizárólag a `GetInstance()` nevű statikus metóduson keresztül kérhető le egy példánya

A Keszlet osztály `addTermek()` metódusa egy `Termek`re mutató pointert és egy darabszámot vár - ami a készleten fellelhető darabok számát jelenti.

A Keszlet osztály `getQuantity()` metódusa egy `Termek`re mutató pointert vár, és visszaadja, hogy az adott `Termek`ből hány darab lelhető fel a készletben.

## 3-as jegyért

A Keszlet osztály `rendel()` metódusa egy `Termek`re mutató pointert vár, illetve egy darabszámot, és a készleten fellelhető darabok számát a megadott számmal csökkenti (mintha annyit rendeltek volna).

## 4-es jegyért

Készítsen a Keszlet osztályhoz egy `checkedRendel()` metódust, ami ugyanúgy egy `Termek`re mutató pointert és egy darabszámot vár, viszont kivételt dob, ha nincs a készleten elegendő darab a termékből.

## 5-ös jegyért

Készítsen a `Keszlet` osztályhoz egy `addTermekChecked()` metódust, ami egy `Termek`re mutató pointert vár amennyiben az adott termékkel azonos termék már szerepel a nyilvántartásban, annak darabszámát növelje új `Termek` felvétele helyett
