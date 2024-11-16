#include "UGraph.h"

int main(){
  UGraph myGraph(6);
  myGraph.addEdge(0,1);
  myGraph.addEdge(0,2);
  myGraph.addEdge(0,3);
  myGraph.addEdge(1,4);
  myGraph.addEdge(2,4);
  myGraph.addEdge(4,5);

  myGraph.printDFS(0);

  return 0;
}
