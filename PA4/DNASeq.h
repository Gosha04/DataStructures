/*
Joshua Vaysman
2449656
vaysman@chapman.edu 
CPSC 350-02
PA4
*/

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
    DNASeq complement(); // Creates a DNASeq that is the complement (G->C, A->T and vice versa) of the original DNASeq
    DNASeq subString(int s, int e); // Takes a substring from m_dna and creates a new DNASeq based on that substring
    bool isGeneticPalindrome(); // Checks inverse of sequence and complement, i.e. first char of sequence and last of complement
    char get(int pos); // The get method from DblList called here
    string getDna(); // Gets the string of the DNASeq
    int getSize();
};

#endif