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
    if (m_weight != other.m_weight) {
        return m_weight < other.m_weight;
    } else { 
        return m_sink < other.m_sink;
    }
}

bool Edge::operator>(const Edge& other) const {
    if (m_weight != other.m_weight) {
        return m_weight > other.m_weight;
    } else {
        return m_sink > other.m_sink;
    }
}

Edge& Edge::operator=(const Edge& other) {
        m_source = other.m_source;
        m_sink = other.m_sink;
        m_weight = other.m_weight;
        return *this;
}
