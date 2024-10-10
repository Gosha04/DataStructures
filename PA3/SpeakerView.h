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
    void howBigN(string fileName);
    void howBigP(string filename);
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
    string line;
    if (getline(reader, line) && line == "BEGIN") {
        istream_iterator<double> it(reader);   // God bless geeksforgeeks and cppreference for documentation
        istream_iterator<double> end;         // Before using an iterator I kept outputting artifacts and weird symbols

        int stackNum = 0;
        while (stackNum < m_N - 1 && it != end) {
            for (int i = 0; i < m_N && it != end; ++i, ++it) {
                double value = *it;
                m_arrOfStack[i]->push(value);
            }
            stackNum++;
        }
    }
    reader.close();
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

int SpeakerView::howBigN(string fileName) {
    ifstream reader(fileName);    
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
    m_N = nSize;
}

void SpeakerView::howBigP(string fileName) {
    ifstream reader(fileName);    
    string line;
    int pSize = 1;
    if (getline(reader, line) && line == "BEGIN") {
        getline(reader, line);

        for (int i = 0; i < line.size(); i++)
            if (line[i] == ' ') {
                pSize++;
            }
    }
    reader.close();
    m_P = pSize;
}

#endif


