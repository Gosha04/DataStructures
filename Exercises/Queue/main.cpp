#include "CQueue.h"
#include <iostream>
using namespace std;

int main(){
  CQueue<char> cq(4);
  cq.add('e');
  cq.add('r');
  cq.add('i');
  cq.add('k');
  cout << cq.isFull() << endl;
  while(!cq.isEmpty()){
    cout << cq.remove() << endl;
  }

  cq.add('e');
  cq.add('r');
  cq.add('i');
  cq.add('k');
  //cout << "here "<<  cq.m_front << " " << cq.m_back << endl;

  cq.remove();
  cq.add('l');
  //cq.add('i');
  cout << cq.isFull() << endl;
  //cout << cq.m_front << " " << cq.m_back << endl;
  while(!cq.isEmpty()){
    cout << cq.remove() << " ";
  }

  return 0;
}
