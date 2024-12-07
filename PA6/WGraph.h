/*
Joshua Vaysman
2449656
vaysman@chapman.edu 
CPSC 350-02
PA6
*/

#ifndef WGraph_H
#define WGraph_H

/*
This class creates a Graph object with an adjacency and connectivity matrix. 
For the purposes of PA6 there is also an implementation of Kruskal's algorithm to find an MST for a Graph object
*/

#include <cstdlib>
#include <deque>
#include <set>
#include <stack>
#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
#include <fstream>
#include <iterator>
#include <sstream>
#include "Edge.h"
#include "PQueue.h"

//an unweighted, undirected WGraph implemented with adjacency matrix
//fixed size

typedef unsigned int VertexID;

class WGraph{
public:

    /*
    a. Default Constructor
    b. No returns, creates a Graph object
    c. No params
    d. No exceptions thrown 
    */
    WGraph();

    /* 
    a. Overloaded Constructor (File Input)
    b. No returns, creates a Graph object
    c. Parameters consist of a file as a string for the purposes of input
    d. No exceptions thrown 
    */
    WGraph(std::string file);

    /*
    a. Overloaded Constructor (Size of Graph)
    b. No returns, creates a Graph object
    c. Parameters consist of an integer for the size of the graph
    d. No exceptions thrown 
    */
    WGraph(unsigned int sz);

    /*
    a. Default Destructor
    b. No returns
    c. No params
    d. No exceptions thrown 
    */
    ~WGraph();

    /*
    a. addEdge
    b. No returns, adds an Edge to a Graph
    c. Params consist of 2 VertexID's (integers) for the purpose of placing the Edge into m_adj, and a double for the weight
    d. No exceptions thrown 
    */
    void addEdge(VertexID i, VertexID j, double w);

    /*
    a. removeEdge
    b. No returns, removes an Edge from a Graph
    c. Params consist of 2 VertexID's (integers) for the purpose of finding which Edge to remove from m_adj
    d. No exceptions thrown 
    */
    void removeEdge(VertexID i, VertexID j);

    /*
    a. areAdjacent
    b. Returns a bool, true if there is an Edge has adjacency for another and false if not
    c. Params consist of 2 VertexID's (integers), the source(i) and sink(j)
    d. No exceptions thrown 
    */
    bool areAdjacent(VertexID i, VertexID j);

    /*
    a. cheapestCost
    b. Returns a double, the weight of the cheapest connection between a source and a sink
    c. Params consist of 2 VertexID's (integers), the source(i) and sink(j)
    d. No exceptions thrown 
    */
    double cheapestCost(VertexID i, VertexID j);

    /*
    a. computeMST
    b. Returns nothing. Computes an MST for a Graph using Kruskal's Algo. Inline comments explain some design choices
    c. No Params
    d. No exceptions thrown 
    */
    void computeMST();

    /*
    a. createGraph
    b. Returns nothing, is really just a helper class that creates a graph and adds edges into a PQ for computeMST
    c. Params consist of an input file as a string
    d. No exceptions thrown 
    */
    void createGraph(std::string file);

    /*
    a. printMatrix
    b. Returns nothing. Prints a matrix to terminal
    c. Param is a matrix of doubles, the weights of our edges
    d. No exceptions thrown 
    */
    void printMatrix(double** matrix);

private:
    
    // A min priority queue of Edges that sorts them by weight. Additional sorting is done within computeMST for ties and the like
    PQueue<Edge> m_edges;

    // Adjacency matrix
    double** m_adj;

    // Connectivity matrix
    double** m_conn;

    // Size of the graph
    unsigned int m_size; //nodes in WGraph (fixed)
};






#endif
