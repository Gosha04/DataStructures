/*
Joshua Vaysman
2449656
vaysman@chapman.edu
CPSC 350-02
PA1
*/

// Purpose: Implements Robber translation rules for a single letter, be it a vowel or consonant

#include "Model.h"

Model::Model()
{
}

Model::~Model()
{
}

std::string Model::translateSingleConsonant (char c) {
    std::string s; 
    return s = c + std::string("o") + c;
}

std::string Model::translateSingleVowel (char c) {
    std::string s; 
    return s = c;

}


