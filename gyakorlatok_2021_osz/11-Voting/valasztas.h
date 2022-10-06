#pragma once
#include <vector>
#include <string>
#include <iostream>

class Valasztas {
	std::string nev;
	int jeloltekSzama;
	std::vector<int> szavazatok;
public:
	Valasztas(const std::string& n, int js) :
		nev(n), jeloltekSzama(js), szavazatok(js, 0) {}

	void addSzavazat(int jelolt) {
		if (jelolt < jeloltekSzama) {
			szavazatok[jelolt] += 1;
		}
	}
	void eredmenyHirdetes() {
		std::cout << nev << " eredmenyei:" << std::endl;
		int jeloltCnt = 1;
		for (auto elem : szavazatok) {
			std::cout << "\t" << jeloltCnt++ << ".";
			std::cout << " jelolt: " << elem;
			std::cout << " szavazat" << std::endl;
		}
	}
};