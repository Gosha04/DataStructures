#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <cstdlib>
#include <iostream>
using namespace std;

template <typename T>
class ListNode
{
private:
    T m_data;
    ListNode<T>* m_Next();
    ListNode<T>* m_Prev();

public:
    ListNode(T data);
    virtual  ~ListNode();
    
    template <typename S>
    friend class DblList;
};

template <typename T>
ListNode<T>::ListNode(T data) {

}

template <typename T>
ListNode<T>::~ListNode() {

}

#endif 
