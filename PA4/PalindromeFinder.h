#ifndef PALINDROME_FINDER_H
#define PALINDROME_FINDER_H

#include <fstream>
#include "DNASeq.h"
class PalindromeFinder
{
private:
    fstream m_reader;
    string m_fileName;
    int m_subLength;
public:
    PalindromeFinder(string fileName);
    virtual ~PalindromeFinder();
    void palindromePrint(DNASeq someDNA, int start);
    bool dnaCheck(DNASeq someDna);
    void readSequence();
};

#endif