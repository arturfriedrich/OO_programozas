#include <iostream>

using namespace std;

class Sports {
    double distance, time, average;
    protected:
        const int sZ, eZ, oRA, pRC;             /* sZ = 100, eZ = 1000, oRA = 3600, pRC = 60 */
    public:
        Sports(double dt, double tm) : sZ(100), eZ(1000), oRA(3600), pRC(60) {        /* paraméteres szülő objektum */
            distance = dt; time = tm; average = 0.0;
        }
    
};

class Swimming : public Sports {
        
};

class Cycling : public Sports {

};

class Running : public Sports {

};