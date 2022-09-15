#pragma once

#include <vector>
#include "kituntetesek.h"


class Katona {
	std::string nev;
	std::string rang;
	int szuletesiEv;
	KituntetesNode* elsoPlecsni;
public:
	//pelda: Katona x("Eros Pista", "Hadnagy", 1977);
	Katona(const std::string& name, const std::string& rank, int yearOfBirth);
	~Katona();
	Katona(Katona& other) = delete;
	Katona& operator=(Katona& other) = delete;
	void addPlecsni(const std::string& nev, int year);
	void print();
};

class Hadsereg {
	std::vector<Katona*> katonak;
public:
	void addKatona(Katona* kp) { katonak.push_back(kp); }
	void print() {
		std::cout << "Hadsereg tagjai:" << std::endl;
		for (Katona* kp : katonak) {
			kp->print();
		}
	}
};
