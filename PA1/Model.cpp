#include <string>
#include "Model.h"

Model::Model()
{
}

Model::~Model()
{
}

std::string Model::translateSingleConsonant (char c) {
    std::string s; 
    s = c + std::string("o") + c;
    return s;
}

std::string Model::translateSingleVowel (char c) {
    std::string s; 
    s = c;
    return s;
}


