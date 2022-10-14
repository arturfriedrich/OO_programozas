#pragma once
#include <iostream>

using namespace std;

class sor_minta 			/* Osztály deklarációja */
{
	private:
		char kar; 			/* kiirandó karakter */
		int ism;  			/* soron belüli ismétlődések száma */
		int sor;  			/* sorok száma, amennyiben megjelenjen */
	public:
		sor_minta() { kar='A'; ism=1; sor=1; }  	/* Alapértelmezett konstruktor  */
		sor_minta(char kr, int im, int sr)  		/* Alapérték beállító konstruktor */
			{ kar=kr; ism=im; sor=sr; }
		int getIsm() const  { return ism; }
		int getSor() const { return sor; }
		char getKar() const { return kar; }
		sor_minta& setIsm(int v_im);
		sor_minta& setSor(int v_sr);
		sor_minta& setKar(char v_kr);
};

class dm_kiir
{
	private:
		sor_minta* mutat;
		const int sK;
	public:
		dm_kiir() : sK(4)   						/* Alapértelmezett konstruktor + inicializáló lista  */
		{ 
			mutat = new sor_minta();
			cout << "Az alapértelmezett objektumot létrehoztam: ";
			cout << mutat << endl;
		}
		dm_kiir(char kr, int im, int sr) : sK(4)  	/* Alapérték beállító konstruktor + inicializáló lista */
		{ 
			mutat = new sor_minta(kr, im, sr); 
			cout << "A paraméteres objektumot létrehoztam: ";
			cout << mutat << endl;
		}
		void kiir(int i) const ;
		int getsK() const { return sK; }
		sor_minta* getMutat() const { return mutat; }
		~dm_kiir()                              	/* Destruktor */
			{ 
				delete mutat;
				cout << "Felszabadítottam az objektum memóriacímét, amely a: ";
				cout << mutat << endl; 
			}
		// dm_kiir(const dm_kiir&) = delete;        /* copy letiltása */
		dm_kiir(const dm_kiir& masolat) : sK(4)  	/* Copy konstruktor + inicializáló lista, attól lesz copy hogy mit írok a zárójelbe */
			{
				mutat = new sor_minta(masolat.mutat->getKar(), masolat.mutat->getIsm(), masolat.mutat->getSor());
				cout << "A klón objektumot létrehoztam: ";
				cout << mutat << endl;
			}
		// dm_kiir& operator=(const dm_kiir&) = delete;         /* operátor felüldefiniálás */
		dm_kiir& operator=(const dm_kiir& felir)  				/* Assignment konstruktor */
			{
				delete mutat;
				cout << "Felszabadítottam a felülírandó objektum memóriacímét, amely a: ";
				cout << mutat << endl; 
				mutat = new sor_minta(felir.mutat->getKar(), felir.mutat->getIsm(), felir.mutat->getSor());
				cout << "A felülírt objektumot létrehoztam: ";
				cout << mutat << endl;
				return *this;                                	/* van visszatérési értéke referenciaként */
			}
 };

void mind(const dm_kiir& nyzj, dm_kiir& es, dm_kiir& zzj, int s_K);
