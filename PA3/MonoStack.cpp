#include "MonoStack.h"

int main(int argc, char const *argv[])
{
    MonoStack<int> myStack(4, 'i');

    myStack.push(3);
    myStack.push(4);
    myStack.push(1);
    myStack.push(5);
    myStack.push(7);

    while (!myStack.isEmpty()) {
        cout << myStack.pop() << endl;
    }

    myStack.push(0);
    myStack.push(11);

   while (!myStack.isEmpty()) {
        cout << myStack.pop() << endl;
    }

    return 0;
}
