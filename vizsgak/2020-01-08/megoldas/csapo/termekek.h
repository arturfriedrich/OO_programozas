#pragma once

#include <string>
#include <vector>
#include <utility>
#include <exception>

class Termek {
private:
	std::string gyarto;
	int ar;
public:
	Termek(std::string g, int a) : gyarto(g), ar(a) {}
	virtual std::string getName() = 0;
	std::string& getGyarto() {
		return gyarto;
	}
	int getAr() { return ar; }
};

class Laptop : public Termek {
public:
	Laptop(std::string gyarto, int ar) :
		Termek(gyarto, ar) {}
	virtual std::string getName() {
		std::string s(getGyarto());
		return s + " laptop";
	}
};

class Mobil : public Termek {
private:
	std::string imei;
public:
	Mobil(std::string gyarto, int ar, std::string imeinum) :
		Termek(gyarto, ar), imei(imeinum) {}
	virtual std::string getName() {
		std::string s(getGyarto());
		return s + " mobil";
	}
	std::string getImei() { return imei; }
};

bool operator==(Termek& t1, Termek&t2) {
	// t1 es t2 ugyanaz a tipus kell, hogy legyenek!
	// utana lehet ellenorizni, hogy minden passzol-e
	Mobil* t1AsMobilPtr = dynamic_cast<Mobil*>(&t1);
	Mobil* t2AsMobilPtr = dynamic_cast<Mobil*>(&t2);
	if (t1AsMobilPtr && t2AsMobilPtr) {
		return
			(t1AsMobilPtr->getGyarto() == t2AsMobilPtr->getGyarto()) &&
			(t1AsMobilPtr->getAr() == t2AsMobilPtr->getAr()) &&
			(t1AsMobilPtr->getImei() == t2AsMobilPtr->getImei());
	}
	Laptop* t1AsLaptopPtr = dynamic_cast<Laptop*>(&t1);
	Laptop* t2AsLaptopPtr = dynamic_cast<Laptop*>(&t2);
	if (t1AsLaptopPtr && t2AsLaptopPtr) {
		return
			(t1AsLaptopPtr->getGyarto() == t2AsLaptopPtr->getGyarto()) &&
			(t1AsLaptopPtr->getAr() == t2AsLaptopPtr->getAr());
	}
	return false;
}

class OutOfKeszletError : public std::exception {
private:
	std::string msg;
public:
	OutOfKeszletError(std::string m) : msg(m) {}
	std::string getMsg() {
		return msg;
	}
};

class Keszlet {
private:
	Keszlet() {}
	Keszlet(const Keszlet&) = delete;
	Keszlet& operator=(const Keszlet&) = delete;
	std::vector<std::pair<Termek*, int>> keszlet_vec;
public:
	static Keszlet* GetInstance() {
		static Keszlet* instance = new Keszlet();
		return instance;
	}
	void addTermek(Termek* t, int mennyiseg) {
		keszlet_vec.push_back(std::make_pair(t, mennyiseg));
	}
	void addTermekChecked(Termek* t, int mennyiseg) {
		for (auto it = keszlet_vec.begin(); it != keszlet_vec.end(); ++it) {
			if (*(*it).first == *t) {
				(*it).second += mennyiseg;
				return;
			}
		}
		keszlet_vec.push_back(std::make_pair(t, mennyiseg));
	}
	// 4-es szintig jo:
	/*
	int getQuantity(Termek* t) {
		for (auto current_pair : keszlet_vec) {
			if (current_pair.first == t) {
				return current_pair.second;
			}
		}
		return 0;
	}*/
	// 5-os szinthez ez kell:
	int getQuantity(Termek* t) {
		for (auto it = keszlet_vec.begin(); it != keszlet_vec.end(); ++it) {
			if (*((*it).first) == *t) {
				return (*it).second;
			}
		}
		return 0;
	}
	void rendel(Termek* t, int mennyiseg) {
		/*int pos = 0;
		for (auto current_pair : keszlet_vec) {
			if (current_pair.first == t) {
				current_pair.second -= mennyiseg;
				keszlet_vec[pos].second = current_pair.second;
				return;
			}
			++pos;
		}
		return;*/
		for (auto it = keszlet_vec.begin(); it != keszlet_vec.end(); ++it) {
			if ( (*it).first == t ) {
				(*it).second -= mennyiseg;
				return;
			}
		}
	}
	void checkedRendel(Termek* t, int mennyiseg) {
		for (auto it = keszlet_vec.begin(); it != keszlet_vec.end(); ++it) {
			if ((*it).first == t) {
				if ((*it).second < mennyiseg) {
					throw OutOfKeszletError("nincs tobb a keszleten");
				}
				(*it).second -= mennyiseg;
				return;
			}
		}
	}
};