#include "menu.h"
#include <iostream>
#include <algorithm>
#include <numeric>

void Menu::addItem(MenuItem* mip) {
	items.push_back(mip);
}

void Menu::print() {
	std::cout << "Etlap:" << std::endl;
	int itemnum = 1;
	for (MenuItem* mip : items) {
		std::cout << itemnum++ << ": ";
		mip->print();
		std::cout << std::endl;
	}
}

void MenuItem::print() {
	std::cout << text << " - (";
	std::cout << price << " USD)";
}

void Rendeles::rendel(Menu* mp, int itemnum) {
	if (MenuItem* mip = mp->getNthItem(itemnum)) {
		std::cout << "Rendeles: ";
		mip->print();
		subtotal = subtotal + mip->getPrice();
		std::cout << " - reszosszeg: " << subtotal;

		if (mip->getType() == 1) { // nem szep megoldas, de meg
			// nem vettuk a dynamic_cast-ot
			potentialFreeItemPrices.push_back(mip->getPrice());
			std::cout << " (lehet hogy ingyenes)";
		}

		std::cout << std::endl;
	}
	else {
		std::cout << "Ilyen termek nem letezik!" <<
			std::endl;
	}
}

void Rendeles::fizet() {
	// a kedvezmenyeket ossze kell szamolni (buy1get1free-knel)
	// 1. sorba rendezzuk a potencialisan levonando arakat:
	std::sort(potentialFreeItemPrices.begin(),
		potentialFreeItemPrices.end());
	int numB1G1Frees = potentialFreeItemPrices.size();
	int numToLetGo = numB1G1Frees / 2;
	double kedvezmeny = std::accumulate(
		potentialFreeItemPrices.begin(),
		potentialFreeItemPrices.begin() + numToLetGo,
		0.0
	);
	double vegosszeg = subtotal - kedvezmeny;
	std::cout << "KEDVEZMENY: " << kedvezmeny << std::endl;
	std::cout << "VEGOSSZEG:" << vegosszeg << std::endl;
}
