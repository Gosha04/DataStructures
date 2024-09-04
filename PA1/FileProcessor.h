#ifndef FILEP_H
#define FILEP_H

#include <string>
#include <fstream>
#include "Translator.h"

class FileProcessor
{

private:
Translator translator;

public:
    FileProcessor();
    virtual ~FileProcessor();
    void processString(std::string file, std::string output);
};

#endif