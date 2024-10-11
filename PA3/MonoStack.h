/*
Joshua Vaysman
2449656
vaysman@chapman.edu 
CPSC 350-02
PA3
*/

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
   int m_count; // current size
   int m_top; //index of m_top
   int m_max; //m_max size of array
   char m_o; // increase vs decreasing monostack

public:
    MonoStack();
    MonoStack(int size, char type);
    virtual ~MonoStack();
    void push(T c);
    T pop();
    T peek();
    bool isEmpty();
    bool isFull();
    int size();   
};

template <typename T>
MonoStack<T>::MonoStack() { // O(1)
    m_count = 0;
    m_max = 0;
    m_top = -1;
    stackArr = nullptr;
}

template <typename T>
MonoStack<T>::MonoStack(int size, char type) { // O(1)
    m_count = 0;
    m_max = size;
    m_top = -1;
    stackArr = new T[m_max];
    m_o = type;

    if (m_o != 'i' && m_o != 'd' && m_o != ' ') {
        throw std::invalid_argument("Invalid type: A monostack may only be increasing ('i') or decreasing ('d')");
    } 
}

template <typename T>
MonoStack<T>::~MonoStack() { // O(1)
    delete[] stackArr;
}

template <typename T>
void MonoStack<T>::push(T c) { // O(1) or O(n)
    if (isFull()) {
       T* temp = new T[2 * m_max];
       for (int i = 0; i <= m_top; ++i) {
        temp[i] = stackArr[i];
       }
       m_max *= 2;
       delete[] stackArr;
       stackArr = temp;
    }
    
    if (m_o == ' ') {
        stackArr[++m_top] = c;
        ++m_count;
    } else {

        T* tempArr = new T[m_count + 1];
        int tempTop = -1;

        if (m_o == 'i') { 
            for (int i = 0; i < m_count; ++i) {
                if (stackArr[i] < c) {  
                    tempArr[++tempTop] = stackArr[i];
                }
            }
        } else if (m_o == 'd') { 
            for (int i = 0; i < m_count; ++i) {
                if (stackArr[i] > c) {  
                    tempArr[++tempTop] = stackArr[i];
                }
            }
        }

        tempArr[++tempTop] = c;
        delete[] stackArr;
        stackArr = tempArr; 
        m_top = tempTop; 
        m_count = m_top + 1;
    }
}

template <typename T>
T MonoStack<T>::pop() { // O(1)
    if (isEmpty()) {
        throw std::underflow_error("Nothing to pop");
    }
    --m_count;
    return stackArr[m_top--];
}

template <typename T>
T MonoStack<T>::peek() { // O(1)
    if (isEmpty()) {
        throw std::underflow_error("Nothing to peek at");
    }
    return stackArr[m_top];
}

template <typename T>
int MonoStack<T>::size() { // O(1)
    return m_count;
}

template <typename T>
bool MonoStack<T>::isEmpty() { // O(1)
    return m_top == -1;
}

template <typename T>
bool MonoStack<T>::isFull() { // O(1)
    return m_top == m_max - 1;
}


#endif