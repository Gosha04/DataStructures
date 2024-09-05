/*
Joshua Vaysman
2449656
vaysman@chapman.edu
CPSC 350-02
PA1
*/

#ifndef FILEP_H
#define FILEP_H

#include <string>
#include <fstream>
#include "Translator.h"

class FileProcessor
{

private:
Translator translator; // Translator object to translate sentences during processing

public:
    FileProcessor();
    virtual ~FileProcessor();
    void processString(std::string file, std::string output);
};

#endif