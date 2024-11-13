/*
Joshua Vaysman
2449656
vaysman@chapman.edu 
CPSC 350-02
PA4
*/

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
    void sequenceSubstringOps(DNASeq someDNA, int start); //Checks and prints Sequences and their palindromic(?) substrings
    // more info in PalindromeFinder.cpp
    bool dnaCheck(DNASeq someDna); // Checks the validity of a DNA Sequence
    void readSequence(); // Reads sequences from an input file and checks them for validity. Then calls the substring operator
    // to check the sequences substrings
};

#endif