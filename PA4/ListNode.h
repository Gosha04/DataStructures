/*
Joshua Vaysman
2449656
vaysman@chapman.edu 
CPSC 350-02
PA4
*/

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
    ListNode<T>* m_next;
    ListNode<T>* m_prev;

public:
    ListNode(T data);
    virtual  ~ListNode();
    
    template <typename S>
    friend class DblList;
};

template <typename T>
ListNode<T>::ListNode(T data) {
    m_next = NULL;
    m_prev = NULL;
    m_data = data;
}

template <typename T>
ListNode<T>::~ListNode() {
    m_next = NULL;
    m_prev = NULL;

}

#endif 
