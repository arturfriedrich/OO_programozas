#pragma once
#include "tabla.h"

typedef std::map<std::pair<int, int>, BabuTypes> BabuPositions;

// Az ilyenek miatt gondolni kell a copy constructorra
// akkor is, ha kezzel mi magunk sohase copyznank!
//void printTable(Tabla t) {
//	t.print();
//}

class Jatek {
	Tabla tabla;
public:
	Jatek(
		int sorok,
		int oszlopok,
		BabuPositions positions
	) : tabla(sorok, oszlopok) {
		// feladat1:
		// itt vegig iteralunk a positions argumentumon
		// es mindegyik cellaba berakjuk az adott tipusu babut
		// ehhez keszitsunk egy Tabla::createBabu() metodust!
		for (const auto& p : positions) {
			int coordx = p.first.first;
			int coordy = p.first.second;
			BabuTypes bt = p.second;
			tabla.createBabu(coordx, coordy, bt);
		}
		tabla.print();

		//printTable(tabla); // itt alapbol masolas tortenne!
		//Tabla tabla2(sorok, oszlopok);
		//tabla2 = tabla; // erre is vigyazni kell (copy assignment)

	}

	void leptet() {
		tabla.leptet();
	}
};