#include "Decl.hpp"

int main(void)
 {
  tort t1(2, 3);
  tort t2(4, 5);
  cin >> t1 >> t2; // -2/6 és 8/-5
  tort t3 = t1 * t2; // ambiguous esete (kétértelmű) 
  //tort t3 = t1.operator*(t2); // egyszerre mindkettő
  //t3 = operator*(t1, t3); // egyszerre mindhárom
  cout << "\n Alap kiírása a törtnek ('*'):\n\t\t t3 = "\
       << t3.getSzaml() << "/" << t3.getNevz() << endl;
  cout << "\n Túlterhelt kiírása a törteknek ('*');\n\t\t t1 = "\
       << t1 << "\n\t\t t2 = " << t2 << "\n\t\t t3 = " << t3 << endl;
  t3 *= t2;
  cout << "\n Túlterhelt kiírása a törtnek ('*='):\n\t\t t3 = " << t3 << endl;
  int i = 2 * 3;         // szorzás operátorát nem felül írta, csak tultöltötte
  cout << "\n Alap kiírása az egésznek:\n\t\t i = " << i << endl;
  tort t4 = t1 * i; // *2 illetve 2 * t1!? és 2 * t1 * 2
  cout << "\n Túlterhelt 'operator*' egész szorzással:\n\t\t t4 = "\
       << t4 << endl;
  t4 *= 2;
  cout << "\n Túlterhelt 'operator*=' egész szorzással:\n\t\t t4 = "\
       << t4 << endl;
  cout << "\n" << t1 << " és " << t2 << " és " << t3 << " és " << t4 << endl;
  return 0;
}