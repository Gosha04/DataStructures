/*
Joshua Vaysman
2449656
vaysman@chapman.edu 
CPSC 350-02
PA3
*/

#include "SpeakerView.h"

int main(int argc, char const *argv[])
{
    SpeakerView speakStack(argv[1]);
    speakStack.writeToStack();
    speakStack.countCanSee();

    return 0;
}
