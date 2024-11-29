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
        edges.add(Edge(i, j, w));
    }
}

void WGraph::removeEdge(VertexID i, VertexID j){
    if (i < m_size && j < m_size) {
        m_adj[i][j] = std::numeric_limits<double>::max();
        m_adj[j][i] = std::numeric_limits<double>::max();

        //TODO Add removal from PQ
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
    std::vector<Edge> checkedEdges;
    int* vertices = new int[m_size];
    
    for (int i = 0; i < m_size; ++i) {
        vertices[i] = i + 1; // Assume that vertices start at 1
    }

    while (!edges.isEmpty()) {
        Edge currEdge = edges.remove();
        int src = currEdge.m_source;
        int snk = currEdge.m_sink;

        int vertSource = vertices[src];
        int vertSink = vertices[snk];

        if (vertSource != vertSink) {
            checkedEdges.push_back(currEdge);

            int smallerPath = std::min(vertSource, vertSink);
            int longerPath = std::max(vertSource, vertSink);

            for (int i = 0; i < m_size; ++i) {
                if (vertices[i] == longerPath) {
                    vertices[i] = smallerPath;
                }
            }
        }
    }
    delete[] vertices;
}                          