#include "registry.h"
#include <iostream>

// itt implementalunk sok mindent
void ValasztasiJegyzek::addValaszto(Valaszto* vp) {
	int id = vp->getAzonosito();
	if (valasztok.find(id) == valasztok.end()) {
		valasztok[id] = vp;
	}
	else {
		std::cout << "Ez a valaszto id mar letezik";
		std::cout << std::endl;
	}
}

void ValasztasiJegyzek::printValasztok() {
	std::cout << "Valasztasi jegyzek:" << std::endl;
	for (auto valaszto : valasztok) {
		std::cout << std::string(2, ' ');
		std::cout << valaszto.second->getAzonosito();
		std::cout << ": " << valaszto.second->getNev();
		std::cout << " - " << valaszto.second->getVaros();
		std::cout << " - " << valaszto.second->getEletkor();
		std::cout << std::endl;
	}
}