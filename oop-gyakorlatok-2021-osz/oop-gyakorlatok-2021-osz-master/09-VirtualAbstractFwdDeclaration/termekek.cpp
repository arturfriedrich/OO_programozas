#include <iostream>
#include <string>
#include <vector>

#include "termekek.h"
#include "raktarak.h"

TermekCsalad::TermekCsalad(const std::string& nm, int ke)
	: nev(nm), kiadasEve(ke) {}

void TermekCsalad::print() {
	// virtual, mert akar felul is definialhato.
	// DE: nem muszaj feluldefinialni, mivel itt is elvben minden info
	// rendelkezesre all
	std::cout << nev << " (kiadas eve: " << kiadasEve << ")" << std::endl;
}

void Termek::javit(Raktar* rp) {
	// ha ennek a termeknek a termekcsaladja
	// Garancialis, megprobaljuk javitani
	// ha Csereszavatos, akkor kicsereljuk

	if (dynamic_cast<Csereszavatos*>(this->tipus)) {
		std::cout << "A termek nem javithato, de csereljuk!" << std::endl;
		rp->addHibas(this);
		rp->kiad(this->tipus, 1);
	}
	else {
		std::cout << "A termeket megprobaljuk javitani" << std::endl;
		rp->addHibas(this);
	}
}

void Termek::setHibas(bool h) {
	isHibatlan = !h;
}

bool Termek::isNotHibas() {
	return isHibatlan;
}

Garancialis::Garancialis(const std::string nm, int ke) :
	TermekCsalad(nm, ke) {}


Csereszavatos::Csereszavatos(const std::string nm, int ke) :
	TermekCsalad(nm, ke) {}


Laptop::Laptop(const std::string nm, int ke) :
	Garancialis(nm, ke) {}

Mobilkeszulek::Mobilkeszulek(const std::string nm, int ke) :
	Csereszavatos(nm, ke) {}