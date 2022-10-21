#include <iostream>

using namespace std;

#define SK 4			/* Kiírandó sorok száma */

class sor_minta 		/* Osztály deklarációja */
{
   	private:
		char kar; 		/* kiirandó karakter */
		int ism;  		/* soron belüli ismétlődések száma */
		int sor;  		/* sorok száma, amennyiben megjelenjen */
		int v_m;  		/* változtatás mértéke az "ism"-re */
   	public:
		sor_minta() { kar='A'; ism=1; sor=1, v_m=0; cout << "\n Alapértelmezett konstruktor\n"; }  /* Alapértelmezett konstruktor */
		sor_minta(char kr, int im, int sr)			/* Alapérték beállító konstruktor */
			{ kar=kr; ism=im; sor=sr; cout << "\n Alapérték beállító konstruktor\n"; }
		void kiir(int i);
		void elemek() { cout << kar <<ism <<sor << endl; }
		void v_i();
		~sor_minta()		/* Destruktor */ 
			{ cout << "A program hibátlanul lefutott!\n"; }
 };