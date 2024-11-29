#ifndef EDGE_H
#define EDGE_H

class Edge {
public:
    Edge(int src, int snk, double weight); 
    Edge();                               
    ~Edge();                              

    int m_source;  
    int m_sink;    
    double m_weight; 

    bool operator<(const Edge& other) const;
    bool operator>(const Edge& other) const;
};

#endif 
