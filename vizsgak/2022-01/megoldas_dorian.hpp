#pragma once
const int szaz = 100;
const int ezer = 1000;
const int haromezerhatszaz = 3600;
const int hatvan = 60;

class Sports
{
protected:
  int distance;
  double time;

public:
  Sports(int distance, int time) : distance(distance), time(time) {}
  /*virtual double average() const=0;*/ // HÁRMASÉRT
  /*virtual string getType() const=0;*/ // NÉGYESÉRT
  virtual void computeSaveAndPrintAverage() const = 0;
  virtual ~Sports() = default;
};
class Running : public Sports
{
public:
  Running(int distance, int time) : Sports(distance, time) {}
  ~Running() = default;
  /*  double average() const override { //HÁRMASÉRT
      double result;
      result = (time/hatvan)/(distance/szaz);

      return result;
    }*/
  /*string getType() const override {return "Running";}*/ // NÉGYESÉRT
  void computeSaveAndPrintAverage() const override
  {
    double result;
    result = (time / hatvan) / (distance / szaz);
    cout << "A futás átlaga: " << result << " min / km\n";
  }
};
class Swimming : public Sports
{
public:
  Swimming(int distance, int time) : Sports(distance, time) {}
  ~Swimming() = default;
  /*  double average() const override { //HÁRMASÉRT
      double result;
      result=time/(distance/szaz);

      return result;
    }*/
  /*string getType() const override {return "Swimming";}*/ // NÉGYESÉRT
  void computeSaveAndPrintAverage() const override
  {
    double result;
    result = time / (distance / szaz);
    cout << "Az úszás átlaga: " << result << " mp / meter\n";
  }
};
class Cycling : public Sports
{
public:
  Cycling(int distance, int time) : Sports(distance, time) {}
  ~Cycling() = default;
  /*  double average() const override { //HÁRMASÉRT
      double result;
      result=(distance/ezer)/(time/haromezerhatszaz);

      return result;
    }*/
  /*string getType() const override {return "Cycling";}*/ // NÉGYESÉRT
  void computeSaveAndPrintAverage() const override
  {
    double result;
    result = (distance / ezer) / (time / haromezerhatszaz);
    cout << "A kerékpározás átlaga: " << result << " min / km\n";
  }
};

/*void printAverages(vector<Sports*>pointers){ //HÁRMASÉRT
  for(size_t ind = 0; ind < pointers.size(); ind++){
    cout << pointers[ind]->average();
    if(ind+1 == pointers.size()){
      break;

    }else{
      std::cout << " - ";
    }

  }

  cout << '\n';
};*/

/*void printNamesOfSports(vector<Sports*> pointers) { //NÉGYESÉRT
  for(size_t indi =0; indi<pointers.size(); indi++){
    if(pointers[indi]->getType()=="Swimming"){
      cout<<"Úszás\n";
    }else if(pointers[indi]->getType()=="Cycling"){
      cout<<"Biciklizés\n";
    }else if(pointers[indi]->getType()=="Running"){
      cout<<"Futás\n";}
  }
};*/
