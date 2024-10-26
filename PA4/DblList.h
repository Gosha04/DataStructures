#ifndef DBL_LIST_H
#define DBL_LIST_H

#include "ListNode.h"

template <typename T>
class DblList
{
private:
    int m_size;
    ListNode<T>* m_front;
    ListNode<T>* m_back;

public:
    DblList();
    DblList(T data);
    virtual ~DblList();
    bool isEmpty();
    int getSize();

    void addFront(T data);
    void addBack(T data);
    void add(int pos, T data);

    T removeFront();
    T removeBack();
    T remove(int pos);

    T get(int pos);
    bool contains(T data);
    
};

template <typename T>
DblList<T>::DblList() {
    m_size = 0;
    m_front = NULL;
    m_back = NULL;
}

template <typename T>
DblList<T>::DblList(T data) {
    m_size = 0;
    m_front = NULL;
    m_back = NULL;
    addFront(data);
}

template <typename T>
DblList<T>::~DblList() {
    while (!isEmpty()) {
        removeFront();      
    }
}

template <typename T>
bool DblList<T>::isEmpty() {
    return (m_size == 0);
}

template <typename T>
int DblList<T>::getSize() {
    return m_size;
}

template <typename T>
T DblList<T>::get(int pos) {
    if (pos < 0 || pos >= m_size) {
        throw std::out_of_range("Index out of range");
    }

    int cPos = 0;
    ListNode<T>* current = m_front;
    while(cPos !=  pos) {
        current = current -> m_next;
        ++cPos;
    }
    return current -> m_data;
}

template <typename T>
bool DblList<T>::contains(T data) {
    bool found = false;
    ListNode<T>* current = m_front;
    while(current != NULL) {
        if (current -> m_data == data){
            found = true;
            break;
        }
        current = current -> m_next;
    }
    return found;
}

template <typename T>
void DblList<T>::addFront(T data) {
    ListNode<T>* newNode = new ListNode<T>(data);
    if (!isEmpty()) {
        m_front -> m_prev = newNode;
        newNode -> m_next = m_front;
    } else {
        m_back = newNode;
    }
    m_front = newNode;
    ++m_size;
}

template <typename T>
void DblList<T>::addBack(T data) {
    ListNode<T>* newNode = new ListNode<T>(data);
    if (!isEmpty()) {
        m_back -> m_next = newNode;
        newNode -> m_prev = m_back;
    } else {
        m_front = newNode;
    }
    m_back = newNode;
    ++m_size;
}

template <typename T>
void DblList<T>::add(int pos, T data) {
    if(isEmpty() || pos == 0) {
        addFront(data);
    } else if (pos >= m_size) {
        addBack(data);
    } else {
        ListNode<T>* newNode = new ListNode<T>(data);
        int cPos = 0;
        ListNode<T>* current = m_front;
        while(cPos !=  pos) {
            current = current -> m_next;
            ++cPos;
        }
        current -> m_prev -> m_next = newNode;
        newNode -> m_prev = current -> m_prev;
        current -> m_prev = newNode;
        newNode -> m_next = current;
        delete current;
        ++m_size;
    }
}

template <typename T>
T DblList<T>::removeFront() {
    T data;
    data = m_front -> m_data;
    if (m_size == 1) {
        delete m_front;
        m_front = NULL;
        m_back = NULL;
    } else {
        ListNode<T>* currFront = m_front;
        m_front = m_front -> m_next;
        m_front -> m_prev = NULL;
        delete currFront;
    }
    --m_size;
    return data;
}

template <typename T>
T DblList<T>::removeBack() {
    T data;
    data = m_back -> m_data;
    if (m_size == 1) {
        delete m_back;
        m_front = NULL;
        m_back = NULL;
    } else {
        ListNode<T>* currBack = m_back;
        m_back = m_back -> m_next;
        m_back -> m_prev = NULL;
        delete currBack;
    }
    --m_size;
    return data;
}

template <typename T>
T DblList<T>::remove(int pos) {
    T data;
    if(pos <= 0) {
        data = removeFront();
    } else if (pos >= m_size - 1) {
        data = removeBack();
    } else {
        int cPos = 0;
        ListNode<T>* current = m_front;
        while(cPos !=  pos) {
            current = current -> m_next;
            ++cPos;
        }
        data = current -> m_data;
        current -> m_prev -> m_next = current -> m_next;
        current -> m_next -> m_prev = current -> m_prev;
        current -> m_next = NULL;
        current -> m_prev = NULL;

        delete current;
        --m_size;
    }
    return data;
}
#endif
