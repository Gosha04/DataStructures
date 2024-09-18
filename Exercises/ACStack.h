#ifndef ACSTACK_H
#define ACSTACK_H

class ACStack
{
private:
   char* stackArr; //array
   int count; // current size
   int top; //index of top
   int max; //max size of array

public:
    ACStack();
    ACStack(int size);
    virtual ~ACStack();
    void push(char c);
    char pop();
    char peek();
    bool isEmpty();
    bool isFull();
    int size();   
};


#endif