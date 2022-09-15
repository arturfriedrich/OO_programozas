// TablaJatek.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "jatek.h"

int main()
{
	BabuPositions positions;
	// mi kell ahhoz, hogy egy uj tipust hozzaadjunk? - mint Tigris
	positions[std::make_pair<int, int>(0, 0)] = BabuTypes::Csirke;
	positions[std::make_pair<int, int>(0, 1)] = BabuTypes::Tigris;
	// hatuluto, hogy bele kell nyulni a Tabla::createBabu() metodusba...
	// de ha Factory pattern-t hasznalunk, akkor viszont csak a babuk.h-t
	// kell modositani. Pl. igy:
	positions[std::make_pair<int, int>(1, 5)] = BabuTypes::Majom;

	positions[std::make_pair<int, int>(3, 4)] = BabuTypes::Aligator;
	positions[std::make_pair<int, int>(0, 7)] = BabuTypes::Csirke;
	// mi tortenik, ha tulcimzek?
	// alapbol crash-elne a program!
	positions[std::make_pair<int, int>(100, 100)] = BabuTypes::Ember;
	positions[std::make_pair<int, int>(6, 9)] = BabuTypes::Ember;
	positions[std::make_pair<int, int>(5, 3)] = BabuTypes::Aligator;

	Jatek j(7, 10, positions);

	for (auto i = 0; i < 100; i++) {
		j.leptet();
		char c;
		std::cin >> c;
	}
}
