#include "UGraph.h"

UGraph::UGraph(){
  m_size = 0;
  m_adj = NULL;
}

UGraph::UGraph(unsigned int size){
  m_size = size;
  m_adj = new VertexID*[m_size];
  for(int i = 0; i < m_size; ++i){
    m_adj[i] = new VertexID[m_size];
    for(int j = 0; j < m_size; ++j){
      m_adj[i][j] = 0U;
    }
  }
}

UGraph::~UGraph(){
  //delete the memory
}

bool UGraph::areAdjacent(VertexID i, VertexID j){
  bool ret = false;
  if(i < m_size && j < m_size){
    ret =  (m_adj[i][j] > 0);
  }
  return ret;
}
void UGraph::addEdge(VertexID i, VertexID j){
  if(i < m_size && j < m_size){
    m_adj[i][j] = 1U;
    m_adj[j][i] = 1U;
  }
}
void UGraph::removeEdge(VertexID i, VertexID j){
  if(i < m_size && j < m_size){
    m_adj[i][j] = 0U;
    m_adj[j][i] = 0U;
  }
}
unsigned int UGraph::getSize(){
  return m_size;
}

void UGraph::printDFS(VertexID i){
  stack<VertexID> fringe;
  set<VertexID> visited;
  fringe.push(i);
  while(fringe.size()> 0 && visited.size() < m_size){
    VertexID current = fringe.top();
    cout << current << endl;
    fringe.pop();
    visited.insert(current);
    for(unsigned int k = 0; k < m_size; ++k){
      if(m_adj[current][k] > 0 && visited.count(k)==0){
        fringe.push(k);
      }
    }
  }
}

void UGraph::printBFS(VertexID i){
  deque<VertexID> fringe;
  set<VertexID> visited;
  fringe.push_back(i);
  while(fringe.size()> 0 && visited.size() < m_size){
    VertexID current = fringe.front();
    cout << current << endl;
    fringe.pop_front();
    visited.insert(current);
    for(unsigned int k = 0; k < m_size; ++k){
      if(m_adj[current][k] > 0 && visited.count(k)==0 && !contains(&fringe,k)){
        fringe.push_back(k);
      }
    }
  }
}

bool UGraph::contains(deque<VertexID>* queue, VertexID vi){
    for(int i = 0; i < queue->size(); ++i){
      if(queue->at(i)==vi){
        return true;
      }
    }
    return false;
}
