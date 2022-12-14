#include "hallgato.h"
#include <iostream>

// lehetne using namespace Neptun; is, es akkor nem kene
// mindenhova odairni

Neptun::Hallgato::Hallgato(std::string nv, std::string nkod) {
 nev = nv;
 neptunkod = nkod;
}

std::string Neptun::Hallgato::getNeptunKod() {
	return neptunkod;
}

void Neptun::Hallgato::print(int numTabs) {
	for (int tabcnt = 0; tabcnt < numTabs; tabcnt++) {
		std::cout << "\t";
	}
	std::cout << nev << " - " << neptunkod << std::endl;
}