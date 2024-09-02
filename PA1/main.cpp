#include "Translator.h"
#include "Model.h"
#include "FileProcessor.h"

int main(int argc, char const *argv[]) {
    FileProcessor filep;

    filep.processString(argv[1], argv[2]);
    return 0;
}




