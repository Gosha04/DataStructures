/*
Joshua Vaysman
2449656
vaysman@chapman.edu 
CPSC 350-02
PA3
*/

#ifndef SPEAKER_VIEW_H
#define SPEAKER_VIEW_H

#include <iterator>
#include <fstream>
#include <string>
#include "MonoStack.h"

class SpeakerView 
{
private:
    MonoStack<double>** m_arrOfStack; // array to hold the stacks
    int m_N; // number of stacks
    int m_P; // size of each stack
    string inputFile;
    int howBigN();
    int howBigP();

public:
    SpeakerView(string fileName);
    virtual ~SpeakerView();
    void writeToStack();
    void countCanSee();
    void makeGrid();
};

SpeakerView::SpeakerView(string fileName) {
    inputFile = fileName;
    makeGrid();
}

SpeakerView::~SpeakerView() {
    delete[] m_arrOfStack;
}

void SpeakerView::writeToStack() {
    ifstream reader(inputFile);
    string line;
    if (getline(reader, line) && line == "BEGIN") {
        istream_iterator<double> it(reader);   // God bless geeksforgeeks and cppreference for documentation
        istream_iterator<double> end;         // Before using an iterator I kept outputting artifacts and weird symbols

        MonoStack<double>** tempStackArr = new MonoStack<double>*[m_N]; // Make a standard non-monotonic stack
        for (int tmp = 0; tmp < m_N; ++tmp) {
            tempStackArr[tmp] = new MonoStack<double>(m_P, ' ');
        }

        int stackNum = 0;
        while (stackNum < m_N && it != end) {  // Reads each line until we got all our stacks filled
            for (int i = 0; i < m_N && it != end; ++i, ++it) {
                double value = *it; // What the iterator holds
                tempStackArr[i]->push(value);
            }   
            stackNum++;
        }

        for (int j = 0; j < m_N; ++j) {
            while (!tempStackArr[j]->isEmpty()) {
                m_arrOfStack[j]->push(tempStackArr[j]->pop()); // fill up actual array of stack
            }
        }
        reader.close();
        delete[] tempStackArr;
    }
}

void SpeakerView::countCanSee() {
    for (int i = 0; i < m_N; ++i) {
        cout << "In column " << i << " there are " << m_arrOfStack[i]->size() << " who can see.";
        cout << " Their heights are: ";
        while (!m_arrOfStack[i]->isEmpty()) {
                cout << m_arrOfStack[i]->pop() << " inches ";
            }
        cout << endl;
    }
}

int SpeakerView::howBigN() {
    ifstream reader(inputFile);    
    string line;
    int nSize = 0;
    if (getline(reader, line) && line == "BEGIN") {
        while(getline(reader, line)) {
            if (line == "END") {
                break;
            }
            nSize++;
        }
    }
    reader.close();
    return nSize + 1;
}

int SpeakerView::howBigP() {
    ifstream reader(inputFile);    
    string line;
    int pSize = 0;

    if (getline(reader, line) && line == "BEGIN") {
        istream_iterator<double> it(reader);  
        istream_iterator<double> end; 

        while (it != end) {
            ++pSize;  
            if (reader.peek() == '\n') {  
                break;
            }
            ++it;
        }
    }

    reader.close();
    return pSize;
}

void SpeakerView::makeGrid() {
    m_P = howBigP();
    m_N = howBigN();

    m_arrOfStack = new MonoStack<double>*[m_N];
    for (int i = 0; i < m_N; ++i) {
        m_arrOfStack[i] = new MonoStack<double>(m_P, 'd');
    }
    
}

#endif


