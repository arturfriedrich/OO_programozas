#pragma once

#include<string>

using string = std::string;

class Part {
protected:
	string name;
    int age = 0;
    const int lifetime;
public:
	Part(const string& name, int lifetime) : name(name), lifetime(lifetime) {}

    void amortize() {
        ++age;
    }

	int getAge() const {
		return age;
	}

	string getName() {
		return name;
	}

    bool isHealthy() const {
        return age <= lifetime;
    }

    void repair() {
        age = 0;
    }
};
