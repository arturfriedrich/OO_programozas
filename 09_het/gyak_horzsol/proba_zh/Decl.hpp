#include <iostream>

using namespace std;

class Sports {
    double distance, time, average;         /* privát tagváltozók */
    protected:
        const int sZ, eZ, oRA, pRC;
    public:
        /* paraméteres szülő objektum */
        Sports(double dt, double tm) : sZ(100), eZ(1000), oRA(3600), pRC(60) {
            distance = dt; time = tm; average = 0.0;
        }
        /* harmadik lépcső */
        double getDistance() const { return distance; }
        double getTime() const { return time; }
        double getAverage() const { return average; }
        void setAverage(double avg) { average = avg; }
        virtual void computeSaveAndPrintAverage() {}
        virtual ~Sports() {}
};

class Swimming : public Sports {        /* meghívják a szülő paraméteres konstruktorát */
    public:
        /* negyedik lépcső - gyerek objektumok létrehozása */
        Swimming(int dt, int tm) : Sports(dt, tm) { }
        /* ötödik lépcső */
        void computeSaveAndPrintAverage() override {            /* nem csinál semmit, nekem jelzés, virtuális */
            setAverage(getTime() / (getDistance() / sZ));       /* beleírjuk a képletet a paraméter helyére */
            cout << "Az úszás átlaga: " << getAverage() << " s / 100 m" << endl;
        }
};

class Cycling : public Sports {
    public:
        /* negyedik lépcső - gyerek objektumok létrehozása */
        Cycling(int dt, int tm) : Sports(dt, tm) { }
        /* ötödik lépcső */
        void computeSaveAndPrintAverage() override {
            setAverage((getDistance() / eZ) / (getTime() / oRA));
            cout << "A bicikli átlaga: " << getAverage() << " km / óra" << endl;
        }
};

class Running : public Sports {
    public:
        /* negyedik lépcső - gyerek objektumok létrehozása */
        Running(int dt, int tm) : Sports(dt, tm) { }
        /* ötödik lépcső */
        void computeSaveAndPrintAverage() override {
            setAverage((getTime() / pRC) / (getDistance() / eZ));
            cout << "Az úszás átlaga: " << getAverage() << " perc / km" << endl;
        }
};

/* hetedik lépcső */
void printNamesOfSports(Sports* sps) {
    if (dynamic_cast<Swimming*>(sps)) cout << "Úszás" << endl;
    else if (dynamic_cast<Cycling*>(sps)) cout << "Bicikli" << endl;
    else if (dynamic_cast<Running*>(sps)) cout << "Futás" << endl;
}