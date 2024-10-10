#ifndef P_QUEUE_H
#define P_QUEUE_H

#include "DblList.h"
#include <cstdlib>
#include <iostream>
using namespace std;

template <typename T> 
class PQueue {

public:
    PQueue(bool isMin);
    virtual ~PQueue();
    void add(T data);
    T remove();
    T peek();
    int size();
    bool isEmpty();

private:
    DblList<T>* m_list;
    bool isMinQ;

};

template <typename T> 
PQueue<T>::PQueue(bool isMin) {
    isMinQ = isMin;
    m_list = new DblList<T>();
}

template <typename T> 
PQueue<T>::~PQueue() {
    delete m_list;
}

template <typename T> 
void PQueue<T>::add(T data) {
    if (isEmpty()) {
        m_list->addFront(data);
    } else {
        ListNode<T>* newNode = new ListNode<T>(data);
        int currIndex = 0;
        ListNode<T>* currNode = m_list->m_front;
        while(currNode != NULL && currNode->m_data < data) {
            currNode = currNode->m_next;
            ++currIndex;
        }
        m_list->add(currIndex, data); //easy, but 2x slower
        //smart thing is patch in manually
        /*
        currNOde -> m_prev -> m_next = newNode;
        newNode -> m_prev = current -> m_prev;
        currNode -> m_prev = newNode;
        newNode -> m_next = currNode;
        delete current;
        */
    }
}

template <typename T> 
T PQueue<T>::remove() {
    if (isMinQ) {
        return m_list->removeFront();
    } else {
       return  m_list->removeBack();
    }
}

template <typename T> 
T PQueue<T>::peek() {
    if (isMinQ) {
        return m_list->get(0);
    } else {
        return m_list->get(size() - 1);
    }
}

template <typename T> 
int PQueue<T>::size() {
    return m_list->getSize();
}

template <typename T> 
bool PQueue<T>::isEmpty() {
    return m_list->isEmpty();
}

#endif