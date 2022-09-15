#pragma once

class Raktar; // forward deklaracio!
// ez azert fontos, mert a TermekCsalad interfesze (javit(Raktar*)) hivatkozik
// a Raktar tipusra, de a fordito nem tudja hogy ilyen tipus letezik!
// itt viszont nem lehet kifejteni a Raktar osztalyt, mert abban lesznek
// TermekCsalad*-ok is, mivel egy vektorban tarolnia kell a Termekek cimeit

class TermekCsalad {
	std::string nev;
	int kiadasEve;
public:
	TermekCsalad(const std::string& nm, int ke);
	virtual void print();
};

class Termek {
	TermekCsalad* tipus;
	bool isKiadva;
	bool isHibatlan;
public:
	Termek(TermekCsalad* tc) : tipus(tc), isKiadva(false), isHibatlan(true) {}
	void kiad() { isKiadva = true; }
	void visszavesz() { isKiadva = false; }
	bool isKiadhato() { return !isKiadva; }
	TermekCsalad* getTipus() { return tipus; }
	void javit(Raktar*);
	void setHibas(bool);
	bool isNotHibas();
	void print() {
		std::cout << "Termek:" << std::endl;
		tipus->print();
		std::cout << " kiadva: " << isKiadva << std::endl;
	}
};

class Garancialis : public TermekCsalad {
public:
	Garancialis(const std::string nm, int ke);
};

class Csereszavatos : public TermekCsalad {
public:
	Csereszavatos(const std::string nm, int ke);
};

class Laptop : public Garancialis {
public:
	Laptop(const std::string nm, int ke);
};

class Mobilkeszulek : public Csereszavatos {
public:
	Mobilkeszulek(const std::string nm, int ke);
};