/*
Joshua Vaysman
2449656
vaysman@chapman.edu
CPSC 350-02
PA1
*/

// Purpose: Implements Robber translation rules for a single letter, be it a vowel or consonant

#include "Model.h"

/*
Default Constructor
*/
Model::Model()
{
}

/*
Default Destructor
*/
Model::~Model()
{
}

/*
a. translateSingleConsonant
b. Returns a string 's' in the format "(c)o(c)", where (c) is the input character from param 'c'.
c. Params: A single char 'c'
*/
std::string Model::translateSingleConsonant (char c) {
    std::string s; 
    return s = c + std::string("o") + static_cast<char>(std::tolower(c)); // 3rd char should always be lower case
}

/*
a. translateSingleVowel
b. Returns a string 's' which = 'c'
c. Params: A single char 'c'
*/
std::string Model::translateSingleVowel (char c) {
    std::string s; 
    return s = c;
}


