#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <string>
#include <cctype>
#include "Model.h"

class Translator
{
private:
std::string vowels;
Model model;

public:
    Translator();
    ~Translator();
    std::string translateEnglishWord (std::string s);
    std::string translateEnglishSentence (std::string s);
};

#endif