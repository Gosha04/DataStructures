#ifndef SPEAKER_VIEW_H
#define SPEAKER_VIEW_H

#include <fstream>
#include <string>
#include "MonoStack.h"

class SpeakerView 
{
private:
    MonoStack<double>** m_arrOfStack;
    int m_N;
    int m_P;

public:
    SpeakerView();
    SpeakerView(int N, int P);
    virtual ~SpeakerView();
    void writeToStack(string fileName);
    void countCanSee();
};

SpeakerView::SpeakerView() {
    m_arrOfStack = new MonoStack<double>*[5];
    for (int i = 0; i < 5; ++i) {
        m_arrOfStack[i] = new MonoStack<double>(5, 'd');
    }
}

SpeakerView::SpeakerView(int N, int P) : m_N(N), m_P(P) {
    m_arrOfStack = new MonoStack<double>*[m_N];
    for (int i = 0; i < m_N; ++i) {
        m_arrOfStack[i] = new MonoStack<double>(m_P, 'd');
    }
}

SpeakerView::~SpeakerView() {
    
}

void SpeakerView::writeToStack(string fileName) {
    ifstream reader(fileName);    
    std::string line;
    if (std::getline(reader, line) && line == "BEGIN") {
        // God bless geeksforgeeks and cppreference for documentation
        std::istream_iterator<double> it(reader);   // Before using an iterator I kept outputting artifacts in my code
        std::istream_iterator<double> end;          // I will do my best to ask if I can keep these once my program fully works

        int stackNum = 0;
        while (stackNum < m_N && it != end) {
            for (int i = 0; i < m_P && it != end; ++i, ++it) {
                double value = *it;
                cout << "Array " << i << " value: " << value << endl;
                cout << "Size: " << m_arrOfStack[i]->isFull() << endl;
                m_arrOfStack[i]->push(value);
                cout << "\nCheck 1: " << m_arrOfStack[i]->peek() << endl;
            }
            stackNum++;
        }
    }
}

void SpeakerView::countCanSee() {
    for (int i = 0; i < m_N; ++i) {
        cout << "\nCheck 2: " << m_arrOfStack[i]->peek() << endl;
        cout << "\nSize of array " << i << ": " << m_arrOfStack[i]->size() << endl;
        cout << "Height of those that can see: " << endl;
        
        while (m_arrOfStack[i]->isEmpty() == false) {
                cout << m_arrOfStack[i]->pop() << "  ";
            }
        cout << endl;
    }
}

#endif

// template <typename T>
// int SpeakerView<T>::howBigN(string fileName) {
//     if (getline(reader, line) && line == "BEGIN") {
//         int nSize = 0;
//         while(getline(reader, line)) {
//             if (line == "END") {
//                 break;
//             }
//             nSize++;
//         }
//     }
//     return nSize;
// }

// template <typename T>
// int SpeakerView<T>::howBigP(string fileName) {
//     if (getline(reader, line) && line == "BEGIN") {
//         getline(reader, line);
        
//         int pSize = 2;
//         for (int i = 0; i < line.size(); i++)
//         if (line[i] == ' ') {
//             pSize++;
//         }
//     }
//     return pSize;
// }

