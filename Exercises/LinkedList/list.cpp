#include "DblList.h"
#include <iostream>
#include "PQueue.h"
using namespace std;

int main(int argc, char const *argv[]) {
    // DblList<int> myList(12);
    // myList.addFront(7);
    // myList.add(2, 4);
    // myList.remove(0);

    // cout << myList.get(0) << endl;

    PQueue<int> pq(true);
    pq.add(4);
    pq.add(3);
    pq.add(1);
    pq.add(7);

    while(!pq.isEmpty()) {
        cout << pq.remove() << endl;
    }

    return 0;
    
    return 0;
}
