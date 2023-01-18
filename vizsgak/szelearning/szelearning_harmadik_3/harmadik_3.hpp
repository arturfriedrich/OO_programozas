#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

class Termek 
{
    protected:
        float mennyiseg;
        int ar;
        std::string mertekegyseg;
    public:
        Termek(float mennyiseg, int ar, std::string mertekegyseg) : mennyiseg(mennyiseg), ar(ar), mertekegyseg(mertekegyseg) { }
        virtual ~Termek() { }
        virtual double getTotal() {                 // visszaadja, a termék árát
            return mennyiseg * ar;
        }
        void setAr(int newAr) {                     // nullázni lehet vele a termék árát, mintha kivettük volna a kosárból
            ar = newAr;
        }
};

class Barack : public Termek
{
    public:
        Barack(double mennyiseg, int ar, std::string mertekegyseg) : Termek(mennyiseg, ar, mertekegyseg) { }
};

class Tej : public Termek
{
    double zsirtartalom;            // azért kell külön zsirtaltarlam létrehozni, mivel a Termek csak 3 paramétert fogad, itt viszont 4 van

    public:
        Tej(double m, double zs, int ar, std::string megy) : Termek(m, ar, megy), zsirtartalom(zs) { }
};

class TrappistaSajt : public Termek
{
    double kedvezmeny;              // azért kell külön kedvezmeny létrehozni, mivel a Termek csak 3 paramétert fogad, itt viszont 4 van

public:
    TrappistaSajt(double m, int ar, std::string megy, double kedv) : Termek(m, ar, megy), kedvezmeny(kedv) {}
    double getTotal() {
        return mennyiseg * ar * (1.0 - kedvezmeny);
    }
};

class Kosar
{
    std::vector<Termek *> tartalom;         // eltarol egy vektort Termek pointerekel

    public:
        ~Kosar() {                          // destruktor a memóriaszivárgás elkerülésének érdekében
            for ( Termek *t : tartalom ) {
                delete t;
            }
        }

        void add(Termek *t) { tartalom.push_back(t); }      // új terméket adhatok hozzá
        void total() {                                      // kiírja a teljes árat
            std::cout << "Kosar erteke: ";
            double teljes_ertek = 0;
            bool elso_termek = true;
            for ( Termek *tp : tartalom ) {
                double resz_osszeg = tp->getTotal();
                teljes_ertek += resz_osszeg;
                if ( elso_termek ) {
                    std::cout << resz_osszeg;
                    elso_termek = false;
                } else {
                    std::cout << " + " << resz_osszeg;
                }
            }
            std::cout << " = " << teljes_ertek << std::endl;
        }
        void remove(std::string mitToruljunk) {         // ki lehet vele törölni egy elemet
            for ( Termek *tp : tartalom ){
                TrappistaSajt *tsp = dynamic_cast<TrappistaSajt *>(tp);     // megadjuk, hogy melyiket szeretnénk törölni
                if ( tsp ) {
                    tp->setAr(0);                       // a setAr(0)-val nullázzuk az árát az adott terméknek
                }
            } 
        } 
};
