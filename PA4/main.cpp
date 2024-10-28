/*
Joshua Vaysman
2449656
vaysman@chapman.edu 
CPSC 350-02
PA4
*/

#include <iostream>
#include "PalindromeFinder.h"

int main(int argc, char const *argv[])
{
    PalindromeFinder palFind(argv[1]);
    palFind.readSequence();
    return 0;
}

