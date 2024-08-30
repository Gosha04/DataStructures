#ifndef MODEL_H
#define MODEL_H

#include <string>

class Model {
    public: 
    Model();
    ~Model();
    std::string Model::translateSingleConsonant(char c);
    std::string Model::translateSingleVowel(char c);
};

#endif