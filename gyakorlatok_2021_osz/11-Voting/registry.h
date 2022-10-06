#pragma once

#include <map>
#include <string>

#include "valasztas.h"

class Valaszto;

class ValasztasiJegyzek {
	std::map<int, Valaszto*> valasztok;
	// minden valasztas pointerhez, minden valasztora megmondja, hogy szavazott-e mar...
	std::map< Valasztas*, std::map<int, bool> > hasSzavazottPerValasztas;
public:
	void addValaszto(Valaszto* vp);
	void printValasztok();
	void initializeValasztas(Valasztas& v) {
		if (hasSzavazottPerValasztas.find(&v) == hasSzavazottPerValasztas.end()) {
			// ha nem letezik ilyen valasztas meg
			std::map<int, bool> hasSzavazott;

			for (auto vIdEsCim : valasztok) {
				// minden valasztora bejegyezni h eddig 0x szavazott
				hasSzavazott[vIdEsCim.first] = false;
			}

			hasSzavazottPerValasztas[&v] = hasSzavazott;
		}
		
	}
	void szavaz(int id, Valasztas& v, int jelolt) {
		// eloszor ellenorizni kene, hogy:
		// - letezik-e ilyen szavazo?
		// - letezik-e ilyen valasztas?
		// - nem szavazott-e mar adott szavazo adott valasztason?
		if (valasztok.find(id) != valasztok.end()) {
			// letezik ez a valaszto
			if (hasSzavazottPerValasztas.find(&v) !=
				hasSzavazottPerValasztas.end()) { 
				// letezik ilyen valasztas
				// ... es nem szavazott benne meg...
				if (!hasSzavazottPerValasztas[&v][id]) {
					v.addSzavazat(jelolt);
					hasSzavazottPerValasztas[&v][id] = true;
				}
			}
		}
	}
};

class Valaszto {
	std::string nev;
	std::string varos;
	int eletkor;
	int azonosito;
public:
	Valaszto(
		const std::string& n,
		const std::string& v,
		int e,
		int id
	) : 
		nev(n), varos(v), eletkor(e), azonosito(id) {}
	int getAzonosito() { return azonosito; }
	std::string getNev() { return nev; }
	std::string getVaros() { return varos; }
	int getEletkor() { return eletkor; }
};