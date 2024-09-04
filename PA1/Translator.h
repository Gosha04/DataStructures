#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <string>
#include <cctype>
#include "Model.h"

class Translator
{
private:
std::string m_vowels;
Model model;

public:
    Translator();
    virtual ~Translator();
    std::string translateEnglishWord (std::string s);
    std::string translateEnglishSentence (std::string s);
};

#endif