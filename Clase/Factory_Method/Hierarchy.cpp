#include <iostream>

class Product{
public:
  void operation()
  {
    std::cout << "Estoy operando 1" << '\n';
  }

  void operation2()
  {
    std::cout << "Estoy operando 2" << '\n';
  }
};
class Creator{
private:
    virtual Product * createProduct(int type) = 0;

public:
    Product* factoryMethod(int type)
    {
      Product * p = createProduct(type);
      p->operation();
      return p;
    }
};

class CreatorA : public Creator
{
public:
  Product * createProduct(int type)
  {
    if(type == 1)
      return new Product;
  }
};

int main(int argc, char const *argv[]) {
  //Creator debe ser Singleton
  //Creator concretos con constructor privado
  Creator * c = new CreatorA;
  Product * p = c->factoryMethod(1);
  p-> operation2();
  delete c;
  delete p;
  return 0;
}
