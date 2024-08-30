#include <iostream>
#include <string>
#include <cctype>
#include "Model.h"
#include "Translator.h"

Translator::Translator()
{
}

Translator::~Translator()
{
}

Model model;

std::string Translator::translateEnglishWord (std::string s) {
    std::string result = "";
    for (char c : s) {
        if(vowels.find(c) == std::string::npos) {
            result += model.translateSingleConsonant(c);
        } else {
            result += model.translateSingleVowel(c);
        }
    }
    return result;
}

std::string Translator::translateEnglishSentence (std::string s) {
    std::string result = "";
    int x = 0;
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i]) != 0) {
            result += translateEnglishWord(s.substr(x, i-x-1));
            result += s[i];
        }
    }
    return result;
}