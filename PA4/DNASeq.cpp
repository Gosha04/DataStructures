/*
Joshua Vaysman
2449656
vaysman@chapman.edu 
CPSC 350-02
PA4
*/

#include "DNASeq.h"

DNASeq::DNASeq() {
    m_dna = "ATCG";
    m_listSize = m_dna.size(); 
    m_list = new DblList<char>();
    for (int i = 0; i < m_listSize; ++i) {
        m_list->addBack(m_dna[i]);
    }
}

DNASeq::DNASeq(string dnaInput) {
    m_dna = dnaInput;
    m_listSize = m_dna.size();
    m_list = new DblList<char>();
    
    for (int i = 0; i < m_listSize; ++i) {
        m_list->addBack(m_dna[i]);
    }
}

DNASeq::~DNASeq() {
    
}

DNASeq DNASeq::complement() {
    DNASeq compSeq; 
    compSeq.m_list = new DblList<char>(); 
    compSeq.m_listSize = m_listSize;

    for (int i = 0; i < m_listSize; ++i) {
        char nucleotide = m_list->get(i);
        char comp;

        switch (nucleotide) {
            case 'A': 
                comp = 'T';
                break;
            case 'T':
                comp = 'A'; 
                break;
            case 'C': 
                comp = 'G'; 
                break;
            case 'G': 
                comp = 'C'; 
                break;
        }

        compSeq.m_list->addBack(comp);
    }

    return compSeq;
}

DNASeq DNASeq::subString(int s, int e) {
    std::string subStr = m_dna.substr(s, e - s); 
    DNASeq result(subStr); 
    return result; 
}

bool DNASeq::isGeneticPalindrome() {

    DNASeq comp = complement();  
    int i = 0;

    while (i < m_listSize) {
        if (m_list->get(i) != comp.m_list->get(m_listSize - 1 - i)) {
            return false; 
        }
        ++i; 
    }

    return true; 
}

char DNASeq::get(int pos) {
    return m_list->get(pos);
}

string DNASeq::getDna() {
    return m_dna;
}

int DNASeq::getSize() {
    return m_listSize;
}