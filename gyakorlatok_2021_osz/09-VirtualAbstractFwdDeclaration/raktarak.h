#pragma once


class Raktar {
	std::vector<Termek*> termekek;
	// Ezeknek addig volt ertelme (hibatlan es hibasDarabszam)
	// amig TermekTipusokat taroltunk itt... mert 1 termektipusbol
	// lehetett akarhany hibas meg hibatlan darab.
	// De most konkret termekeket tarolunk, tehat ha az egyik
	// (hibas vagy hibatlanDarabszam) erteke egy indexnel 0, akkor
	// a masik 1, tehat ez redundans!
	// Raadasul most mar inkabb a termek attributuma, hogy hibas-e
	// vagy hibatlan. (Korabban nem modelleztuk a termekeket, csak a
	// termektipust. Egy termektipus benne lehetett egyszerre tobb
	// raktarban is, igy ertelmes volt, hogy a raktar tarolja ezt.
	// De egy termek fura lenne, ha tobb raktarban is benne lenne)
	/*std::vector<int> hibatlanDarabszam;
	std::vector<int> hibasDarabszam;*/
public:
	~Raktar();
	Raktar& add(TermekCsalad* t, int quantity);
	// addHibas-t csak a Csereszavatos es Garancialis
	// osztalyok javit metodusaban hivjuk meg, de ez is
	// okafogyott, hiszen nem termekcsaladot kell javitani
	// hanem konkret termeket
	void addHibas(Termek* term);
	void kiad(TermekCsalad* term, int db);
	void visszavesz(TermekCsalad* t, int db);
	void print();
};