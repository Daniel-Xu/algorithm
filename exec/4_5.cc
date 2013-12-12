#include <iostream>
#include <list>
#include <queue>

using namespace std;


class Graph
{
    //number of node
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    //this is every node has V edges, they can pointers to themself.
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

//from s
void Graph::BFS(int s)
{
    bool *visted = new bool[V];

    for (int i = 0; i < V; ++i)
    {
        visted[i] = false;
    }

    //queue to implement BFS
    queue<int> search;
    visted[s] = true;
    search.push(s);

    list<int>::iterator i;

    while(!search.empty()) {
        s = search.front();
        cout << s << " ";
        search.pop();

        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visted[*i]) {
                visted[*i] = true;
                search.push(*i);
            }
        }
    }
}

int main(int argc, char const *argv[])
{

    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);

    g.addEdge(1, 2);
    g.addEdge(2, 0);

    g.addEdge(2, 3);
    g.addEdge(3, 3);


    cout << "search result: " <<endl;

    g.BFS(2);
    cout << endl;
    return 0;
}
