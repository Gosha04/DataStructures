/*
Joshua Vaysman
2449656
vaysman@chapman.edu 
CPSC 350-02
PA4
*/

#include "PalindromeFinder.h"

PalindromeFinder::PalindromeFinder(string fileName) {
    m_fileName = fileName;
    m_subLength = 0;
}

PalindromeFinder::~PalindromeFinder() {

}

bool PalindromeFinder::dnaCheck(DNASeq someDNA) {
    for (int i = 0; i < someDNA.getSize(); ++i) {
        char nucleotide = someDNA.getDna()[i];
        if (nucleotide != 'A' && nucleotide != 'T' &&
            nucleotide != 'C' && nucleotide != 'G') {
            return false;
        }
    }
    return true;
}

/*
Fairly straightforward in theory, less so in practice.
Basically I started with substring of length 4 whose start kept getting pushed up until it hits the end of the sequence
Then the substring length increases and we start at index 0 again
The general structure is that the start increases until it can't, which causes m_subLength to increase, and when that taps out
we move onto the next sequence. This is recursive.
*/
void PalindromeFinder::sequenceSubstringOps(DNASeq someDNA, int start) {
    int size = someDNA.getSize();
    int lim = 5;
    int end = start + m_subLength + lim;

    if (start >= size - lim - m_subLength) {
        ++m_subLength;
        if (m_subLength > size - 1) {
            return;
        }
        sequenceSubstringOps(someDNA, 0);  
        return;
    }

    DNASeq subSeq = someDNA.subString(start, end);

    if (subSeq.isGeneticPalindrome()) {
        cout << "   Substring [" << start << "-" << end << "]: " << subSeq.getDna();
        cout << " - Palindrome" << endl;
    }

    sequenceSubstringOps(someDNA, start + 1);
}

void PalindromeFinder::readSequence() {
    m_reader.open(m_fileName);

    string line;
    while (getline(m_reader, line)) {
        if (line == "END") {
            break;  
        }

        DNASeq dna(line);

        if (!dnaCheck(dna)) {
            cout << "Invalid sequence: " << line << endl;
            continue;
        }

        cout << "Valid Sequence: " << dna.getDna(); 
        if (dna.isGeneticPalindrome()) {
            cout << " - Palindrome" << endl;
        } else {
            cout << " - Not a Palindrome" << endl;
        }
        m_subLength = 0; 
        sequenceSubstringOps(dna, 0);  
    }
    m_reader.close(); 
}