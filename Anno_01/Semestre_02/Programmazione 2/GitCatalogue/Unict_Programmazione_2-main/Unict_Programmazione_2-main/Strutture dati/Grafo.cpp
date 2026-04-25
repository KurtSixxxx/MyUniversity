#include <iostream>

using namespace std;

class Edge{

public:
    Edge(size_t t, Edge* nx) : target(t), next(nx) {}

    size_t getTarget() const { return target;}
    Edge*  getNext() { return next;} 


private:
    size_t target;
    Edge *next;
};

class Node{
public:
    Node() : head(nullptr) {}
    ~Node();

    Edge* addEdge(size_t target);
    Edge* getHead() {return head;};


private:
    Edge* head;
};

enum nodeColor {white = 0,  grey = 1, black = 2};

class Graph{
public:
    Graph(size_t n) : num_nodes(n), color(nullptr), d(nullptr), f(nullptr), pred(nullptr) {nodes = new Node[n];}
    ~Graph() 
    {
        delete [] nodes;
        delete [] color;
        delete [] d;
        delete [] f;
        delete [] pred;
    }

    size_t getNumNodes() {return num_nodes;}
    size_t getNumEdges();

    Graph& addEdge(size_t source, size_t target)
    {
        nodes[source].addEdge(target);
        return *this;
    }

    void DFS();
    void DFS_Visit(size_t u);
    void print_DFS_results();
    const char* colorToString(nodeColor c);

    void print();

private:
// Struttura permanente del grafo
    Node* nodes;
    size_t num_nodes;

    // Variabili temporanee per DFS
    size_t* d;
    size_t* f;
    nodeColor* color; 
    int* pred;
    size_t time;
};

Edge* Node::addEdge(size_t target)
{
    Edge* newEdge = new Edge(target,head);
    head = newEdge;
    return newEdge;
}

size_t Graph::getNumEdges()
{
    size_t count = 0;

    for(size_t i=0; i<num_nodes; i++)
    {
        Edge* e = nodes[i].getHead();
        while(e)
        {
            count++;
            e = e->getNext();
        }
    }

    return count;

}

void Graph::DFS()
{
    if(color)
    {
        delete [] color; 
        delete [] d;
        delete [] f;
        delete [] pred;
    }

    color = new nodeColor[num_nodes];
    d = new size_t[num_nodes];
    f = new size_t[num_nodes];
    pred = new int[num_nodes];

    for(int i=0; i<num_nodes; i++)
    {
        color[i] = white;
        pred[i] = -1;
    }

    time = 0;

    for(int i=0; i<num_nodes; i++)
    {
        if(color[i] == white)
            DFS_Visit(i);
    }
}

void Graph::DFS_Visit(size_t u)
{
    color[u] = grey;
    d[u] = time++;
    Edge* e = nodes[u].getHead();

    while(e)
    {
        size_t v = e->getTarget();
        if(color[v] == white)
        {
            pred[v] = u;
            DFS_Visit(v);
        }

        e = e->getNext();
    }

    color[u] = black;
    f[u] = time++;
}

void Graph::print_DFS_results()
{
    for(int i=0; i<num_nodes; i++)
    {
        cout << "Node " << i << ": color=" << colorToString(color[i]) << "; d=" << d[i] << "; f" << f[i] << "; pred=" << pred[i] << endl;
    }
}

const char* Graph::colorToString(nodeColor c)
{
    static const char* names[] = {"white", "gray", "black"};
    return names[c];
}

void Graph::print()
{
    cout << "Il grafo ha " << num_nodes << " nodi" << endl;
    cout << "Gli archi sono: " << endl;

    for(int i=0; i<num_nodes; i++)
    {
        Edge* e = nodes[i].getHead();

        while(e)
        {
            cout <<  "Arco " << e << " (" << i << ", " << e->getTarget() << ") " << endl; 
            e = e->getNext();
        }
    }
}

Node::~Node()
{
    Edge* e = head;

    while(e)
    {
        Edge* succ = e->getNext();
        delete e;
        e = succ;
    }
}

int main()
{
    int n = 7;
    Graph g(n);

    g.addEdge(1,2).addEdge(1,4).addEdge(2,5).addEdge(5,4).addEdge(3,5).addEdge(3,6).addEdge(6,6);

    g.print();
    cout << "Il numero di archi e': " << g.getNumEdges() << endl;

    g.DFS();
    g.print_DFS_results();

    return 0;
}