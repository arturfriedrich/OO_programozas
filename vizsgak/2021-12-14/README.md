# 2021. 12. 14.

## Alapfeladat

Készítse el a `Point2D`, `Shape`, `Rectangle` es `Circle` osztályokat úgy, hogy az alábbi kód forduljon és az elvárt kimenetet adja.

Fontos, hogy a `Shape` osztály absztrakt legyen! - különben a `static_assert` nem fog lefordulni.

## Tovabbi megjegyzesek

### Téglalap argumentumai

A `Rectangle` inicializálásakor feltételezheti, hogy az argumentumok egy téglalap 4 sarkát hatarozzák meg az alábbi sorrendben:

1. bal felső,
2. bal alsó,
3. jobb alsó,
4. jobb felső.

### Kör területe

A kör területe: `r` négyzet `pi`. `pi` értéke legyen simán `3.14`, beégetve.

### 2 pont távolsága

2 pont, `a` és `b` távolsága `sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2))`.

`sqrt` és `pow` a `math.h` könyvtárban megtalálhatóak, azaz: `#include <math.h>`.

## Elvárt kimenet

Az elvárt kimenet az alábbi (a távolságok, területek nyilván nem kell, hogy az utolsó ezrelékig azonosak legyenek):

### 2-es jegyert

```
myPoint1 es myPoint2 kozotti tavolsag : 2.23607
s1 terulete : 8
s2 terulete : 12.56
```

### 3-as jegyert

Egyszerűen le kell hogy forduljon, amikor `SZINT_3` makró `1`-re van állítva

### 4-es jegyert

`Teglalap` kisebb területű, mint `Kor`

### 5-os jegyert

A `Teglalap` alakzatnak 4 sarka van.

A `Kor` alakzatnak viszont 0 sarka van.
