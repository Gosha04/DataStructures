#ifndef L_QUEUE_H
#define L_QUEUE_H

#include "DblList.h"
#include <cstdlib>
using namespace std;

template <typename T>
class LQueue{
public:
  LQueue();
  LQueue(int s);
  virtual ~LQueue();
  void add(T data); //add to back
  T remove(); //remove from front
  T peek(); //look at front
  int size();
  bool isEmpty();
  bool isFull();

private:
  int m_count;
  int m_front;
  int m_back;
  int m_max;
  T* m_arr;

};

template <typename T>
LQueue<T>::LQueue(){ //O(1)
  m_count = 0;
  m_max = 0;
  m_front = 0;
  m_back = -1;
  m_arr = NULL;
}

template <typename T>
LQueue<T>::LQueue(int s){ //O(1)
  m_count = 0;
  m_max = s;
  m_front = 0;
  m_back = -1;
  m_arr = new T[s];
}

template <typename T>
LQueue<T>::~LQueue(){ //O(1)
  delete[] m_arr;
}

template <typename T>
void LQueue<T>::add(T data){ //O(n)
  if(!isFull()){
    m_arr[++m_back] = data;
    ++m_count;
  } else{ //full
    T* temp = new T[2*m_max];
    for(int i = 0; i < m_max; ++i){
      temp[i] = m_arr[i];
    }
    delete[] m_arr;
    m_arr = temp;
    m_max *= 2;
    m_arr[++m_back] = data;
    ++m_count;
  }
}

template <typename T>
T LQueue<T>::remove(){ //O(1)
  //better check if empty - throw execption, etc
  T ret = m_arr[m_front];
  ++m_front;
  --m_count;
  return ret;
}

template <typename T>
T LQueue<T>::peek(){ //O(1)
  return m_arr[m_front];
}

template <typename T>
int LQueue<T>::size(){ //O(1)
  return m_count;
}

template <typename T>
bool LQueue<T>::isEmpty(){ //O(1)
  return (m_count == 0);
}

template <typename T>
bool LQueue<T>::isFull(){ //O(1)
  return (m_count==m_max || m_back == m_max-1);
}

#endif
