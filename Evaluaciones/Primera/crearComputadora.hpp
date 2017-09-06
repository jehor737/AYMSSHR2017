#include <iostream>
using namespace std;

class Computadora{
  friend class CreadorComputadora;
protected:
  std::string modelo;
  Computadora()=default;
public:
  virtual Computadora * clonarComputador()=0;
  void eleccionDeComponentes(){std::cout << "Componentes elegidos para "<< modelo << '\n';}
  void ensambladoDeComponentes(){std::cout << "Computadora ensamblada para "<< modelo<< '\n';}
  void instalacionConfiguracioncSoftware(){ std::cout << "Software instalado para "<< modelo<< '\n';}
  void empaquetarComputador(){std::cout << "Computadora empaquetada para "<< modelo<< '\n';}
  virtual ~Computadora(){}
};


class CreadorComputadora{
public:
  static CreadorComputadora * getComputadora(){
      if(!computadora)
        computadora =  new CreadorComputadora;
      return computadora;
  }
  template <class Comp>
  static Comp * crearComputador()
  {
    return new Comp;
  }
private:
  CreadorComputadora(){}
protected:
  static CreadorComputadora * computadora;
};
CreadorComputadora* CreadorComputadora::computadora=0;


template <class SubClase>
class Clonar : public Computadora{
public:
  Computadora * clonarComputador()
  {
    std::cout << "Computador clonado" << '\n';
    return new SubClase(dynamic_cast<SubClase&>(*this));
  }
protected:
  Clonar(){}
};

class Desktop : public Clonar<Desktop>{
  friend class CreadorComputadora;
public:
  void desk()
  {
    std::cout << "Desktop creada" << '\n';
  }
private:
  Desktop(){ modelo = "Desktop";}
};

class Laptop : public Clonar<Laptop>{
friend class CreadorComputadora;
public:
  void lap()
  {
    std::cout << "Laptop creada" << '\n';
  }
private:
  Laptop(){modelo = "Laptop";}
};

class Netbook : public Clonar<Netbook>{
  friend class CreadorComputadora;
public:
  void net()
  {
    std::cout << "Netbook creada" << '\n';
  }
private:
  Netbook(){modelo = "Netbook";}
};

class Tablet : public Clonar<Tablet>{
  friend class CreadorComputadora;
public:
  void tab()
  {
    std::cout << "Tablet creada" << '\n';
  }
private:
  Tablet(){modelo = "Tablet";}
};

class ServerRack : public Clonar<ServerRack>{
  friend class CreadorComputadora;
public:
  void servR()
  {
    std::cout << "Server Rack creado" << '\n';
  }
  ServerRack(){modelo = "Server Rack";}
};

class ServerTower : public Clonar<ServerTower>{
  friend class CreadorComputadora;
public:
  void servTw()
  {
    std::cout << "Server Tower creado" << '\n';
  }
  ServerTower(){modelo = "Server Tower";}
};
