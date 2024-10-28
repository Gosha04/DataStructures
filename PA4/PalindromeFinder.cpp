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

void PalindromeFinder::palindromePrint(DNASeq someDNA, int start) {
    int size = someDNA.getSize();
    int lim = 5;
    int end = start + m_subLength + lim; 

    if (start >= size - lim - m_subLength) {
        ++m_subLength;
        if (m_subLength > size - 1) {
            return;
        }
        palindromePrint(someDNA, 0);  
        return;
    }

    DNASeq subSeq = someDNA.subString(start, end);

    if (subSeq.isGeneticPalindrome()) {
        cout << "   Substring [" << start << "-" << end << "]: " << subSeq.getDna();
        cout << " - Palindrome" << endl;
    }

    palindromePrint(someDNA, start + 1);
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
        palindromePrint(dna, 0);  
    }
    m_reader.close(); 
}