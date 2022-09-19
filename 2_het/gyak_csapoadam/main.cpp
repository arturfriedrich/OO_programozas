#include "hallgatoDb.cpp"

using namespace Neptun; // nagy projekteknel nem javasolt
// mivel baj, ha 2 nevterben is letezik u.az a tipus vagy fv

int main() {
	HallgatoDb hallgatok;
	hallgatok.add("Kocsis Balint", "RBV23Q");
    hallgatok.add("Varga Árpád", "ER34N5");
    hallgatok.add("Kiss Aladár", "IKR2TR");
	hallgatok.printDb();
}