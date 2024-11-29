#include "Edge.h"

Edge::Edge(int src, int snk, double weight) {
    m_source = src;
    m_sink = snk;
    m_weight = weight;
}

Edge::Edge() {
    m_source = -1;
    m_sink = -1;
    m_weight = 0.0;
}

Edge::~Edge() {
    
}

bool Edge::operator<(const Edge& other) const {
    return m_weight < other.m_weight;
}

bool Edge::operator>(const Edge& other) const {
    return m_weight > other.m_weight;
}
