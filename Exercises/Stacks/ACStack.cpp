#include "ACStack.h"
#include <cstdlib>
using namespace std;

ACStack::ACStack() { // O(1)
    count = 0;
    max = 0;
    top = -1;
    stackArr = NULL;
}

ACStack::ACStack(int size) { // O(1)
    count = 0;
    max = size;
    top = -1;
    stackArr = new char[max];
}

ACStack::~ACStack() { // O(1)
    if(stackArr != NULL) {
        delete[] stackArr;
    }
}


void ACStack::push(char c) { // O(1) or O(n)
    if (isFull()) {
       char* temp = new char[2 * max];
       for (int i = 0; i < top; ++i) {
        temp[i] = stackArr[i];
       }
       max *= 2;
       delete[] stackArr;
       stackArr = temp;
    } else {
        stackArr[++top] = c;
        ++count;
    }
}

char ACStack::pop() { // O(1)
    --count;
    return stackArr[top--];
}

char ACStack::peek() { // O(1)
    return stackArr[top];
}

int ACStack::size() { // O(1)
    return count;
}

bool ACStack::isEmpty() { // O(1)
    return top == -1;
}

bool ACStack::isFull() { // O(1)
    return top == max - 1;
}
