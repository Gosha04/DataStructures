#include <iostream>
#include "PalindromeFinder.h"

void runTests() {

    // Test 2: Parameterized constructor
    DNASeq seq2("AGCT");
    std::cout << "DNA Sequence: AGCT" << std::endl;

    // Test 3: Complement
    DNASeq comp2 = seq2.complement();
    std::cout << "Complement of AGCT: ";
    for (int i = 0; i < 4; ++i) {
        std::cout << comp2.get(i); // Expected: "TCGA"
    }
    std::cout << std::endl;

    // Test 4: Substring
    DNASeq sub2 = seq2.subString(1, 3); // Should return "GC"
    std::cout << "Substring (1, 3): ";
    for (int i = 0; i < 2; ++i) {
        std::cout << sub2.get(i);
    }
    std::cout << std::endl; // Expected: "GC"

    // Test 5: Palindrome Check
    DNASeq seq3("ACCTAGGT"); // This should be a palindrome
    std::cout << "Is ACCTAGGT a genetic palindrome? " 
              << (seq3.isGeneticPalindrome() ? "Yes" : "No") << std::endl; // Expected: "Yes"

    DNASeq seq4("ATCG"); // Not a palindrome
    std::cout << "Is ATCG a genetic palindrome? " 
              << (seq4.isGeneticPalindrome() ? "Yes" : "No") << std::endl; // Expected: "No"
}

int main() {
    //runTests();
    PalindromeFinder palFind("input");
    palFind.readSequence();
    return 0;
}
