#include "Decl.hpp"
 
int main(void)
 {
  hpmp[0]=-1; hpmp.push_back(6);
  for(int i=0; i<10; i++) { hpmp.push_back(7+i); } 
  hpmp.pop_back(); hpmp.resize(19); hpmp.push_back(20);
  for(auto it = hpmp.begin(); it != hpmp.end(); it++) { cout << (*it) << " "; }
  cout << "\n";
  // lambda kifejezések, metódus és fgv. paraméterként
  sort(hpmp.begin(), hpmp.end(),\
    [](int i, int j) -> bool { return i>j; }); cout << "\n";
  for(auto it = hpmp.cbegin(); it != hpmp.cend(); it++) { cout << *it << " "; }
  cout << "\n";
  hpmp.erase((remove_if(hpmp.begin(), hpmp.end(),\
     [](int i) -> bool { return ((i%2)==1 or (i%2)==-1); })),hpmp.end());  
  for(auto it = hpmp.cbegin(); it != hpmp.cend(); it++) { cout << *it << " "; }
  cout << "\n";
  cout << *max_element(hpmp.begin(), hpmp.end(),\
    [](int i, int j) -> bool { return i<j; }) << "\n";
  cout << *min_element(hpmp.begin(), hpmp.end(),\
    [](int i, int j) -> bool { return i<=j; }) << "\n";
  cout << count_if(hpmp.begin(), hpmp.end(),\
     [](int i) -> bool { return ((i%2)==0 && i!=0); }) << "\n"; cout << "\n";
  // önálló lambda kifejezések, a v.é. típusa a fordítóra bízva
  cout << [](int x){ return x*x; }(5) << endl;
  cout << [](int x){ return x*x; }(count_if(hpmp.begin(), hpmp.end(),\
          [](int i){ return ((i%2)==0 && i!=0); })) <<  "\n\n";
  // [=] érték ill. [&] referencia szerinti változó-átvétel
  int j=7, k=10;
  cout << [=](int x){ return x*k + j; }(5)\
       << "\tj = " << j << "\tk = " << k << endl;
  cout << [&](int x){ return x*(k++) + (++j)++; }(5)\
       << "\tj = " << j << "\tk = " << k << endl;
//  cout << [=,&j](int x){ return x*(k++) + (++j)++; }(5)\
//       << "\tj = " << j << "\tk = " << k << endl;
  return 0;
}