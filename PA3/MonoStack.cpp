#include "MonoStack.h"

int main(int argc, char const *argv[])
{
    MonoStack<double> myStack(4, 'd');

    myStack.push(50.2);
    myStack.push(80.2);
    myStack.push(90.7);
    myStack.push(92.6);
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
