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
};

template <typename T>
DblList<T>::DblList(T data) {

}

template <typename T>
DblList<T>::~DblList() {

}


#endif
