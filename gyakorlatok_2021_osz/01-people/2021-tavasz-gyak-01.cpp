// 2021-tavasz-gyak-01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#define LENGTH 2 // ez a sor V1 es V2

struct Person { // POD - plain old data
    std::string name;
    int age;
    Person(std::string name, int age) {
        this->name = name;
        this->age = age;
    }
    // Ha ez nincs, es letezik legalabb 1 masik konstruktor,
    // akkor nem hozhato letre Person tipusu valtozo parameterek
    // nelkul!! Ha van legalabb 1 konstruktor, muszaj valamelyiket
    // hasznalni.
    //Person() {
    //    this->name = "Anonymous";
    //    this->age = 0;
    //}
};

int main()
{
    Person people[LENGTH] = {
        Person("", 0),
        Person("", 0)
    };

    std::string tmpName;
    std::string tmpAge;
    for (int i = 0; i < LENGTH; i++) {
        std::cout << "enter name #" << i + 1 << ": ";
        std::getline(std::cin, tmpName);
        std::cout << "enter age #" << i + 1 << ": ";
        std::getline(std::cin, tmpAge);
        //people[i].init(tmpName, stoi(tmpAge));
    }

    for (int i = 0; i < LENGTH; i++) {
        std::cout << "person #" << i + 1 << ":\t" << people[i].name << ",\t\tage " << people[i].age << std::endl;
    }

    // V2 - mi tortenik, ha age-et pl. elfelejtjuk beallitani? memoriaszemet lesz ott!
    /*std::string tmpAge;
    for (int i = 0; i < LENGTH; i++) {
        std::cout << "enter name #" << i + 1 << ": ";
        std::getline(std::cin, people[i].name);
        std::cout << "enter age #" << i + 1 << ": ";

        std::getline(std::cin, tmpAge);
        people[i].age = stoi(tmpAge);
    }

    for (int i = 0; i < LENGTH; i++) {
        std::cout << "person #" << i + 1 << ":\t" << people[i].name << ",\t\tage " << people[i].age << std::endl;
    }*/

    // V1
    /*std::string names[LENGTH];
    int ages[LENGTH];

    std::string tmpAge;
    for (int i = 0; i < LENGTH; i++) {
        std::cout << "enter name #" << i + 1 << ": ";
        std::getline(std::cin, names[i]);
        std::cout << "enter age #" << i + 1 << ": ";

        std::getline(std::cin, tmpAge);
        ages[i] = stoi(tmpAge);
    }

    for (int i = 0; i < LENGTH; i++) {
        std::cout << "person #" << i + 1 << ":\t" << names[i] << ",\t\tage " << ages[i] << std::endl;
    }*/
    // V1 vege...
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
