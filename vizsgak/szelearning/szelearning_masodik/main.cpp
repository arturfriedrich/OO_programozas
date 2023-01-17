#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

#include "masodik.hpp"

int main()
{
    Mediator mindenki;
    Mediator kalapjakabFriends;

    Person kalapjakab("Kalap Jakab");
    Person larifanni("Lari Fanni");
    Person mokamester("Moka Mester");

    mindenki.add(&kalapjakab);
    mindenki.add(&larifanni);
    mindenki.add(&mokamester);

    kalapjakabFriends.add(&kalapjakab);
    kalapjakabFriends.add(&larifanni);

    mindenki.send(&mokamester, "Jottok a humor estemre?");
    kalapjakabFriends.send(&larifanni, "Jaj ne, mar megint ezek a faviccek...");
}