#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Subject{
  vector<Observer*> observadores;
  string estado;
public:
  string getEstado(){ return estado; }
  void setEstado(string n) {
    estado = n;
    for (vector<Observer*>::iterator it = observadores.begin() ; it != observadores.end(); ++it){
      it->actualizacion();
    }
   }
  void agregarObserver(Observer ob){
    observadores.push_back(ob);
  }
};

class Observer{
protected:
  vector<Subject *> sujetos;
public:
  virtual void actualizacion() = 0;
};

class Trump : public Subject{
public:

};

class EPN : public Subject{

};

class LiderCoreano : public Subject{

};

class MVSNoticias : public Observer{

public:
  MVSNoticias(std::vector<Subject*> v)
  {
    sujetos = v;
    
  }
  void actualizacion()
  {
    for (vector<Observer*>::iterator it = sujetos.begin() ; it != sujetos.end(); ++it)
      std::cout << it->getEstado() << '\n';
  }
};
class TelevisaNoticias : public Observer{
public:
  TelevisaNoticias(std::vector<Subject*> v)
  {
    sujetos = v;
  }
  void actualizacion()
  {
    for (vector<Observer*>::iterator it = sujetos.begin() ; it != sujetos.end(); ++it)
      std::cout << it->getEstado() << '\n';
  }
};
class RadioRedNoticias : public Observer{
public:
  RadioRedNoticias(std::vector<Subject*> v)
  {
    sujetos = v;
  }
  void actualizacion()
  {
    for (vector<Observer*>::iterator it = sujetos.begin() ; it != sujetos.end(); ++it)
      std::cout << it->getEstado() << '\n';
  }
};
class NoticiasInternacionales : public Observer{
public:
  NoticiasInternacionales(std::vector<Subject*> v)
  {
    sujetos = v;
  }
  void actualizacion()
  {
    for (vector<Observer*>::iterator it = sujetos.begin() ; it != sujetos.end(); ++it)
      std::cout << it->getEstado() << '\n';
  }
};

int main(int argc, char const *argv[]) {

  return 0;
}
