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
    DblList(T data);
    virtual ~DblList();
    bool isEmpty();
    int getSize();

    void addFront(T data);
    void addBack(T data);
    void add(int pos, T data)

    void removeFront(T data);
    void removeBack(T data);
    void remove(int pos, T data);

    T get(int pos);
    bool contains(T data);
};

template <typename T>
DblList<T>::DblList(T data) {

}

template <typename T>
DblList<T>::~DblList() {

}


#endif
