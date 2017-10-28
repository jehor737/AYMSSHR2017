/*
Jesús Horacio Rojas Cortés A01020026
Compile with g++ JuegoNaves.cpp -o eval2 -std=c++11
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#define SIZE 10
using namespace std;
class Juego;

template <class T>
class Iterator;

template <class T>
class Collection{
protected:
  int size;
  int cont;
  T * array;
public:
  friend class Iterator<T>;
  Collection()
  {
    size = SIZE;
    cont = 0;
    array = new T[size];
  }
  void addElement(T value){
    if(cont<=size)
    {
      array[cont++]= value;
      return;
    }
    cout << "Ya no hay espacio\n";
  }

  Iterator<T>* getIterator();

  T at(int pos)
  {
    return array[pos];
  }
};

template <class T>
class Iterator{
protected:
  Collection<T> coll;
  int cont = 0;
public:
  Iterator(const Collection<T>& coll) : coll(coll){}
  bool hasNext()
  {
    if(cont < coll.cont)
      return true;
    return false;
  }
  T next()
  {
    return coll.at(cont++);
  }

};
template <class T>
Iterator<T> * Collection<T>::getIterator(){
  return new Iterator<T>(*this);
}

class FarAwayGalaxy{
protected:
  static FarAwayGalaxy* instance;
  FarAwayGalaxy(){}
  int posX, posY, tipo;
  int vida = 1;
public:
  std::vector<FarAwayGalaxy*> galaxyElement;
  Collection<FarAwayGalaxy*> observer;//Para iterator en el observer
  string name;
  //Singleton de creación de objetos
  static FarAwayGalaxy* getInstance()
  {
    if(!instance)
      instance =  new FarAwayGalaxy;
    return instance;
  }
  //factory method para crear objetos de diferente tipo
  template <class Item>
  Item* factoryMethod()
  {
    return new Item;
  }
  //Métodos de posición de los objetos
  void quitVida() { vida = 0; }
  int getVida() { return vida; }
  void setPosX(int x) { posX = x; }
  void setPosY(int y) { posY = y; }
  int getPosX() { return posX; }
  int getPosY() { return posY; }
  void moveInicial()//Dar primer lugar aleatorio
  {
    posX = (rand() % SIZE);
    posY = (rand() % SIZE);
    std::cout << "Position ("<< posX<<", "<< posY<<")" << '\n';
  }
  void addObserver(FarAwayGalaxy* ob)//Agregar al vector de
  {
    galaxyElement.push_back(ob);
  }
  //notificación del observer
  void notificacion(int x, int y, Iterator<FarAwayGalaxy*> it, string name){
    while(it.hasNext()) {//uso del iterator para el observer
        std::cout << "Mensaje para: "<< it.next()->name << '\n';
        std::cout << "Colisión en ("<<x<< ","<< y<<") de "<<name<< '\n';
    }
  }
};
FarAwayGalaxy* FarAwayGalaxy::instance = 0;//definir instancia
//Clases que crean diferentes tipos de objetos del factory method
class PlanetExplorationShip : public FarAwayGalaxy{
friend class FarAwayGalaxy;
private:
  PlanetExplorationShip(){ name="Exploration"; moveInicial();}
};
class ColonizationShip : public FarAwayGalaxy{
friend class FarAwayGalaxy;
private:
  ColonizationShip(){name="Colonization"; moveInicial();}
};
class PlanetObservationShip : public FarAwayGalaxy{
friend class FarAwayGalaxy;
private:
  PlanetObservationShip(){name="Observation"; moveInicial();}
};
class StonyMeteorite : public FarAwayGalaxy{
friend class FarAwayGalaxy;
private:
  StonyMeteorite(){ name="Stony meteorite"; moveInicial(); }
};
class IronMeteorite : public FarAwayGalaxy{
friend class FarAwayGalaxy;
private:
  IronMeteorite(){ name="Iron Meteorite"; moveInicial(); }
};
class DesertPlanet : public FarAwayGalaxy{
friend class FarAwayGalaxy;
private:
  DesertPlanet(){ name="Desert Planet"; moveInicial(); }
};
class EarthAnalog : public FarAwayGalaxy{
friend class FarAwayGalaxy;
private:
  EarthAnalog(){name="Earth Analog"; moveInicial();}
};
//clase que controla el juego
class Juego{
private:
  int tablero[SIZE][SIZE]={{0}};//tablero
  int choque = -1;
  int total = 0;
  FarAwayGalaxy * galaxy;
  Iterator<FarAwayGalaxy*> *it;
  PlanetExplorationShip* shipExplorer;
  PlanetObservationShip* shipObserver;
  ColonizationShip* shipColonization;
  StonyMeteorite* stoneMeteorite;
  IronMeteorite* ironMeteorite;
  DesertPlanet* desertPlanet;
  EarthAnalog* earthAnalog;
public:

  void agregarATablero(FarAwayGalaxy* object){
    if(tablero[object->getPosX()][object->getPosY()] != 0){//dar un valor de inicio en el tablero
      object->setPosX((rand() % SIZE));
      object->setPosY((rand() % SIZE));
    }
    tablero[object->getPosX()][object->getPosY()]=object->getVida();
    std::cout << object->name << '\n';
    galaxy->observer.addElement(object);//Agregar al collection
    galaxy->addObserver(object);//Agregar al vector
  }
  void imprimeTablero(){
			std::cout << "\n";
			std::cout << "\t-----------------------------------" << "\n";
			for (int j = 0; j < SIZE; j++) {
				std::cout << "\t|";
            	for (int i = 0; i < SIZE; i++) {
            		std::cout << " " << tablero[i][j] << " ";
            	}
            	std::cout << "|" << "\n";
        	}
        	std::cout << "\t-----------------------------------" << "\n";
    	}
  void crearGameObjects()
  {
     galaxy = FarAwayGalaxy::getInstance();
     shipObserver = galaxy->factoryMethod<PlanetObservationShip>();
     shipExplorer = galaxy->factoryMethod<PlanetExplorationShip>();
     shipColonization = galaxy->factoryMethod<ColonizationShip>();
     stoneMeteorite= galaxy->factoryMethod<StonyMeteorite>();
     ironMeteorite = galaxy->factoryMethod<IronMeteorite>();
     desertPlanet = galaxy->factoryMethod<DesertPlanet>();
     earthAnalog = galaxy->factoryMethod<EarthAnalog>();
     agregarATablero(shipExplorer);
     agregarATablero(shipObserver);
     agregarATablero(shipColonization);
     agregarATablero(stoneMeteorite);
     agregarATablero(ironMeteorite);
     agregarATablero(desertPlanet);
     agregarATablero(earthAnalog);
     it = galaxy->observer.getIterator();//traer el iterator
     imprimeTablero();
  }

  void moverRandom() {
    std::vector<FarAwayGalaxy*> object = galaxy->galaxyElement;
    for (size_t i = 0; i < object.size(); i++) {
      if (object.at(i)->getVida()) {
        if (tablero[object.at(i)->getPosX()][object.at(i)->getPosY()]==-1) {//Si hay colisión entonces
          object.at(i)->quitVida();//Quitar vida
          object.at(i)->notificacion(object.at(i)->getPosX(),object.at(i)->getPosY(),*it, object.at(i)->name);//Notificar a todos con observer
          total++;
          break;
        }
        else{
          std::cout << "Posicion inicial de "<<object.at(i)->name<<"("<< object.at(i)->getPosX()<<", "<<object.at(i)->getPosY()<<")" << '\n';
          tablero[object.at(i)->getPosX()][object.at(i)->getPosY()]=0;
          int movimiento = (rand() % 4) + 1;
          switch (movimiento) {
            case 1:
            //Derecha
            if (object.at(i)->getPosX() != SIZE - 1 && tablero[object.at(i)->getPosX() + 1][object.at(i)->getPosY()]!=-1) {
              object.at(i)->setPosX(object.at(i)->getPosX()+1);
            }
            break;
            case 2:
            //Izquierda
            if (object.at(i)->getPosX() != 0 && tablero[object.at(i)->getPosX()-1][object.at(i)->getPosY()]!=-1) {
              object.at(i)->setPosX(object.at(i)->getPosX()-1);
            }
            break;
            case 3:
            //Arriba
            if (object.at(i)->getPosY() != SIZE - 1 && tablero[object.at(i)->getPosX()][object.at(i)->getPosY() + 1]!=-1) {
              object.at(i)->setPosY(object.at(i)->getPosY()+1);
            }
            break;
            case 4:
            //Abajo
            if (object.at(i)->getPosY() != 0 && tablero[object.at(i)->getPosX()][object.at(i)->getPosY()-1]!=-1) {
              object.at(i)->setPosY(object.at(i)->getPosY() - 1);
            }
            break;
          }
          if (tablero[object.at(i)->getPosX()][object.at(i)->getPosY()]==0) {
            tablero[object.at(i)->getPosX()][object.at(i)->getPosY()]=1;//Mover si no hay colisión
          }
          else{
            tablero[object.at(i)->getPosX()][object.at(i)->getPosY()]=-1;//Colocar que hubo colisión
            object.at(i)->quitVida();
            object.at(i)->notificacion(object.at(i)->getPosX(),object.at(i)->getPosY(),*it, object.at(i)->name);//Notificar a todos con observer
            total++;
          }
          std::cout << "Posicion final de "<<object.at(i)->name<<"("<< object.at(i)->getPosX()<<", "<<object.at(i)->getPosY()<<")" << '\n';
        }
      }
    }
    imprimeTablero();
  }

  void iniciarJuego(){
    while (total < galaxy->galaxyElement.size()-1)
        moverRandom();//Mover a todos los objetos hasta que ya hayan chocado todos o ya no quede nada con qué chocar
    std::cout << "Ha terminado" << '\n';
  }
};


int main(int argc, char const *argv[]) {
  srand((int)time(0));
  Juego juego;
  juego.crearGameObjects();
  juego.iniciarJuego();
  return 0;
}
