#include <iostream>
#include "crearComputadora.hpp"
using namespace std;
void mensajesComputadora(Computadora * la);
void opcionElegida(string tipoCompu, CreadorComputadora * c);

int main(int argc, char const *argv[]) {
  std::string tipoCompu = "p";
  //Singleton
  CreadorComputadora * c = CreadorComputadora::getComputadora();
  //Factory Method
  Desktop* l = c->crearComputador<Desktop>();
  l->desk();
  //CRTP y Prototype
  Desktop * l2 = dynamic_cast<Desktop*>(l->clonarComputador());
  l2->desk();
  //Prototype
  Computadora * la = l->clonarComputador();
  mensajesComputadora(la);
  delete l;
  delete l2;
  /*
  No se pueden realizar lo siguientes comandos:
  CreadorComputadora *cr = new CreadorComputadora;
  Clonar<Laptop> * clon = new Clonar<Laptop>;
  Computadora * no = new Computadora;
  Desktop * d = new Desktop;
  Laptop * l = new Laptop;
  Netbook * ne = new Netbook;
  Table * t = new Tablet;
  ServerRack * sr = new ServerRack;
  ServerTower * st = new ServerTower;
  */
  while (tipoCompu != "q")
  {
    std::cout << "Ingrese el tipo de computadora a crear:" << '\n';
    std::cout << "a. Desktop" << '\n';
    std::cout << "b. Laptop" << '\n';
    std::cout << "c. Netbook" << '\n';
    std::cout << "d. Tablet" << '\n';
    std::cout << "e. Server Rack" << '\n';
    std::cout << "f. Server Tower" << '\n';
    std::cout << "q. Salir" << '\n';
    std::cin>> tipoCompu;
    opcionElegida(tipoCompu, c);
  }
  delete c;
  return 0;
}

void mensajesComputadora(Computadora * la)
{
  la->eleccionDeComponentes();
  la->ensambladoDeComponentes();
  la->instalacionConfiguracioncSoftware();
  la->empaquetarComputador();
  delete la;
}

void crearDesktop(CreadorComputadora * c)
{
  //usar
  Desktop* l = c->crearComputador<Desktop>();
  l->desk();
  Desktop * l2 = dynamic_cast<Desktop*>(l->clonarComputador());
  l2->desk();
  Computadora * la = l->clonarComputador();
  mensajesComputadora(la);
  delete l;
  delete l2;
}

void crearLaptop(CreadorComputadora * c)
{
  Laptop * l = c->crearComputador<Laptop>();
  l->lap();
  Laptop * l2 = dynamic_cast<Laptop*>(l->clonarComputador());
  l2->lap();
  Computadora * la = l->clonarComputador();
  mensajesComputadora(la);
  delete l;
  delete l2;
}

void crearNetbook(CreadorComputadora * c)
{
  Netbook * l = c->crearComputador<Netbook>();
  l->net();
  Netbook * l2 = dynamic_cast<Netbook*>(l->clonarComputador());
  l2->net();
  Computadora * la = l->clonarComputador();
  mensajesComputadora(la);
  delete l;
  delete l2;
}

void crearTablet(CreadorComputadora * c)
{
  Tablet * l = c->crearComputador<Tablet>();
  l->tab();
  Tablet * l2 = dynamic_cast<Tablet*>(l->clonarComputador());
  l2->tab();
  Computadora * la = l->clonarComputador();
  mensajesComputadora(la);
  delete l;
  delete l2;
}

void crearServerRack(CreadorComputadora * c)
{
  ServerRack * l = c->crearComputador<ServerRack>();
  l->servR();
  ServerRack * l2 = dynamic_cast<ServerRack*>(l->clonarComputador());
  l2->servR();
  Computadora * la = l->clonarComputador();
  mensajesComputadora(la);
  delete l;
  delete l2;
}

void crearServerTower(CreadorComputadora * c)
{
  ServerTower * l = c->crearComputador<ServerTower>();
  l->servTw();
  ServerTower * l2 = dynamic_cast<ServerTower*>(l->clonarComputador());
  l2->servTw();
  Computadora * la = l->clonarComputador();
  mensajesComputadora(la);
  delete l;
  delete l2;
}
void opcionElegida(string tipoCompu, CreadorComputadora * c)
{
  if(tipoCompu == "a")
    crearDesktop(c);
  else if(tipoCompu == "b")
    crearLaptop(c);
  else if(tipoCompu == "c")
    crearNetbook(c);
  else if(tipoCompu == "d")
    crearTablet(c);
  else if(tipoCompu == "e")
    crearServerRack(c);
  else if(tipoCompu == "f")
    crearServerTower(c);
  else if(tipoCompu == "q")
    return;
  else
  {
    std::cout << "Opción no válida" << '\n';
    return;
  }
}
