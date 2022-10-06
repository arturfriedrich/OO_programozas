#include "1.cpp"

int main(void)
 {
    /* az idegen osztáylból példányosítunk, a dinamikus memóratartományban jönnek létre */
  dm_kiir nyzj('[',2,2), es('&',3,3), zzj(']',4,1)/*, alap*/;  /* Objektumok példányosítása, beállítása */
  const dm_kiir alap;
  mind(nyzj,es,zzj,alap.getsK());
  /* a setKar vár egy objektumot a setSort-tól, amit megkapott a setIsm nevű metódustól, amit illesztünk egy objektumhoz,
     egy pointert ad vissza, ami a sorminta osztályra mutat */
  es.getMutat()->setIsm(4).setSor(-1).setKar('@');
  /* es.getIsm(); az nemó, mert az es osztálynak nincsen getIsm metódusa */
  es.getMutat()->getIsm();
  mind(nyzj,es,zzj,alap.getsK());
  return 0;
  /* a memória felszabadítását hátulról kezdjük, különben kitöröljük azokat a doolgokat, amiket még nem példányosítottunk */
}