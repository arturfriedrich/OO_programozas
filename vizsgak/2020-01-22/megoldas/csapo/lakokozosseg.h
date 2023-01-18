#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <numeric>
#include <functional>

class Tarstulajdonos {
protected:
	std::string name;
	int tulajdoniHanyad;
public:
	Tarstulajdonos(const std::string& nm, int th) : name(nm), tulajdoniHanyad(th) {}
	virtual ~Tarstulajdonos() = default;
	virtual void print() = 0;
	virtual int getTulajdoniHanyad() {
		return tulajdoniHanyad;
	}
	// --------------------
	// 4-es szinthez kell csak:
	virtual void print(int th) = 0;
};

// -------------------
// 4-es szinthez kell csak a Meghatalmazas osztaly
class Meghatalmazas {
private:
	Tarstulajdonos * meghatalmazo;
	Tarstulajdonos* meghatalmazott;
public:
	Meghatalmazas(Tarstulajdonos* ki, Tarstulajdonos* kit) {
		meghatalmazo = ki;
		meghatalmazott = kit;
	}
	Tarstulajdonos* getMeghatalmazott() {
		return meghatalmazott;
	}
	Tarstulajdonos* getMeghatalmazo() {
		return meghatalmazo;
	}
};


class BekesTulajdonos : public Tarstulajdonos {
public:
	BekesTulajdonos(const std::string& nm, int th) : Tarstulajdonos(nm, th) {}
	void print() {
		std::cout << "Bekes tulajdonos: " << name << " - " << tulajdoniHanyad << " / 10 000" << std::endl;
	}
	// -----------------
	// 4-es szinthez kell csak:
	void print(int th) {
		std::cout << "Bekes tulajdonos: " << name << " - " << th << " / 10 000" << std::endl;
	}
};

class Kozgyules; // forward deklaracio orditozik() metodus miatt... csak 5-os szinthez kell

class PereskedoTulajdonos : public Tarstulajdonos {
public:
	PereskedoTulajdonos(const std::string& nm, int th) : Tarstulajdonos(nm, th) {}
	void print() {
		std::cout << "Pereskedo tulajdonos: " << name << " - " << tulajdoniHanyad << " / 10 000" << std::endl;
	}
	// -----------------
	// 4-es szinthez kell csak:
	void print(int th) {
		std::cout << "Pereskedo tulajdonos: " << name << " - " << th << " / 10 000" << std::endl;
	}
	// -----------------
	// 5-os szinthez kell csak:
	void orditozik(Kozgyules* kgy);
};

class Kozgyules {
private:
	int evszam, honap, nap;
	std::vector<Tarstulajdonos*> jelenlevok;
	// -----------------
	// 3-as szinthez kell csak:
	class SumJelenlevos {
	public:
		int operator()(int acc, Tarstulajdonos* tp) {
			return acc + tp->getTulajdoniHanyad();
		}
	};

	// -----------------
	// 4-es szinthez kell csak:
	std::vector<Meghatalmazas*> meghatik;
	class SumMeghatis {
		Tarstulajdonos* meghatalmazott;
	public:
		SumMeghatis(Tarstulajdonos* tp) : meghatalmazott(tp) {}
		int operator()(int acc, Meghatalmazas* mp) {
			if (mp->getMeghatalmazott() == meghatalmazott) {
				return acc + mp->getMeghatalmazo()->getTulajdoniHanyad();
			}
			else {
				return acc;
			}
		}
	};

	// -----------------
	// 5-os szinthez kell csak:
	int numOrditozas;
public:
	Kozgyules(int evszam, int honap, int nap) : evszam(evszam), honap(honap), nap(nap), numOrditozas(0) {}
	void addJelenlevo(Tarstulajdonos* tp) {
		jelenlevok.push_back(tp);
	}
	void printJelenlevok() {
		for (Tarstulajdonos* tp : jelenlevok) {
			tp->print();
		}
	}

	// -----------------
	// 3-as szinthez kell csak:
	void printLetszam() {
		int total = std::accumulate(jelenlevok.begin(), jelenlevok.end(), 0, SumJelenlevos());
		std::cout << "Letszam: " << total << std::endl;
	}

	// -----------------
	// 4-es szinthez kell csak:
	void submitMeghatalmazas(Meghatalmazas* mh) {
		meghatik.push_back(mh);
	}
	void printJelenlevokWithProxies() {
		for (Tarstulajdonos* tp : jelenlevok) {
			int total = std::accumulate(meghatik.begin(), meghatik.end(), tp->getTulajdoniHanyad(), SumMeghatis(tp));
			tp->print(total);
		}
	}
	// --------------------
	// 5-os szinthez kell csak
	void addOrditozo() {
		numOrditozas++;
	}
	int getNumOrditozos() {
		return numOrditozas;
	}
};

// -----------------
// 5-os szinthez kell csak:
void PereskedoTulajdonos::orditozik(Kozgyules* kgy) {
	kgy->addOrditozo();
}

class Tarsashaz {
private:
	std::vector<Tarstulajdonos*> tulajdonosok;
	Kozgyules* previousKozgyules; // csak 5-oshoz kell
public:
	Tarsashaz() : previousKozgyules(nullptr) {}
	void addTulajdonos(Tarstulajdonos* tp) {
		tulajdonosok.push_back(tp);
	}
	void setPreviousKozgyules(Kozgyules* pkgy) { // ez a fv csak 5-oshoz kell
		previousKozgyules = pkgy;
	}
	void holdKozgyules(Kozgyules* kgy) {
		int bekes_cnt = 0;
		int bekes_max = (previousKozgyules && previousKozgyules->getNumOrditozos() > 1) ? 4 : 3;
		int pereskedo_cnt = 0;
		int pereskedo_max = 2;
		for (Tarstulajdonos* tp : tulajdonosok) {
			if (BekesTulajdonos* btp = dynamic_cast<BekesTulajdonos*>(tp)) {
				bekes_cnt++;
				if (bekes_cnt == bekes_max) {
					kgy->addJelenlevo(tp);
					bekes_cnt = 0;
				}
			}
			if (PereskedoTulajdonos* ptp = dynamic_cast<PereskedoTulajdonos*>(tp)) {
				pereskedo_cnt++;
				if (pereskedo_cnt == pereskedo_max) {
					kgy->addJelenlevo(tp);
					pereskedo_cnt = 0;
				}
			}
		}
	}
};

