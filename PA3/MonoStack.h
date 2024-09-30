#ifndef MONO_STACK_H
#define MONO_STACK_H

#include <cstdlib>
#include <iostream>
using namespace std;

template <typename T>
class MonoStack
{
private:
   T* stackArr; //array
   int count; // current size
   int top; //index of top
   int max; //max size of array
   char o; // increase vs decreasing monostack

public:
    MonoStack();
    MonoStack(int size, char type);
    virtual ~MonoStack();
    void push(T c);
    T pop();
    T monoCutShift(int index);
    T peek();
    T checkFirst();
    bool isEmpty();
    bool isFull();
    int size();   
};

template <typename T>
MonoStack<T>::MonoStack() { // O(1)
    count = 0;
    max = 0;
    top = -1;
    stackArr = NULL;
}

template <typename T>
MonoStack<T>::MonoStack(int size, char type) { // O(1)
    count = 0;
    max = size;
    top = -1;
    stackArr = new T[max];
    o = type;

    if (o != 'i' && o != 'd') {
        throw "Invalid. A monostack may only be increasing(i) or decreasing(d)";
    } 
}

template <typename T>
MonoStack<T>::~MonoStack() { // O(1)
    if(stackArr != NULL) {
        delete[] stackArr;
    }
}

template <typename T>
void MonoStack<T>::push(T c) { // O(1) or O(n)
    if (isFull()) {
       T* temp = new T[2 * max];
       for (int i = 0; i <= top; ++i) {
        temp[i] = stackArr[i];
       }
       max *= 2;
       delete[] stackArr;
       stackArr = temp;

    } else {
        if (o == 'i') {
            for (int i = count - 1; i >= 0; --i) {
                if (stackArr[i] >= c) {
                    monoCutShift(i);
                }
            }
        }

        if (o == 'd') {
            for (int i = count - 1; i > 0; --i) {
                if (stackArr[i] <= c) {
                    monoCutShift(i);
                }
            }
        }
    }

    stackArr[++top] = c;
    ++count;
}

template <typename T>
T MonoStack<T>::pop() { // O(1)
    --count;
    return stackArr[top--];
}

template <typename T>
T MonoStack<T>::monoCutShift(int index) {
    
    T cutItem = stackArr[index];

    for (int i = index; i < top; ++i) {
        stackArr[i] = stackArr[i + 1];
    }

    --top;
    --count;

    return cutItem;
}

template <typename T>
T MonoStack<T>::peek() { // O(1)
    return stackArr[top];
}

template <typename T>
T MonoStack<T>::checkFirst() {
    return stackArr[0];
}

template <typename T>
int MonoStack<T>::size() { // O(1)
    return count;
}

template <typename T>
bool MonoStack<T>::isEmpty() { // O(1)
    return top == -1;
}

template <typename T>
bool MonoStack<T>::isFull() { // O(1)
    return top == max - 1;
}


#endif