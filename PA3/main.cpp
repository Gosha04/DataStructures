#include "SpeakerView.h"

int main(int argc, char const *argv[])
{
    SpeakerView speakStack(speakStack.howBigN(argv[1]), speakStack.howBigP(argv[1]));
    speakStack.writeToStack(argv[1]);
    speakStack.countCanSee();

    return 0;
}
