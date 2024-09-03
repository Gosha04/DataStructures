/*
Joshua Vaysman
2449656
vaysman@chapman.edu
CPSC 350-02
PA1
*/


#include "Translator.h"
#include "Model.h"
#include "FileProcessor.h"

int main(int argc, char const *argv[]) {
    FileProcessor filep;

    filep.processString(argv[1], argv[2]);
    return 0;
}




