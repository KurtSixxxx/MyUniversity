#include <iostream>
#include "grafo.h"
using namespace std;

int main()
{
    Graph<int> g(10);

    g.addVertex(6);
    g.addVertex(5);
    g.addVertex(8);
    g.addVertex(4);
    g.addVertex(2);

    g.addEdge(5, 4);
    g.addEdge(6, 2);

    cout << g << endl;
}