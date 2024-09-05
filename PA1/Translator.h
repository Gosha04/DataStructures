/*
Joshua Vaysman
2449656
vaysman@chapman.edu
CPSC 350-02
PA1
*/

#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <string>
#include <cctype>
#include "Model.h"

class Translator
{
private:
std::string m_vowels; // String of all english vowels including 'y'
Model model; // Model object to translate letters

public:
    Translator(); 
    virtual ~Translator();
    std::string translateEnglishWord (std::string s);
    std::string translateEnglishSentence (std::string s);
};

#endif