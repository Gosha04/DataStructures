#include "PQueue.h"

int main(int argc, char const *argv[])
{
    PQueue<int> pq(true);
    pq.add(11);
    pq.add(3);
    pq.add(5);
    pq.add(7);

    while(!pq.isEmpty()) {
        cout << pq.remove() << endl;
    }

    return 0;
}
