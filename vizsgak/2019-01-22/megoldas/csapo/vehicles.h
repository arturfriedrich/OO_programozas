#pragma once

#include <string>
#include <list>
#include <iostream>

#include "parts.h"

using string = std::string;
template<class T>
using list = std::list<T>;

class Vehicle {
protected:
	string name;
	list<Part*> parts;

public:
	Vehicle(const std::string& n) : name(n) {}

#if PLUS3
    virtual ~Vehicle() {
        for (auto p : parts) {
            delete p;
        }
    }

    virtual Vehicle* clone() = 0;
#endif

	string getName() const { return name; }

	void addPart(Part* p) {
		parts.push_back(p);
	}

	virtual void print() const = 0;

	void amortizeParts() {
		for (auto p : parts) {
			p->amortize();
		}
	}

    void repair() {
        for (auto p : parts) {
            if (!p->isHealthy()) p->repair();
        }
    }
};

class Car : public Vehicle {
public:
    Car(const std::string& n) : Vehicle(n) {
        parts = {
            new Part("Front left wheel" , 5),
            new Part("Front right wheel", 5),
            new Part("Rear left wheel", 5),
            new Part("Rear right wheel", 5)
        };
	}

#if PLUS3
    Car(const Car& other) : Vehicle("Copy of " + other.name) {
        for (auto p : other.parts) {
            parts.push_back(new Part(*p));
        }
    }

    Car& operator=(const Car& other) {
        return Car(other);
    }

    virtual Vehicle* clone() override {
        return new Car(*this);
    }
#endif

    virtual void print() const override {
		std::cout << "Car named " << getName() << " with " << parts.size() << " parts:\n";
        for (auto p : parts) {
            std::cout << "\t" << p->getName() << " (" << p->getAge() << " years old)";
            if (!p->isHealthy()) std::cout << " - Needs repair!";
            std::cout << std::endl;
        }
	}
};

class MotorBike : public Vehicle {
public:
	MotorBike(const std::string& n) : Vehicle(n) {
        parts = {
            new Part("Front wheel", 4),
            new Part("Rear wheel", 4)
        };
	}

#if PLUS3
    MotorBike(const MotorBike& other) : Vehicle("Copy of " + other.name) {
        for (auto p : other.parts) {
            parts.push_back(new Part(*p));
        }
    }

    MotorBike& operator=(const MotorBike& other) {
        return MotorBike(other);
    }

    virtual Vehicle* clone() override {
        return new MotorBike(*this);
    }
#endif

    virtual void print() const override {
        std::cout << "Motorbike named " << getName() << " with " << parts.size() << " parts:\n";
        for (auto p : parts) {
            std::cout << "\t" << p->getName() << " (" << p->getAge() << " years old)";
            if (!p->isHealthy()) std::cout << " - Needs repair!";
            std::cout << std::endl;
        }
	}
};

class VehiclePark {
private:
	list<Vehicle*> vehicles;
public:
    VehiclePark() {}
#if PLUS3
    ~VehiclePark() {
        for (auto v : vehicles) {
            delete v;
        }
    }

    VehiclePark(const VehiclePark& other) {
        for (auto v : other.vehicles) {
            /*
            Car* c = dynamic_cast<Car*>(v);
            if (c) {
                vehicles.push_back(new Car(*c));
                continue;
            }
            MotorBike* mb = dynamic_cast<MotorBike*>(v);
            if (mb) {
                vehicles.push_back(new MotorBike(*mb));
                continue;
            }
            std::cerr << "Error: Could not copy unknown Vehicle type: " << v->getName();
            */
            // using a virtual Vehicle::clone() function is a better solution
            vehicles.push_back(v->clone());
        }
    }

    VehiclePark& operator=(const VehiclePark& other) {
        return VehiclePark(other);
    }
#endif

	void addVehicle(Vehicle* v) {
		vehicles.push_back(v);
	}

	void amortize() {
		for (auto it = vehicles.begin(); it != vehicles.end(); it++) {
			(*it)->amortizeParts();
		}
	}

	void printVehicles() {
		std::cout << "Vehicles in park are:" << std::endl;
		for (auto it = vehicles.begin(); it != vehicles.end(); it++) {
			(*it)->print();
		}
	}

	void repairCars() {
		for (auto it = vehicles.begin(); it != vehicles.end(); it++) {
            Car* c = dynamic_cast<Car*>(*it);
            if (c) c->repair();
		}
	}

    void repairBikes() {
        for (auto it = vehicles.begin(); it != vehicles.end(); it++) {
            MotorBike* b = dynamic_cast<MotorBike*>(*it);
            if (b) b->repair();
        }
    }

    template<class V>
    void repairVehicles() {
        for (auto it = vehicles.begin(); it != vehicles.end(); it++) {
            V* b = dynamic_cast<V*>(*it);
            if (b) b->repair();
        }
    }
};
