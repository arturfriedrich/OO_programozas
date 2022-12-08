#include <iostream>
#include <vector>

using namespace std;

class Sports
{
	double distance, time, average;
	protected:
		const int sZ, eZ, oRA, pRC;
	public:
		Sports(double dt, double tm) : sZ(100), eZ(1000), oRA(3600), pRC(60)
			{distance = dt; time = tm; average = 0.0; }
		double getDistance() const { return distance; }
		double getTime() const { return time; }
		double getAverage() const { return average; }
		void setAverage(double avg) { average = avg; }
		virtual void computeSaveAndPrintAverage() {};
		virtual ~Sports() {}
		// operátor felültöltés
		Sports& operator+=(Sports& other) {        			// metódusként van megvalósítva  
				distance=distance+other.getDistance();     	// nem tudok behivatkozni a +otherrel, mindegyik tagra külön kell megadni, ahány tagváltozó van
				time=time+other.getTime();
				return *this; 								// a visszatérési érték is referencia
			}     
		void printTotal() { 
			cout << "\nA teljes tav: " << getDistance()/eZ << " [km]\n"\
				 << "A cel ido: " << (int)getTime()/oRA << ":" << (int)getTime()%oRA/pRC\
				 << ":" << (int)getTime()%oRA%pRC << " [h:m:s]" << endl; 
	}
};

class Swimming : public Sports
{
	public:
		Swimming(double dt, double tm) : Sports(dt, tm) { }
		void computeSaveAndPrintAverage() override { 
			setAverage(getTime() / (getDistance() / sZ));
			cout << "Az uszas atlaga: " << getAverage() << " s / 100 m" << endl; 
		}
};

class Cycling : public Sports
{
	public:
		Cycling(double dt, double tm) : Sports(dt, tm) { }
		void computeSaveAndPrintAverage() override { 
			setAverage((getDistance() / eZ) / (getTime() / oRA));
			cout << "A kerekparozas atlaga: " << getAverage() << " km / h" << endl; 
		}
};

class Running : public Sports
{
	public:
		Running(double dt, double tm) : Sports(dt, tm) { }
		void computeSaveAndPrintAverage() override { 
			setAverage((getTime() / pRC) / (getDistance() / eZ));
			cout << "A futas atlaga: " << getAverage() << " min / km" << endl; 
		}
};

void printAverages(vector<Sports*>& sps) {
	int cnt=0;
	cout << endl;
	for (auto sp : sps) {
		if (cnt > 0) cout << " - " << sp->getAverage();
		else cout << sp->getAverage();
		cnt++; 
	}
	cout << endl; 
}

void printNamesOfSports(vector<Sports*>& sps)
{
	cout << endl;
	for (auto sp : sps) { 
		if (dynamic_cast<Swimming*>(sp)) cout << "Uszas";
		else if (dynamic_cast<Cycling*>(sp)) cout << "Kerekpar";
		else if (dynamic_cast<Running*>(sp)) cout << "Futas";
		cout << endl; 
	} 
}