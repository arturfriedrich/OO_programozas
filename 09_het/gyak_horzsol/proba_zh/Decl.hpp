#include <iostream>

using namespace std;

class Sports {
    double distance, time, average;
    protected:
        const int sZ, eZ, oRA, pRC;             /* sZ = 100, eZ = 1000, oRA = 3600, pRC = 60 */
    public:
        Sports(double dt, double tm) : sZ(100), eZ(1000), oRA(3600), pRC(60) {        /* paraméteres szülő objektum */
            distance = dt; time = tm; average = 0.0;
            cout << "\nAz alapértelmezett szülő-objektum létrejött: ";
        }
        /* harmadik lépcső */
        double getDistance() const { return distance; }
        double getTime() const { return time; }
        double getAverage() const { return average; }
        void setAverage(double avg) { average = avg; }
        virtual void computeSaveAndPrintAverage() {}
        virtual ~Sports() {}
};

class Swimming : public Sports {

};

class Cycling : public Sports {

};

class Running : public Sports {

};