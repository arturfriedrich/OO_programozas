// SorokEsBekezdesek2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

class Szo {
	const std::string content;
public:
	Szo(const std::string& szo) : content(szo) {}
	int getLength() const { return content.length(); }
	void print() { std::cout << content; }
};

class Sor {
	std::vector<Szo> szavak;
	int currentHossz;
	const int hosszLimit;
public:
	Sor() : currentHossz(0), hosszLimit(75) {}
	bool addSzo(const Szo& sz) {
		if (currentHossz < hosszLimit) {
			if (szavak.size() > 0) { currentHossz++; }
			currentHossz = currentHossz + sz.getLength();
			szavak.push_back(sz);
			return true;
		}
		return false;
	}
	void print() {
		bool isFirst = true;
		for (Szo sz : szavak) {
			if (!isFirst) { std::cout << " "; }
			else { isFirst = false; }
			sz.print();
		}
		std::cout << std::endl;
	}
};

class Bekezdes {
	std::vector<Sor> sorok;
public:
	void addText(const std::string& text) {
		int inxOfNextSpace = 0;
		int inxOfPreviousSpace = -1;
		bool stop = false;

		while (!stop) {
			inxOfNextSpace = text.find(" ", inxOfPreviousSpace + 1);
			std::string nextSzo = text.substr(inxOfPreviousSpace + 1,
				inxOfNextSpace - inxOfPreviousSpace - 1);
			inxOfPreviousSpace = inxOfNextSpace;

			if (nextSzo == "" || inxOfNextSpace == -1) {
				stop = true;
			}
			if (nextSzo.length() > 0) {
				int numSorok = sorok.size();
				if (numSorok == 0) {
					Sor elsoSor;
					elsoSor.addSzo(Szo(nextSzo));
					sorok.push_back(elsoSor);
				}
				else {
					Sor& utolsoSor = sorok[numSorok - 1];
					bool success = utolsoSor.addSzo(Szo(nextSzo));

					if (!success) {
						Sor nextSor;
						nextSor.addSzo(Szo(nextSzo));
						sorok.push_back(nextSor);
					}

				}

				// adjuk hozza az utolso sorhoz!!
				//std::cout << "hozzaadva!" << std::endl;
			}
			//std::cout << "kovetkezo szo: ." << nextSzo << "." << std::endl;
		}
	}
	void print() {
		for (Sor sz : sorok) {
			sz.print();
		}
	}
};

int main()
{


	//int inx2 = test.find(" ", inx + 1);
	//std::string masodikSzo = test.substr(inx+1, inx2 - inx - 1);

	//std::cout << "inx = " << inx << std::endl;
	//std::cout << "elsoSzo = ." << elsoSzo << "." << std::endl;

	//std::cout << "inx2 = " << inx2 << std::endl;
	//std::cout << "masodikSzo = ." << masodikSzo << "." << std::endl;

	Bekezdes b;
	b.addText("This is a test szoveg.");
	b.addText("Please, please add this text and do not forget to create new lines in the process.");
	b.addText("Keep going with creating new lines as long as the previous line has more than 75 characters");
	b.print();
}
