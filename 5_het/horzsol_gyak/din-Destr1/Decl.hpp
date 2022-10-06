#pragma once
#include <iostream>

using namespace std;

/* ez az osztály csak a tagváltozókat, gettereket és settereket tartalmazza, valamint a konstruktorokat, nincsenek destrukturok */
class sor_minta 			/* Osztály deklarációja */
{
	private:
    	char kar; 			/* kiirandó karakter */
    	int ism;  			/* soron belüli ismétlődések száma */
    	int sor;  			/* sorok száma, amennyiben megjelenjen */
   	public:
   		/* ha nincsen lényege, el lehet hagyni a konstruktort, de azért érdemes */
    	sor_minta() { kar='A'; ism=1; sor=1; }  		/* Alapértelmezett konstruktor  */
    	sor_minta(char kr, int im, int sr) { 			/* Alapérték beállító konstruktor  */
     		kar=kr; ism=im; sor=sr; 
		}
	 	int getIsm() const { return ism; }
   		int getSor() const { return sor; }
   		char getKar() const { return kar; }
		sor_minta& setIsm(int v_im);
		sor_minta& setSor(int v_sr);
		sor_minta& setKar(char v_kr);
     	/* ~sor_minta() { cout << "!!!" << endl; } */
 };

/* ez egy idegen osztály */
class dm_kiir
{
  	private:
		/* mivel alapvetően nem látszódik a másik osztály, itt rá kell mutatnunk 
			ez az osztály, nem fogja közvetlenül elérni a másik osztály tagváltozóit, csak a muatató segítségével */
		sor_minta* mutat;
		const int sK;
  	public:
   		dm_kiir() : sK(4) {								/* Alapértelmezett konstruktor + inicializáló lista  */
			/* a new szó után az alapértelmezett konstruktorra hivatkozom, úgy foglalok 
			dinamikus memóriaterületet egy idegen osztályban, hogy a default osztályra hivatkozok */
			mutat = new sor_minta();
			cout << "Az alapértelmezett objektum címe: ";
			cout << mutat << endl;
    	}
   		dm_kiir(char kr, int im, int sr) : sK(4) { 		/* Alapérték beállító konstruktor + inicializáló lista */
			/* itt is egy konstruktort hívok, megadunk neki paramétereket is */
			mutat = new sor_minta(kr, im, sr);
			cout << "A paraméteres objektum címe: ";
			cout << mutat << endl;
    	}
		void kiir(int i) const;
		int getsK() const { return sK; }
   		/* visszaadja azt a memóriacímet amire a mutató mutat, ami jelenleg az osztály objektuma */
		sor_minta* getMutat() const { return mutat; }
		/* felszabadítja az objektumoknak odaadott memóriacímeket */
   		~dm_kiir() {                                    /* Destruktor */ 
			delete mutat;
			cout << "Felszabadítottam az objektum memóriacímét, amely a: ";
			cout << mutat << endl;
     	}
 };
 
 /* const objektumot csak const metódus tud kezelni */
void mind(const dm_kiir& nyzj, dm_kiir& es, dm_kiir& zzj, int s_K);