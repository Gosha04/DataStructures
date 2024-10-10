#ifndef ATSTACK_H
#define ATSTACK_H

#include <cstdlib>
using namespace std;

template <typename T>
class ATStack
{
private:
   T* stackArr; //array
   int count; // current size
   int top; //index of top
   int max; //max size of array

public:
    ATStack();
    ATStack(int size);
    virtual ~ATStack();
    void push(T c);
    T pop();
    T peek();
    bool isEmpty();
    bool isFull();
    int size();   
};

template <typename T>
ATStack<T>::ATStack() { // O(1)
    count = 0;
    max = 0;
    top = -1;
    stackArr = NULL;
}

template <typename T>
ATStack<T>::ATStack(int size) { // O(1)
    count = 0;
    max = size;
    top = -1;
    stackArr = new T[max];
}

template <typename T>
ATStack<T>::~ATStack() { // O(1)
    if(stackArr != NULL) {
        delete[] stackArr;
    }
}

template <typename T>
void ATStack<T>::push(T c) { // O(1) or O(n)
    if (isFull()) {
       T* temp = new T[2 * max];
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

template <typename T>
T ATStack<T>::pop() { // O(1)
    --count;
    return stackArr[top--];
}

template <typename T>
T ATStack<T>::peek() { // O(1)
    return stackArr[top];
}

template <typename T>
int ATStack<T>::size() { // O(1)
    return count;
}

template <typename T>
bool ATStack<T>::isEmpty() { // O(1)
    return top == -1;
}

template <typename T>
bool ATStack<T>::isFull() { // O(1)
    return top == max - 1;
}


#endif