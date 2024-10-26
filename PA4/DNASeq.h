#ifndef DNA_SEQ_H
#define DNA_SEQ_H
#include "DblList.h"

class DNASeq
{
private:
    DblList<char>* m_list;
    string m_dna;
    int m_listSize;
public:
    DNASeq();
    virtual ~DNASeq();
    DNASeq(string dnaInput);
    DNASeq complement();
    DNASeq subString(int s, int e);
    bool isGeneticPalindrome();
    char get(int pos);
    string getDna();
    int getSize();
    string toString();
};

#endif