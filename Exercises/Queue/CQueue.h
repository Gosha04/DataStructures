#ifndef CQUEUE_H
#define CQUEUE_H

#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class CQueue
{
private:
    int m_count;   // Current number of elements in the queue
    int m_front;   // Index of the front of the queue
    int m_back;    // Index of the back of the queue
    int m_max;     // Max size of the array
    T* m_arr;      // Pointer to the array for storing queue elements

public:
    CQueue();           // Default constructor
    CQueue(int size);   // Constructor with initial size
    virtual ~CQueue();          // Destructor
    void add(T value); // Enqueue (add element to the back)
    T remove();            // Dequeue (remove element from the front)
    T peek();           // Peek at the front element without removing
    bool isEmpty();     // Check if the queue is empty
    bool isFull();      // Check if the queue is full
    int size();         // Get the current number of elements in the queue
};

// Default constructor
template <typename T>
CQueue<T>::CQueue() { 
    m_count = 0;
    m_max = 0;
    m_front = 0;
    m_back = -1;
    m_arr = nullptr;
}

template <typename T>
CQueue<T>::CQueue(int size) {
    m_count = 0;
    m_max = size;
    m_front = 0;
    m_back = -1;
    m_arr = new T[m_max];
}

template <typename T>
CQueue<T>::~CQueue() {
    delete[] m_arr;
}

template <typename T>
bool CQueue<T>::isEmpty() {
    return (m_count == 0);
}

template <typename T>
bool CQueue<T>::isFull() {
    return (m_count == m_max);
}

template <typename T>
int CQueue<T>::size() {
    return m_count;
}

template <typename T>
T CQueue<T>::peek() {
    return m_arr[m_front];
}

template <typename T>
void CQueue<T>::add(T data) {
    if (!((isFull()))) { // space somewhere
        if (m_back == m_max - 1) {
            m_back = 1;
        }
        m_arr[++m_back] = data;
        ++m_count;
    } else { // truly full
        T* temp = new T[2 * m_max];
        int tc = 0;
        while (!isEmpty()) {
            temp[tc++] = remove();
        }
        delete[] m_arr;
        m_arr = temp;
        m_max *= 2;
        m_front = 0;
        m_back = m_count;
        m_arr[++m_back] = data;
        ++m_count;
    }
}

template <typename T>
T CQueue<T>::remove() {
    if (!isEmpty()) {
        T value = m_arr[m_front];
        if (m_front == m_max - 1) {
            m_front = 0; // Wrap around
        } else {
            ++m_front;
        }
        --m_count;
        return value;
    } else {
        throw runtime_error("Queue is empty. Cannot remove element.");
    }
}


#endif