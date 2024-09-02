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


