#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <type_traits>

#include "/home/g14/uni/sze_oo_programozas/mintavizsga/minta_vizsga_3/megoldas_csapo.hpp"

// A 2-es jegyert keszitse el az alabbi osztalyokat:
//
// Oltas osztaly - absztrakt ososztaly
// - ennek az osztalynak van egy const std::string&-et varo konstruktora, ami beallitja az Oltas nevet!
// - ennek az osztalynak van egy getName() metodusa ami visszaadja az oltas nevet
// - ennek az osztalynak van egy getType() nevu pure virtual metodusa is, ami std::string-et ad vissza, de nincs kifejtve!

// Pfizer osztaly, amely publikus modon szarmazik az Oltas osztalybol
// Ez egy singleton osztaly, vagyis:
// - konstruktora meghivja ugyan az ososztaly konstruktorat (inicializalo listaban), de a konstruktor maga privat!
// - copy constructora vagy privat, vagy le van tiltva! ( = delete;)
// - copy assignment operatora vagy privat, vagy le van tiltva! ( = delete;)
// - van egy public, static Oltas* GetInstance() metodusa, amely egy static pointert ad vissza
// - megvalositja az ososztaly getType() metodusat is, es azt a stringet adja vissza, hogy "mRNA"
// Singleton osztalyokrol hatteranyag: https://u.pcloud.link/publink/show?code=XZMR4rXZsHduf1qXGq4bAzr2cNPaCX5friLV (8-9. oldal)

// elvart kimenet:
// Igen, pfizer es pfizer2 cime ugyanaz!
// Pfizer neve es tipusa : Pfizer, mRNA
// Igen, sinovac es sinovac2 cime ugyanaz!
// Sinovac neve es tipusa : Sinovac, adenovirus

int main()
{
    static_assert(std::is_abstract<Oltas>(), "Oltas-nak absztrakt osztalynak kell lennie!");
    Oltas *pfizer = Pfizer::GetInstance();
    Oltas *pfizer2 = Pfizer::GetInstance();

    if (pfizer == pfizer2)
    {
        std::cout << "Igen, pfizer es pfizer2 cime ugyanaz!" << std::endl;
    }

    std::cout << "Pfizer neve es tipusa: " << pfizer->getName() << ", " << pfizer->getType() << std::endl;

    Oltas *sinovac = Sinovac::GetInstance();
    Oltas *sinovac2 = Sinovac::GetInstance();

    if (sinovac == sinovac2)
    {
        std::cout << "Igen, sinovac es sinovac2 cime ugyanaz!" << std::endl;
    }

    std::cout << "Sinovac neve es tipusa: " << sinovac->getName() << ", " << sinovac->getType() << std::endl;

    // 4-es jegyert:
    std::vector<Oltas *> oltasok1 = {Sinovac::GetInstance(), Sinovac::GetInstance(), Pfizer::GetInstance()};
    std::vector<Oltas *> oltasok2 = {Pfizer::GetInstance(), Sinovac::GetInstance(), Pfizer::GetInstance()};

    OltasiIgazolas oltasiig1(oltasok1);
    OltasiIgazolas oltasiig2(oltasok2);

    std::cout << "Elso delinkvens ennyi Pfizer oltast kapott: " << oltasiig1.getCount(Pfizer::GetInstance()) << std::endl;
    std::cout << "Masodik delinkvens ennyi Pfizer oltast kapott: " << oltasiig2.getCount(Pfizer::GetInstance()) << std::endl;
    std::cout << "Masodik delinkvens ennyi Sinovac oltast kapott: " << oltasiig2.getCount(Sinovac::GetInstance()) << std::endl;

    Kovetelmenyek kovetelmenyek1 = {
        std::make_pair<Oltas *, int>(
            Pfizer::GetInstance(), 2)};
    Kovetelmenyek kovetelmenyek2 = {
        {Pfizer::GetInstance(), 2},
        {Sinovac::GetInstance(), 2}};
    /*
        BeutazasiSzabalyozas ketPfizer(kovetelmenyek1);
        BeutazasiSzabalyozas ketBarmi(kovetelmenyek2);

        if (ketPfizer.isKaranten(&oltasiig1))
        {
            std::cout << "Onnek sajnos nincs 2 pfizere..." << std::endl;
        }
        else
        {
            std::cout << "Jojjon, baratunk!" << std::endl;
        }
        */
}