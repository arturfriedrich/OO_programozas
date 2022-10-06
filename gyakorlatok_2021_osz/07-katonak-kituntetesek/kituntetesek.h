#pragma once
#include <iostream>


class Kituntetes {
	std::string nev;
	int evszam;
public:
	Kituntetes(const std::string& name, int year) :
		nev(name), evszam(year)
	{}
	void print() {
		std::cout << "\t\t" << nev << " ("
			<< evszam << ")" << std::endl;
	}
};

class KituntetesNode {
	Kituntetes value;
	KituntetesNode* next;
public:
	KituntetesNode(const std::string& kitNev, int yearOfKit) :
		next(nullptr), value(kitNev, yearOfKit)
	{}
	bool append(KituntetesNode* nxt) {
		if (!next) {
			next = nxt;
			return true;
		}
		return false;
	}
	KituntetesNode* getNext() { return next; }
	void print() { value.print(); }
};