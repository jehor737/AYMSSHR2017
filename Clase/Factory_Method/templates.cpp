#include <iostream>
using namespace std;

class FactoryProduct{
public:
  template <class Prod>
  Prod* factoryMethod()
  {
    return new Prod;
  }
};

class ProductA : public FactoryProduct
{
public:
  void operation()
  {
    std::cout << "Estoy en producto A" << '\n';
  }
};

int main(int argc, char const *argv[]) {
  FactoryProduct * p = new FactoryProduct;
  ProductA * a = p -> factoryMethod<ProductA>();
  a->operation();
  return 0;
}
