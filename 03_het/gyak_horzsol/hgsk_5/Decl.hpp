using namespace std;

#define SK 4			/* Kiírandó sorok száma */

class sor_minta 		/* Osztály deklarációja */
{
   	private:
		char kar; 		/* kiirandó karakter */
		int ism;  		/* soron belüli ismétlődések száma */
		int sor;  		/* sorok száma, amennyiben megjelenjen */
   	public:
		sor_minta() { kar='A'; ism=1; sor=1; }  	/* Alapértelmezett konstruktor */
		sor_minta(char kr, int im, int sr)          /* Alapérték beállító konstruktor */
			{ kar=kr; ism=im; sor=sr; }
		void kiir(int i);
		~sor_minta()			/* Destruktor */ 
			{ cout << "A program hibátlanul lefutott!\n"; }
		int getIsm() { return ism; }
		sor_minta& setIsm(int v_im);
		sor_minta& setSor(int v_sr);
		sor_minta& setKar(char v_kr);
 };