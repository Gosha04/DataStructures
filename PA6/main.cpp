#include "WGraph.h"

int main(int argc, char const *argv[])
{
    WGraph graph(argv[1]);
    graph.computeMST();
    return 0;
}
