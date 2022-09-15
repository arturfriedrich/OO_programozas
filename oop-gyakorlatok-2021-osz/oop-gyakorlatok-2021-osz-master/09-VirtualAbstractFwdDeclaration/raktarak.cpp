#include <iostream>
#include <string>
#include <vector>

#include "termekek.h"
#include "raktarak.h"

Raktar::~Raktar() {
	for (Termek* t : termekek) {
		delete t;
	}
}

Raktar& Raktar::add(TermekCsalad* t, int quantity) {
	for (int i = 0; i < quantity; i++) {
		termekek.push_back(new Termek(t));
	}
	return *this;
}

void Raktar::addHibas(Termek* term) {
	int cnt = 0;
	for (Termek* t : termekek) {
		if (t == term) {
			t->setHibas(true);
			t->visszavesz();
		}
		cnt++;
	}
}

void Raktar::kiad(TermekCsalad* term, int db) {
	int cnt = 0;
	int numTermeksKiadva = 0;
	for (Termek* t : termekek) {
		if (t->getTipus() == term &&
			t->isKiadhato() &&
			t->isNotHibas()
			// ez utobbi botranyos most mar, 
			// ezt is a Termek osztalynak kene
			// menedzselnie
			) {
			t->kiad();
			numTermeksKiadva++;
			if (numTermeksKiadva == db) {
				return;
			}
		}
		cnt++;
	}
}

void Raktar::visszavesz(TermekCsalad* tc, int db) {
	int cnt = 0;
	int numTermeksVisszaveve = 0;
	for (Termek* t : termekek) {
		if (t->getTipus() == tc &&
			!t->isKiadhato()
			) {
			t->setHibas(true);
			t->javit(this);
			numTermeksVisszaveve++;
			if (numTermeksVisszaveve == db) {
				return;
			}
		}
		cnt++;
	}
}

void Raktar::print() {
	int cnt = 0;
	for (Termek* t : termekek) {
		std::cout << ++cnt << ": ";
		t->print();
		std::cout << "\tHibatlan: " << t->isNotHibas() << std::endl;
	}
}