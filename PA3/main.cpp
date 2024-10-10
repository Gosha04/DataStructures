#include "SpeakerView.h"

int main(int argc, char const *argv[])
{
    SpeakerView speakStack(argv[1]);
    speakStack.writeToStack();
    speakStack.countCanSee();

    return 0;
}
