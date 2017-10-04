//Jesús Horacio Rojas Cortés A01020026
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Observer{
protected:
  string name;
public:
  Observer () = default;
  virtual void actualizacion(string a) = 0;
};

class Subject{
protected:
  vector<Observer*> observadores;
  string name;
public:
  Subject() = default;
  void notificacion() {
    for (vector<Observer*>::iterator it = observadores.begin() ; it != observadores.end(); ++it){
      (*it)->actualizacion(name);
    }
   }
  void agregarObserver(Observer* ob){
    observadores.push_back(ob);
  }
  void borrarObserver(Observer* ob){
    //Iterate the observers, if found delete, alert if not
    int i = 0;
    for(vector<Observer*>::iterator it = observadores.begin(); it != observadores.end(); it++,i++ ){
      if(observadores.at(i)==ob){
        // erase the element
        observadores.erase (observadores.begin()+i);
        std::cout << "Observador eliminado" << '\n';
        return;
      }
    }
    std::cout << "¡Este observador no estaba suscrito!" << '\n';
  }
};

class Trump : public Subject{
public:
  Trump(){
    name = "Trump";
  }
};

class EPN : public Subject{
public:
EPN(){
  name = "EPN";
  }
};

class LiderCoreano : public Subject{
public:
LiderCoreano()  {
  name = "Kim Jong-Un";
  }
};

class MVSNoticias : public Observer{

public:
  MVSNoticias()
  {
    name = "MVS Noticias";
  }
  void actualizacion(string a)
  {
      std::cout <<name + " nueva noticia de " + a<< '\n';
  }
};
class TelevisaNoticias : public Observer{
public:
  TelevisaNoticias()
  {
    name = "Televisa Noticias";
  }
  void actualizacion(string a)
  {
      std::cout <<name + " nueva noticia de " + a<< '\n';
  }
};
class RadioRedNoticias : public Observer{
public:
  RadioRedNoticias()
  {
    name = "Radio Red";
  }
  void actualizacion(string a)
  {
    std::cout <<name + " nueva noticia de " + a<< '\n';
  }
};
class NoticiasInternacionales : public Observer{
public:
  NoticiasInternacionales()
  {
    name = "Noticias Internacionales";
  }
  void actualizacion(string a)
  {
    std::cout <<name + " nueva noticia de " + a<< '\n';
  }
};

int main(int argc, char const *argv[]) {
  Trump trump;
  EPN pena;
  LiderCoreano kim;
  MVSNoticias * mvs = new MVSNoticias();
  TelevisaNoticias * tele = new TelevisaNoticias();
  RadioRedNoticias * radiored = new RadioRedNoticias();
  NoticiasInternacionales * notiint = new NoticiasInternacionales();
  trump.agregarObserver(mvs);
  trump.agregarObserver(tele);
  trump.agregarObserver(radiored);
  trump.agregarObserver(notiint);
  pena.agregarObserver(tele);
  pena.agregarObserver(radiored);
  kim.agregarObserver(notiint);
  trump.notificacion();
  pena.notificacion();
  kim.notificacion();
  trump.borrarObserver(mvs);
  trump.notificacion();

  return 0;
}
