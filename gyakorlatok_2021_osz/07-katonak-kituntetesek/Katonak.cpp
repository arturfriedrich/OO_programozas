#include "katonak.h"

Katona::Katona(const std::string& name, const std::string& rank, int yearOfBirth) :
	nev(name), rang(rank), szuletesiEv(yearOfBirth), elsoPlecsni(nullptr) {
}

Katona::~Katona() {
	KituntetesNode* nextToDelete = elsoPlecsni;
	while (nextToDelete) {
		KituntetesNode* followingNode = nextToDelete->getNext();
		delete nextToDelete;
		nextToDelete = followingNode;
	}
}

void Katona::addPlecsni(const std::string& nev, int year) {
	KituntetesNode* newnode = new KituntetesNode(nev, year);
	if (!elsoPlecsni) {
		elsoPlecsni = newnode;
	}
	else {
		KituntetesNode* candidateLastNode = elsoPlecsni;
		while (true) {
			if (candidateLastNode->append(newnode)) {
				break;
			}
			candidateLastNode = candidateLastNode->getNext();
		}
	}
}

void Katona::print() {
	std::cout << "\t" << nev << " (" << rang << " - " << szuletesiEv << ")";
	std::cout << std::endl;

	KituntetesNode* candidateLastNode = elsoPlecsni;
	while (candidateLastNode) {
		candidateLastNode->print();
		candidateLastNode = candidateLastNode->getNext();
	}
	// itt meg a plecsniket ki kell iratni!
}