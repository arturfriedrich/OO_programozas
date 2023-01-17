#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

class Person
{
    protected:
        std::string name;
    public:
        Person(std::string name) : name(name) { }           // konstruktor amivel beállítjuk a Person nevét
        void notify(std::string msg, Person *sender) {      // notify() metódus, amely megkapja az üzenetet, a küldő címét, majd kiír a konzolra
            std::cout << name << " megkapta " << sender->name << " uzenetet: " << msg << std::endl;
        }
};

class Mediator
{
    std::vector<Person *> people;                           // vektor amely eltárolja a Person címeket

    public:
        void add(Person *pp) { people.push_back(pp); }      // felírja a Mediator-ra az adott Person objektumot
        void send(Person *senderp, std::string msg) {       // fogadja, hogy ki és milyen üzenetet küld, meghívja az öszes notify() metódusát az adott Person-nak
            for ( Person *pp : people ) {                   // kiváve annak, aki küldi az üzenetet
                if ( pp != senderp ) {
                    pp->notify(msg, senderp);
                }
            }
        }
};
