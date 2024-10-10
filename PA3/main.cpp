#include "SpeakerView.h"

int main(int argc, char const *argv[])
{
    SpeakerView speakStack(stoi(argv[1]), stoi(argv[2]));
    speakStack.writeToStack(argv[3]);
    speakStack.countCanSee();

    return 0;
}
