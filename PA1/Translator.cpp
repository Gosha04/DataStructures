/*
Joshua Vaysman
2449656
vaysman@chapman.edu
CPSC 350-02
PA1
*/

// Implements Rober translation rules for a word and/or a sentence. I chose to have all vowels be a private member string.

#include "Translator.h"

Translator::Translator() : vowels("aeiuyo")
{
}

Translator::~Translator()
{
}

std::string Translator::translateEnglishWord (std::string s) {
    std::string result = "";

    for (int i = 0; i < s.size(); i++) {
        if (vowels.find(s[i]) == std::string::npos) { 
            result += model.translateSingleConsonant(s[i]);
        } else {
            result += model.translateSingleVowel(s[i]);
        }
    }
    return result;
}

std::string Translator::translateEnglishSentence (std::string s) {
    std::string result = "";
    int wordStart = 0;
    for (int i = 0; i <= s.size(); i++) {
        if (!isalpha(s[i])) {
            if (i > wordStart) {
                result += translateEnglishWord(s.substr(wordStart, i - wordStart));
            } 
            if (i < s.size()) {
                result += s[i];
            }
            wordStart = i + 1;
        }  
    }
    return result;
}