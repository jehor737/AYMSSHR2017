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

int main(int argc, char const *argv[]) {
  Collection<char> i;
  i.addElement('c');
  i.addElement('a');
  i.addElement('r');
  i.addElement('r');
  i.addElement('o');
  Iterator<char>* it = i.getIterator();
  while (it->hasNext())
    std::cout << it->next() << '\n';
  delete it;
  return 0;
}
