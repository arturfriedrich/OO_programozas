#include <type_traits>
#include <string>
#include <iostream>
#include "/home/g14/uni/sze_oo_programozas/mintavizsga/minta_vizsga_5/megoldas_dani.hpp"

// Keszitsen el 3 osztalyt: Device, Computer es Laptop
// Device egy absztrakt ososztaly, melynek print() metodusa
// nincs megvalositva
// Computer es Laptop egyfajta Device (szarmaznak belole) es
// megvalositjak a print() metodust

// Keszitsen el egy DeviceFactory nevu osztalyt, melynek egyetlen
// publikus statikus fv-e van:
// Device* NewDevice(const std::string&)
// szignaturval

int main()
{
    static_assert(
        std::is_abstract<Device>(),
        "Device ought to be abstract.");

    Device *computer =
        DeviceFactory::NewDevice(DeviceType::Computer, "IBM Business");
    Device *laptop =
        DeviceFactory::NewDevice(DeviceType::Laptop, "Asus TUF");

    computer->print(); // IBM Business gep vagyok
    laptop->print();   // Asus TUF laptop vagyok

    delete computer;
    delete laptop;
}