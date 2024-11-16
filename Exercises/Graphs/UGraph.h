#ifndef UGRAPH_H
#define UGRAPH_H

#include <cstdlib>
#include <iostream>
#include <stack>
#include <deque>
#include <set>
using namespace std;

typedef unsigned int VertexID;

class UGraph{
public:
  UGraph();
  UGraph(unsigned int size);
  virtual ~UGraph();
  bool areAdjacent(VertexID i, VertexID j);
  void addEdge(VertexID i, VertexID j);
  void removeEdge(VertexID i, VertexID j);
  unsigned int getSize();
  void printDFS(VertexID i);
  void printBFS(VertexID i);

private:
  VertexID** m_adj;
  unsigned int m_size;
  bool contains(deque<VertexID>* queue, VertexID vi);

};

#endif
