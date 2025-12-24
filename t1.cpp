#include <iostream>
using namespace std;

class Graph {
private:
    int** adjMatrix;
    int maxVertices;
    int n;
    bool* visited;

public:
    Graph(int maxV, int currV) {
        maxVertices = maxV;
        n = currV;

        adjMatrix = new int*[maxVertices];
        for (int i = 0; i < maxVertices; i++) {
            adjMatrix[i] = new int[maxVertices];
            for (int j = 0; j < maxVertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }

        visited = new bool[maxVertices];
        for (int i = 0; i < maxVertices; i++) {
            visited[i] = false;
        }
    }

    ~Graph() {
        for (int i = 0; i < maxVertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
        delete[] visited;
    }

    bool addVertex(int& v) {
        if (n >= maxVertices)
            return false;

        n++;
        v = n;

        for (int i = 0; i < maxVertices; i++) {
            adjMatrix[n - 1][i] = 0;
            adjMatrix[i][n - 1] = 0;
        }

        visited[n - 1] = false;
        return true;
    }

    bool addEdge(int u, int v) {
        if (u < 1 || v < 1 || u > n || v > n)
            return false;

        adjMatrix[u - 1][v - 1] = 1;
        adjMatrix[v - 1][u - 1] = 1;
        return true;
    }

    bool removeEdge(int u, int v) {
        if (u < 1 || v < 1 || u > n || v > n)
            return false;

        adjMatrix[u - 1][v - 1] = 0;
        adjMatrix[v - 1][u - 1] = 0;
        return true;
    }
    bool isEmpty();
    bool isComplete();
    void clear();
    void display();
    int Degree(int v);
};

bool Graph::isEmpty()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(adjMatrix[i][j] == 1)
                return false;
        }
    }
    return true;
}

bool Graph::isComplete()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i != j && adjMatrix[i][j] == 0)
                return false;
        }
    }
    return true;
}

void Graph::clear()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            adjMatrix[i][j] = 0;
        }
    }
}

void Graph::display()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int Graph::Degree(int v)
{
    if(v < 1 || v > n)
        return -1;

    int deg = 0;
    for(int i=1;i<=n;i++)
    {
        if(adjMatrix[v][i] == 1)
            deg++;
    }
    return deg;
}

int main() {
    Graph g(5, 0);
    int v1, v2, v3;
    g.addVertex(v1);
    g.addVertex(v2);
    g.addVertex(v3);
    cout  << v1 << " " << v2 << " " << v3 << endl;
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    cout << "Edges added between 1-2 and 2-3" << endl;
    g.removeEdge(1, 2);
    cout << "Edge removed between 1-2" << endl;
    return 0;
}
