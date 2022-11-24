#pragma once
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

/* itt soruljuk fel azokat az osztályokat, melyek körkörös hívásban vesznek részt
ezek az ozstályok csak pointerekkel és mutatókkal tudnak kommunikálni */
class in_ch; // forward deklaráció, de '*' vagy '&'!

class frnd  // barát osztály
 {
  public:
   frnd() { }
   void olvas(in_ch* x_tri);            /* itt olvassa ki az adatokat */
   ~frnd()
    { cout << "\nFelszabadítottam a barát adatszerkezetének a memóriacímét: "; }
 };

class tri_race
 {
  int sum;
  protected:
   class memb
    {
      string lic;
      int swim, cycle, run, depo, ij;
     public:
      string getLic() const { return lic; }
      int getSwim() const { return swim; }
      int getCycle() const { return cycle; }
      int getRun() const { return run; }
      int getDepo() const { return depo; }
      int getIj() const { return ij; }
      void setLic(string lc) { lic=lc; }
      void setSwim(int sw) { swim=sw; }
      void setCycle(int cyc) { cycle=cyc; }
      void setRun(int rn) { run=rn; }
      void setDepo(int dp) { depo=dp; }
      void setIj(int t) { ij=t; }
      memb() { cout << "\nAz alapértelmezett szülő-tag adatszerkezet létrejött: "; }
      ~memb() { cout << "\nFelszabadítottam a szülő-tag adatszerkezet memóriacímét: "; }
	  //friend class frnd;
	  //friend void frnd::olvas(in_ch*);
    };
   memb tagok;
   tri_race() : sum(0)
    { tagok.setLic("--------"); tagok.setSwim(0); tagok.setCycle(0); tagok.setRun(0);
      tagok.setDepo(0); tagok.setIj(0);
      cout << "\nAz alapértelmezett szülő-adatszerkezet létrejött: ";}  
   tri_race(string lc, int sw, int cyc, int rn, int dp, int t) : sum(0)
     { tagok.setLic(lc); tagok.setSwim(sw); tagok.setCycle(cyc); tagok.setRun(rn);
       tagok.setDepo(dp); tagok.setIj(t);
       cout << "\nA paraméteres szülő-adatszerkezet létrejött: "; }
   int getSum() const { return sum; }
  public:
   tri_race& setSum();
   virtual tri_race& kiir_cel()=0;
   virtual ~tri_race()
    { cout << "\nFelszabadítottam a szülő-adatszerkezet memóriacímét: "; }
   friend class frnd;
   friend void frnd::olvas(in_ch*);
	};

class h_m_s
 {
   const int oRA, pRC;
   protected:
    vector<int> hpmp={0,0,0};
    vector<int> sps;
    vector<string> jelek={"Ú:\t\t","B:\t\t","D:\t\t","Ú+B+D:\t","F:\t\t","T-:\t\t","Cél idő:"};
    vector<int>::iterator it;
    vector<string>::iterator j_it;
    h_m_s() : oRA(3600), pRC(60)
     { cout << "\nAz alapértelmezett átszámoló szülő-adatszerkezet létrejött: "; }
    void s_hms(int s)
     { hpmp.push_back(s/oRA); hpmp.push_back((s%oRA)/pRC);
       hpmp.push_back((s%oRA)%pRC); }	 
   public:
    void kiir_i1() const;
    virtual h_m_s& kiir_cel()=0;
    ~h_m_s()
     { cout << "\nFelszabadítottam az átszámoló szülő-adatszerkezet memóriacímét: "; }
 };
	
class in_ch : public tri_race, public h_m_s
 {
    int kat;
    int getKat() const { return kat; }
    void setKat(int kt) { kat=kt; }
   protected:
    void kiir_i4();	
   public:
    in_ch() : tri_race() { setKat(0); cout << "\nAz alapértelmezett gyerek-objektum létrejött: "; }
    in_ch(string lc, int sw, int cyc, int rn, int dp, int t, int kt) : \
           tri_race(lc, sw, cyc, rn, dp, t)
     { setKat(kt); cout << "\nA paraméteres gyerek-objektum létrejött: "; }
   in_ch& kiir_cel() override;
   virtual ~in_ch()
    { cout << "\nFelszabadítottam a gyerek-objektum saját adatának a memóriacímét: "; }
   in_ch(const in_ch&) = delete;
   in_ch& operator=(const in_ch&) = delete;
   /* a barát osztály mindenhez hozzáfér, a privát változókhoz is */
   friend class frnd;
   friend void frnd::olvas(in_ch*);     /* itt hívja meg a barát osztály metódusát */
 };
 
class in_gr_ch : public in_ch
 {
    char nem;
    char getNem() const { return nem; }
    void setNem(char nm) { nem=nm; }
   public:
    in_gr_ch() : in_ch() { setNem('N'); }
    in_gr_ch(string lc, int sw, int cyc, int rn, int dp, int t, int kt, char nm) : \
           in_ch(lc, sw, cyc, rn, dp, t, kt), nem(nm)
     { setNem(nm); cout << "\nA paraméteres unoka-objektum létrejött: "; }
   in_gr_ch& kiir_cel() override;
   virtual ~in_gr_ch()
    { cout << "\nFelszabadítottam az unoka-objektum saját adatának a memóriacímét: "; }
 };

void mind1(vector<in_ch*> x_tri);
void felsz(vector<in_ch*> x_tri);