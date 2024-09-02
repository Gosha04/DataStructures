#include "Translator.h"

Translator::Translator() : vowels("aeiuyo")
{
}

Translator::~Translator()
{
}

std::string Translator::translateEnglishWord (std::string s) {
    std::string result = "";
    int size = s.size();
    for (int i = 0; i < size; i++) {
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
    int x = 0;
    int size = s.size();
    for (int i = 0; i < size; i++) {
        if (isalpha(s[i]) != 0) {
            result += translateEnglishWord(s.substr(x, i - x - 1));
            result += s[i];
        }
    }
    if (x < size) {
        result += translateEnglishWord(s.substr(x));
    }
    return result;
}