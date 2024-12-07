/*
Joshua Vaysman
2449656
vaysman@chapman.edu 
CPSC 350-02
PA6
*/

#ifndef EDGE_H
#define EDGE_H

/*
Purpose: This is a simple object to represent the edges in a graph
*/

class Edge {
public:
    /*
    a. Overloaded Constructor
    b. No returns, creates an Edge object
    c. Parameters consist of an integer for source and sink are used. The weight is a double
    d. No exceptions thrown 
    */
    Edge(int src, int snk, double weight); 
    /*
    a. Default  Constructor
    b. No returns, creates an Edge object with no source, sink, or weight
    c. No Parameters
    d. No exceptions thrown 
    */
    Edge();  
    /*
    a. Destructor
    b. No returns, deletes an Edge object
    c. No parameters
    d. No exceptions thrown 
    */                             
    ~Edge();                              

    // Source of the Edge as an int
    int m_source;  
    // Sink of the Edge as an int
    int m_sink;  
    // Weight of the Edge as a double  
    double m_weight; 

    /*
    a. < Operator
    b. The return shows the result of the comparison of 2 Edge Objects. They are compared via their weights for the PQ.
    c. The parameter is a constant reference of another Edge
    d. No exceptions thrown 
    */
    bool operator<(const Edge& other) const;

    /*
    a. > Operator
    b. The return shows the result of the comparison of 2 Edge Objects. They are compared via their weights for the PQ.
    c. The parameter is a constant reference of another Edge
    d. No exceptions thrown 
    */
    bool operator>(const Edge& other) const;

    /*
    a. = Operator
    b. Returns a reference to the current Edge object being changed. Essentially implements the '=' operator for Edge objects
    c. The parameter is a constant reference of another Edge
    d. No exceptions thrown 
    */
    Edge& operator=(const Edge& other);
};

#endif 
