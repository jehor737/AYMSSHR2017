#include <iostream>
using namespace std;

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
    size = 10;
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
template<class T>
bool par(T x)
{
  if(x % 2 == 0)
    return true;
  return false;
}
template<class T, typename Function>
void find_if(Iterator<T> it, Function f)
{
  while (it.hasNext()){
    T x = it.next();
    if(f(x))
      std::cout << x << " es par" <<'\n';
  }
}

int main(int argc, char const *argv[]) {
  Collection<int> i;
  i.addElement(6);
  i.addElement(5);
  i.addElement(7);
  i.addElement(8);
  i.addElement(10);
  Iterator<int>* it = i.getIterator();
  while (it->hasNext())
    std::cout << it->next() << '\n';
  Iterator<int>* iterador = i.getIterator();
  find_if<int, bool(*)(int)>(*iterador, par<int>);
  delete it;
  delete iterador;
  return 0;
}
