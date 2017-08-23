#include <iostream>
using namespace std;
class Singleton{
  public:
    static Singleton* getInstance()
    {
      if(!instance)
        instance =  new Singleton;
      return instance;
    }
    void operation()
    {
      std::cout << "Direccion de Singleton " <<instance << '\n';
    }

  protected:
    static Singleton* instance;

  private:
    Singleton(){}
};

Singleton* Singleton::instance = 0;
int main(int argc, char const *argv[]) {
  Singleton* s = Singleton::getInstance();
  s->operation();
  Singleton* instance= Singleton::getInstance();
  instance->operation();

  Singleton* instance2= Singleton::getInstance();
  instance2->operation();

  Singleton* instance3= Singleton::getInstance();
  instance3->operation();
  return 0;
}
