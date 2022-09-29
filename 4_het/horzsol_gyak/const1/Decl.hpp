using namespace std;

class sor_minta /* Osztály deklarációja */
 {
   private:
    char kar; /* kiirandó karakter */
    int ism;  /* soron belüli ismétlődések száma */
    int sor;  /* sorok száma, amennyiben megjelenjen */
    const int sK; // sK=5;
   public:
    sor_minta() : sK(4)  { kar='A'; ism=1; sor=1; }  /* Alapértelmezett konstruktor + inicializáló lista  */
    sor_minta(char kr, int im, int sr) : sK(4)  /* Alapérték beállító konstruktor + inicializáló lista */
     { kar=kr; ism=im; sor=sr; }
    void kiir(int i) const;
	  ~sor_minta()
     { cout << "A törléseket elvégeztem\n"; }
	 int getIsm() const { return ism; }
	 sor_minta& setIsm(int v_im);
	 sor_minta& setSor(int v_sr);
	 sor_minta& setKar(char v_kr);
   int getsK() const { return sK; }
 };