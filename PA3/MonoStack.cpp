#include "MonoStack.h"

int main(int argc, char const *argv[])
{
    MonoStack<double> myStack(4, 'd');

    myStack.push(81.4);
    myStack.push(90.0);
    myStack.push(80.8);
    myStack.push(82.2);
//     myStack.push(2);

//     while (!myStack.isEmpty()) {
//         cout << myStack.pop() << endl;
//     }

//     myStack.push(0);
//     myStack.push(11);

   while (!myStack.isEmpty()) {
        cout << myStack.pop() << endl;
    }

    return 0;
}
