/*
    it should have:
        - left child ptr
        - right child ptr
        - data for node, any type (T)
*/

#ifndef TREE_NODE_H
#define TREE_NODE_H
#include <cstdlib>    // TO USE NULL
using namespace std;

template <typename T>
class TreeNode{ 
    public:
        TreeNode(T d);
        virtual ~TreeNode();
        T getData();
        /*
        Make BST a friend class of TreeNode

        Normally, the private and protected members of a class can only be accessed by 
        the class itself and its derived classes. 
        However, by declaring another class as a "friend," the class allows that other 
        class to access its private and protected members directly.
        */
       template <typename R>
       friend class BST;
       
    private:
        T m_data;
        TreeNode<T>* m_left; 
        TreeNode<T>* m_right;
};


template <typename T>
TreeNode<T>::TreeNode(T d){
    m_data = d;
    m_left = NULL;
    m_right = NULL;
}

template <typename T>
TreeNode<T>::~TreeNode(){
    m_left = NULL;
    m_right = NULL;
}

template <typename T>
T TreeNode<T>::getData(){
    return m_data;
}

#endif