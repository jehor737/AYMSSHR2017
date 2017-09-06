#include <iostream>
#include "crearComputadora.hpp"
using namespace std;
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
  Desktop* l = c->crearComputador<Desktop>();
  l->hola();
  Computadora * la = l->clonarComputador();
  mensajesComputadora(la);
  delete l;
}

void crearLaptop(CreadorComputadora * c)
{
  Laptop * l = c->crearComputador<Laptop>();
  l->hola();
  Computadora * la = l->clonarComputador();
  mensajesComputadora(la);
  delete l;
}

void crearNetbook(CreadorComputadora * c)
{
  Netbook * l = c->crearComputador<Netbook>();
  l->hola();
  Computadora * la = l->clonarComputador();
  mensajesComputadora(la);
  delete l;
}

void crearTablet(CreadorComputadora * c)
{
  Tablet * l = c->crearComputador<Tablet>();
  l->hola();
  Computadora * la = l->clonarComputador();
  mensajesComputadora(la);
  delete l;
}

void crearServerRack(CreadorComputadora * c)
{
  ServerRack * l = c->crearComputador<ServerRack>();
  l->hola();
  Computadora * la = l->clonarComputador();
  mensajesComputadora(la);
  delete l;
}

void crearServerTower(CreadorComputadora * c)
{
  ServerTower * l = c->crearComputador<ServerTower>();
  l->hola();
  Computadora * la = l->clonarComputador();
  mensajesComputadora(la);
  delete l;
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

int main(int argc, char const *argv[]) {
  std::string tipoCompu = "p";
  CreadorComputadora * c = CreadorComputadora::getComputadora();
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
