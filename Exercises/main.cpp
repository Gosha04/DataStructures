#include "ACStack.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    ACStack myStack(10);
    myStack.push('e');
    myStack.push('r');
    myStack.push('i');
    myStack.push('k');

    cout << myStack.peek() << endl << endl;
    cout << myStack.size() << endl << endl;

    while (!myStack.isEmpty()) {
        cout << myStack.pop() << endl;
    }


    return 0;
}
