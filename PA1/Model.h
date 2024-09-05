/*
Joshua Vaysman
2449656
vaysman@chapman.edu
CPSC 350-02
PA1
*/

#ifndef MODEL_H
#define MODEL_H

#include <string>

class Model {
    
    public: 
    Model();
    virtual ~Model();
    std::string translateSingleConsonant(char c);
    std::string translateSingleVowel(char c);
};

#endif