#include "CQueue.h"
int main(int argc, char const *argv[])
{
    CQueue<char> cq(4);
    cq.add('e');
    cq.add('r');
    cq.add('i');
    cq.add('k');
    cout << cq.isFull() << endl;
    cq.remove();
    cq.add('l');
    cq.add('i');
    while (!cq.isEmpty()) {
        cout << cq.remove() << endl;
    }
    return 0;
}
