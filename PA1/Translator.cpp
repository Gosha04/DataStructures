/*
Joshua Vaysman
2449656
vaysman@chapman.edu
CPSC 350-02
PA1
*/

// Implements Rober translation rules for a word and/or a sentence
// I chose to have all vowels be a private member string
// I also used 'cctype' to check if a character was alphabetical.

#include "Translator.h"

/*
Default Constructor. Initializes the string 'vowels' with all English vowels, including 'y'.
*/
Translator::Translator() : m_vowels("aeiuyo")
{
}

/* 
Default Destructor
*/
Translator::~Translator()
{
}

/*
a. translateEnglishWord
b. Returns a string 'result' which represents a word translated into Robber
c. Params: string 's' which is a single word in standard English
*/
std::string Translator::translateEnglishWord (std::string s) {
    std::string result = "";

    for (int i = 0; i < s.size(); i++) {
        if (m_vowels.find(s[i]) == std::string::npos) { // checks if a char within 's' is a vowel or consonant
            result += model.translateSingleConsonant(s[i]);
        } else {
            result += model.translateSingleVowel(s[i]); // Punctuation isn't translated it remains as is
        }
    }
    return result;
}

/*
a. translateEnglishWord
b. Returns a string 'result' which represents a sentence translated into Robber
c. Params: string 's' which is a sentence in standard English
*/
std::string Translator::translateEnglishSentence (std::string s) {
    std::string result = "";
    int wordStart = 0;
    for (int i = 0; i <= s.size(); i++) {
        if (!isalpha(s[i])) {
            if (i > wordStart) { // Makes sure that there's a word between s[i] and s[wordStart]
                result += translateEnglishWord(s.substr(wordStart, i - wordStart)); // i - wordStart removes whitespace and prevents looping
            } 
            if (i < s.size()) { // Punctuation, mainly whitespace, added back in
                result += s[i];
            }
            wordStart = i + 1;
        }  
    }
    return result;
}
