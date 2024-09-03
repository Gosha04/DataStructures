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

/*
a. main
b. Returns 0 as an int
c. Params:
    - 'argc': the number of arguments as an int
    - 'argv': vector for the command line arguments
*/
int main(int argc, char const *argv[]) {
    FileProcessor filep;

    filep.processString(argv[1], argv[2]);
    return 0;
}




