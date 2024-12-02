#include "WGraph.h"

WGraph::WGraph() : edges(true) {
    m_size = 0;
    m_adj = NULL;
}

WGraph::WGraph(unsigned int sz) : edges(true) { 
    m_size = sz;
    //allocate sz * sz adj matrix
    m_adj = new double*[sz];
    m_conn = new double*[sz];
    for(int i = 0; i < m_size; ++i){
        m_adj[i] = new double[sz];
        m_conn[i] = new double[sz];
    }
    
    //start with edges
    for(int i = 0; i < m_size; ++i){
        for(int j = 0; j < m_size; ++j){
            m_adj[i][j] = std::numeric_limits<double>::max();
            m_conn[i][j] = std::numeric_limits<double>::max();
        }
    }
}

WGraph::~WGraph(){
    //release memory
}

void WGraph::addEdge(VertexID i, VertexID j, double w){
    if (i < m_size && j < m_size){
        m_adj[i][j] = w;
        m_adj[j][i] = w;
    }
}

void WGraph::removeEdge(VertexID i, VertexID j){
    if (i < m_size && j < m_size) {
        m_adj[i][j] = std::numeric_limits<double>::max();
        m_adj[j][i] = std::numeric_limits<double>::max();
    }
}

bool WGraph::areAdjacent(VertexID i, VertexID j){
    return (m_adj[i][j] < std::numeric_limits<double>::max());
}

void WGraph::calcFW(){
    for(int i = 0; i < m_size; ++i){
        for(int j = 0; j < m_size; ++j){
            m_conn[i][j] = m_adj[i][j]; //start with conn == adj matrix
        }
    }

    for (int im = 0; im < m_size; ++im){ //transitive closure
        for (int source = 0; source < m_size; ++source){
            for (int sink = 0; sink < m_size; ++sink){
                //every possible pair of source,sink and intermediate node
                if(source==sink){
                    continue;
                }
                if (m_conn[source][im] != std::numeric_limits<double>::max() &&
                    m_conn[im][sink] != std::numeric_limits<double>::max() &&
                    m_conn[source][sink] > m_conn[source][im] + m_conn[im][sink]){
                    m_conn[source][sink] = m_conn[source][im] + m_conn[im][sink];
                }
            }
        }
    }
}

double WGraph::cheapestCost(VertexID i, VertexID j){
    return m_conn[i][j];
}

void WGraph::computeMST() {
    for (int i = 0; i < m_size ; ++i) {
        for (int j = 0; j < m_size; ++j) {
            if (m_adj[i][j] != std::numeric_limits<double>::max()) {
                //std::cout << i << j << m_adj[i][j] << std::endl;
                edges.add(Edge(j, i, m_adj[i][j]));
            }
        }
    }
    
    std::set<int> visitedVertices; 
    std::vector<Edge> mstEdges;   

    while (!edges.isEmpty() && mstEdges.size() < m_size - 1) {
        Edge currEdge = edges.remove();
        int src = currEdge.m_source;
        int snk = currEdge.m_sink;

        if (snk == src) {
            continue;
        } 

        if (visitedVertices.find(src) == visitedVertices.end() || visitedVertices.find(snk) == visitedVertices.end()) {
            //std::cout << "Check the visits\n";
            std::set<int> tempHold;
            std::cout << src << " and " << snk << std::endl;

            std::cout << "Adding: " << src << " to " << snk << std::endl;
            mstEdges.push_back(currEdge);
            visitedVertices.insert(src);
            visitedVertices.insert(snk);
        }
    }

    std::cout << "MST Edges:\n";
    while (!mstEdges.empty()) {
        std::cout << "Source: " << mstEdges.back().m_source << ", Sink: " << mstEdges.back().m_sink  
        << ", Weight: " << mstEdges.back().m_weight << "\n";

        mstEdges.pop_back();
    }
}

int main() {
    WGraph graph(5);  
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);
    graph.addEdge(3, 4, 7);

    // graph.addEdge(1, 2, 12);

    graph.computeMST();
    return 0;
}
