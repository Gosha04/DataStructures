#include "WGraph.h"
// NOTES: m_conn is mstAdjMatrix
WGraph::WGraph() : m_edges(true) { // m_edges(true) exist so that the PQ is treated as a min pq
    m_size = 0; 
    m_adj = NULL;
}

WGraph::WGraph(std::string file) : m_edges(true) {
    createGraph(file); 
}

WGraph::WGraph(unsigned int sz) : m_edges(true) { 
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

double WGraph::cheapestCost(VertexID i, VertexID j){
    return m_conn[i][j];
}


void WGraph::computeMST() {

    // for loop that adds Edges from the graph to m_edges
    for (int i = 0; i < m_size ; ++i) {
        for (int j = 0; j < m_size; ++j) {
            if (i < j && m_adj[i][j] != std::numeric_limits<double>::max()) {
                m_edges.add(Edge(j, i, m_adj[i][j]));
            }
        }
    }
    
    std::set<int> visitedSnk; // used to track sinks that have been hit
    std::set<int> visitedSrc; // used to track sources that have been hit
    // originally both of the above were one set but it was overly finicky

    
    std::vector<Edge> mstEdges; // vector used to hold the final edges of our MST
    std::vector<Edge> holdCell; // temporary storage for ties and Edges that are in visitedSnk but not visitedSource
    double mstCost = 0.0;

    // we start things off by saying we've visited the source of our first edge
    // since we want to avoid cycles we would never have it enter visitedSnk otherwise
    visitedSnk.insert(m_edges.peek().m_source); 

    while (!m_edges.isEmpty() || !holdCell.empty()) { // while we have edges to process

        Edge currEdge;
        bool foundHeldEdge = false; // a bool that tracks if an edge in holdCell can now leave

        for (int i = 0; i < holdCell.size(); ++i) { // loop to check over all Edges in holdCell
            // if an edge in holdCell has a source that has been the sink of another Edge we act
            // or if the sink is in sinks, since this tells us that something else is reaching 
            // we have to remember that all sources and sinks can be inverted in our adjacency matrix
            if (visitedSnk.find(holdCell[i].m_source) != visitedSnk.end() ||
                visitedSnk.find(holdCell[i].m_sink) != visitedSnk.end()) {

                currEdge = holdCell[i];
                holdCell.erase(holdCell.begin() + i);
                foundHeldEdge = true;
                break;
            }
        }

        if (!foundHeldEdge) { // if theres no edge in the holding cell continue with the base m_edges pq
            if (m_edges.isEmpty()) { 
                break;
            } 
            currEdge = m_edges.remove();
        }

        // simplifications
        int src = currEdge.m_source;
        int snk = currEdge.m_sink;
        double weight = currEdge.m_weight;
 
        // more simplifications
        bool srcVisited = visitedSnk.find(src) != visitedSnk.end(); // is the source connected to something else
        bool snkVisited = visitedSnk.find(snk) != visitedSnk.end();

        // if an edge has had both its source and sink hit that means its a cycle and we ought to skip it
        if (srcVisited && snkVisited) { 
            continue;
        }

        // if the source or sink is visited add it to mstEdges and increase mstCost
        // its or since if we just visited sources we'd really only use one or two 
        // and if we only saw sinks then we wouldn't get past the first edge
        if (srcVisited || snkVisited) {
            mstEdges.push_back(currEdge);
            mstCost += weight;

            visitedSnk.insert(src); // make sure to track source
            visitedSnk.insert(snk); // same for sink
        } else { // if the Edge has both unvisited sources and sinks check over the holding cell for applicable edges
            holdCell.push_back(currEdge); 
        }
    }

    // now that we're done sorting the Edges, we populate m_conn
    for (int i = 0; i < m_size; ++i) { 
        m_conn[i] = new double[m_size];
        for (int j = 0; j < m_size; ++j) {
            m_conn[i][j] = 0; 
        }
    }
    
    for (int i = 0; i < mstEdges.size(); ++i) {
        m_conn[mstEdges[i].m_source][mstEdges[i].m_sink] = mstEdges[i].m_weight;
        m_conn[mstEdges[i].m_sink][mstEdges[i].m_source] = mstEdges[i].m_weight; 
    }

    // cleanup
    mstEdges.clear();  

    // prints the total cost of the MST and m_conn to the terminal
    std::cout << "Total MST Cost: " << std::fixed << std::setprecision(3) << mstCost << std::endl;
    printMatrix(m_conn);
}

void WGraph::createGraph(std::string file) {
    std::ifstream reader(file);
    std::string line;

    std::getline(reader, line); 
    int graphSize = std::stoi(line);

    m_size = graphSize;

    // the below code is pulled straight from the overloaded size constructor
    // makes the graph
    m_adj = new double*[graphSize];
    m_conn = new double*[graphSize];
    for(int i = 0; i < m_size; ++i){
        m_adj[i] = new double[graphSize];
        m_conn[i] = new double[graphSize];
    }
    
    for(int i = 0; i < m_size; ++i){
        for(int j = 0; j < m_size; ++j){
            m_adj[i][j] = std::numeric_limits<double>::max();
            m_conn[i][j] = std::numeric_limits<double>::max();
        }
    }


    // heres where the fun begins
    int row = 0; // source of edge
    while (std::getline(reader, line) && line != "END") {
        std::istringstream lineStream(line);
        std::istream_iterator<double> it(lineStream), end;

        double weight = 0.0;
        int col = 0; // sink of edge
        while (it != end) {
            weight = *it++; 
            if (weight > 0) { // if the weight exists add it to the graph
                addEdge(row, col, weight);
            }
            ++col; 
        }
        ++row; 
    }
}

void WGraph::printMatrix(double** matrix) {

    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            std::cout << std::fixed << std::setprecision(3) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
