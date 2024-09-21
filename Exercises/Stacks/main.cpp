#include "ATStack.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // Create a stack of characters with initial size 3
    ATStack<char> myStack(3);
    
    // Push characters onto the stack
    myStack.push('e');
    myStack.push('r');
    myStack.push('i');
    myStack.push('k');  // This will trigger resizing
    
    // Peek at the top element
    cout << "Top element (peek): " << myStack.peek() << endl;
    cout << "Stack size: " << myStack.size() << endl << endl;

    // Pop and print all elements
    cout << "Popping elements from stack:" << endl;
    while (!myStack.isEmpty()) {
        cout << myStack.pop() << endl;
    }

    // Create a stack of doubles with initial size 3
    ATStack<double> myStack2(3);
    
    // Push some doubles onto the stack
    myStack2.push(1.0);
    myStack2.push(2.0);
    myStack2.push(7.0);

    // Peek at the top element of myStack2
    cout << endl << "Top element (peek) in myStack2: " << myStack2.peek() << endl;
    cout << "Stack size of myStack2: " << myStack2.size() << endl;

    return 0;
}
