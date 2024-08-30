#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <iostream>
#include <string>
#include <cctype>

class Translator
{
private:
std::string vowels = "aeiuyo";

public:
    Translator();
    ~Translator();
    std::string Translator::translateEnglishWord (std::string s);
    std::string Translator::translateEnglishSentence (std::string s);
};

#endif