#ifndef L_QUEUE_H
#define L_QUEUE_H

#include "DblList.h"
#include <cstdlib>
using namespace std;

template <typename T>
class LQueue{
public:
  LQueue();
  virtual ~LQueue();
  void add(T data); //add to back
  T remove(); //remove from front
  T peek(); //look at front
  int size();
  bool isEmpty();

private:
  DblList<T>* m_list;

};

template <typename T>
LQueue<T>::LQueue() { //O(1)
  m_list = new DblList<T>();
}

template <typename T>
LQueue<T>::~LQueue(){ //O(1)
  delete m_list;
}

template <typename T>
void LQueue<T>::add(T data){ //O(n)
  m_list->addBack(data);
}

template <typename T>
T LQueue<T>::remove(){ //O(1)
  return m_list->removeFront();
}

template <typename T>
T LQueue<T>::peek(){ //O(1)
  return m_list->get(0);
}

template <typename T>
int LQueue<T>::size(){ //O(1)
  return m_list->getSize();
}

template <typename T>
bool LQueue<T>::isEmpty(){ //O(1)
  return m_list->isEmpty();
}

#endif
