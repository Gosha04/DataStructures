#include "SpeakerView.h"

int main(int argc, char const *argv[])
{
    SpeakerView speakStack(5, 5);
    speakStack.writeToStack(argv[1]);
    speakStack.countCanSee();

    //cout << stod(" 23.43 ");

    return 0;
}
