#include <iostream>
#include <string>
using namespace std;

class Motor{

  int potencia;
  int numSerie;
  public:
    Motor()=default;
    Motor(int pot, int nS) : potencia(pot), numSerie(nS){}
    int getPotencia(){ return potencia; }
    int getNumSerie(){ return numSerie; }
};

class Alas{
  string marca;
  int numSerie;
  int hiper;
  int spoilers;
  public:
    Alas()=default;
    Alas(string m, int nS, int h, int sp) : marca(m), numSerie(nS), hiper(h), spoilers(sp){}
    string getMarca(){ return marca; }
    int getNumSerie(){ return numSerie; }
    int getHiper(){ return hiper; }
    int getSpoiler(){ return spoilers; }
};

class Avion{
  Motor * motor;
  Alas * alas;
  string marca;
  string modelo;
  int numSerie;
  public:
  void setAlas(Alas * a){ alas = a;}
  void setMotor(Motor * m){ motor = m; }
  void setMarca(string m){ marca = m; }
  void setModelo(string m){ modelo = m;}
  void setNumSerie(int n){numSerie=  n; }

    string getMarca(){ return marca; }
    string getModelo(){ return modelo; }
    int getNumSerie(){ return numSerie; }
    Alas * getAlas(){ return alas; }
    Motor * getMotor(){ return motor; }
};


class Builder{
protected:
  Avion * avion;

  public:
    Avion * getAvion(){ return avion; }
    void createAvion()
    {
      avion = new Avion;
    }
    virtual Motor * buildMotor() = 0;
    virtual Alas * buildAlas() = 0;
    virtual string buildModelo() = 0;
    virtual string buildMarca() = 0;
    virtual int buildNumSerie() = 0;
};

class BoeingBuilder : public Builder{
  public:
    Motor * buildMotor()
    {
      Motor * motor = new Motor(10000, 1111111);
      avion->setMotor(motor);
      return motor;
    }

    Alas * buildAlas()
    {
        Alas * alas = new Alas("Boeing", 10101010, 10, 10);
        avion->setAlas(alas);
        return alas;
    }
    string buildMarca(){
      avion->setMarca("boeing");
      return "boeing";
    }
    string buildModelo(){
      avion->setModelo("754");
      return "754";
     }
    int buildNumSerie(){
      avion->setNumSerie(123456789);
      return 123456789;
    }
};

class Director{
  Builder * builder;
  public:
    void setBuilder(string  tipoAvion){
      if(tipoAvion == "Boeing")
      {
        builder = new BoeingBuilder;
      }
    }
    Avion * getAvion()
    {
      return builder->getAvion();
    }
    void construct()
    {
      builder->createAvion();
      builder->buildAlas();
      builder->buildMotor();
      builder->buildModelo();
      builder->buildMarca();
      builder->buildNumSerie();
    }
};

int main(int argc, char const *argv[]) {
  Director d;
  d.setBuilder("Boeing");
  d.construct();
  Avion * a = d.getAvion();
  std::cout << a->getMarca() <<'\n';
  return 0;
}
