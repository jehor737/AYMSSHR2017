#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
class Clock {
public:
  static Clock * getHora()
  {
    if(!hora)
      hora = new Clock;
    return hora;
  }

  void horaActual()
  {
    char fecha[30];
    time_t tiempoActual = time(NULL);
    ctime(&tiempoActual);
    strcpy(fecha, ctime(&tiempoActual));
    std::cout << "Hora actual: " << fecha << '\n';
  }
protected:
  static Clock * hora;
private:
  Clock(){}
};
Clock * Clock::hora = 0;
int main(int argc, char const *argv[]) {
  Clock * reloj = Clock::getHora();
  reloj->horaActual();
  return 0;
}
