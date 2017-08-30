#include <iostream>
#include <string>
using namespace std;
class Mundo
{
public:
  Mundo(string nm){
    nombreMundo = nm;
  }
  string nombreMundo;
};

class Personaje{
public:
    Personaje()= default;
    string nombre;
    int telefono;
    string correo;
    Mundo * mundo;
    virtual Personaje * clone()=0;
    Personaje(string n){ nombre = n;}
};

template <class SubClase>
class ClonPersonaje : public Personaje{
public:
  Personaje * clone()
  {
    return new SubClase(dynamic_cast<SubClase&>(*this));
  }
};

class Princesa : public ClonPersonaje<Princesa>
{
  public:
    Princesa(string n)
    {
      nombre = n;
    }
    Princesa(const Princesa& p)
    {
      nombre = p.nombre;
      telefono = p.telefono;
      correo = p.correo;
      mundo = new Mundo(p.mundo->nombreMundo);
    }
     void grita(){
       std::cout << "aaaaaaaaaaaa" << '\n';
     }
};


class Villano : public ClonPersonaje<Villano>
{
  public:

    Villano(string n){
       nombre = n;
    }
    Villano(const Villano& p)
    {
      nombre = p.nombre;
      telefono = p.telefono;
      correo = p.correo;
      mundo = new Mundo(p.mundo->nombreMundo);
    }
     void grita(){
       std::cout << "Te atrapé" << '\n';
     }
};

class Heroe : public ClonPersonaje<Heroe>
{
  public:
    Heroe(string n){
      nombre = n;
    }
    Heroe(const Heroe& p)
    {
      nombre = p.nombre;
      telefono = p.telefono;
      correo = p.correo;
      mundo = new Mundo(p.mundo->nombreMundo);
    }
     void salvar(){
       std::cout << "Te salvé" << '\n';
     }
};

int main(int argc, char const *argv[]) {
  Princesa* pri = new Princesa("Rapunzel");
  pri->correo="princesaamoros@hotmail.com";
  pri->telefono=556765906;
  pri->mundo = new Mundo("Paleta");
  Princesa * p = dynamic_cast<Princesa*> (pri->clone());
  std::cout << "Princesa 1" <<std::endl;
  std::cout<<pri->nombre<<std::endl;
  std::cout<<pri->telefono<<std::endl;
  cout<<pri->correo<<std::endl;
  cout << pri->mundo->nombreMundo<<std::endl;
  std::cout << "Princesa 2" <<std::endl;
  p->mundo->nombreMundo="Winterfell";
  cout<<p->nombre<<std::endl;
  cout<<p->telefono<<std::endl;
  cout<<p->correo<<std::endl;
  cout << p->mundo->nombreMundo<<std::endl;
  return 0;
}
