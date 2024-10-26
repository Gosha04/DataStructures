#include "PalindromeFinder.h"

PalindromeFinder::PalindromeFinder(string fileName) {
    m_fileName = fileName;
    m_subLength = 0;
}

PalindromeFinder::~PalindromeFinder() {

}

bool PalindromeFinder::dnaCheck(DNASeq someDNA) {
    for (int i = 0; i < someDNA.getSize(); ++i) {
        char nucleotide = someDNA.toString()[i];
        if (nucleotide != 'A' && nucleotide != 'T' &&
            nucleotide != 'C' && nucleotide != 'G') {
            return false;
        }
    }
    return true;
}

void PalindromeFinder::palindromePrint(DNASeq someDNA, int start) {
    cout << "Pal Check ";
    int size = someDNA.getSize();
    int end = start + m_subLength + 4; 

    if (m_subLength >= size) {
        cout << "All substrings have been checked." << endl;
        return;
    }

    if (start > size - 4 - m_subLength) {
        ++m_subLength;
        palindromePrint(someDNA, 0);  
        return;
    }

    DNASeq subSeq = someDNA.subString(start, end);

    cout << "Substring [" << start << "-" << end << "]: " << subSeq.toString();

    if (subSeq.isGeneticPalindrome()) {
        cout << " - Palindrome" << endl;
    } else {
        cout << " - Not a palindrome" << endl;
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

        cout << "Valid Sequence: " << dna.toString() << endl;
        palindromePrint(dna, 0);  
    }
    m_reader.close(); 
}