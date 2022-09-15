#pragma once

#include <string>

enum class BabuTypes {
	Aligator,
	Csirke,
	Ember,
	Tigris,
	Majom
};

// ez lesz az abstract base class, amibol tobbfele Babu szarmazhat
class Babu {
	bool isFrozen;
public:
	Babu() : isFrozen(false) {}
	virtual char char_rep() = 0;
	virtual std::string getName() = 0;
	void freeze() { isFrozen = true; }
	void unfreeze() { isFrozen = false; }
	bool isStateFrozen() { return isFrozen; }
	virtual double getTamadoEro() = 0;
	virtual double getVedekezoEro() = 0;
	bool megtamad(Babu* vedekezo) {
		// akkor igaz, ha a tamado nyer; kulonben hamis
		std::cout << "\t" << char_rep() << " megtamadta " << vedekezo->char_rep();
		std::cout << "-t ... hajjaj!" << std::endl;
		return this->getTamadoEro() > vedekezo->getVedekezoEro();
	}
};

class Aligator : public Babu {
public:
	char char_rep() override {
		return 'A';
	}
	double getTamadoEro() { return 0.8; }
	double getVedekezoEro() { return 0.6; }
	std::string getName() { return "aligator"; }
};

class Csirke : public Babu {
public:
	char char_rep() override {
		return 'C';
	}
	double getTamadoEro() { return 0.2; }
	double getVedekezoEro() { return 0.2; }
	std::string getName() { return "csirke"; }
};

class Ember : public Babu {
public:
	char char_rep() override {
		return 'E';
	}
	double getTamadoEro() { return 0.8; }
	double getVedekezoEro() { return 0.7; }
	std::string getName() { return "ember"; }
};

class Tigris : public Babu {
public:
	char char_rep() override {
		return 'T';
	}
	double getTamadoEro() { return 0.9; }
	double getVedekezoEro() { return 0.8; }
	std::string getName() { return "tigris"; }
};

class Majom : public Babu {
public:
	char char_rep() override {
		return 'M';
	}
	double getTamadoEro() { return 0.82; }
	double getVedekezoEro() { return 0.6; }
	std::string getName() { return "majom"; }
};

class BabuFactory {
public:
	static Babu* New(BabuTypes bt) {
		if (bt == BabuTypes::Aligator) {
			return new Aligator;
		}
		if (bt == BabuTypes::Ember) {
			return new Ember;
		}
		if (bt == BabuTypes::Csirke) {
			return new Csirke;
		}
		if (bt == BabuTypes::Tigris) {
			return new Tigris;
		}
		if (bt == BabuTypes::Majom) {
			return new Majom;
		}
	}
};