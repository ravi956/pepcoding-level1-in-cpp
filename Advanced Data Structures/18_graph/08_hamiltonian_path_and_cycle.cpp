#include <bits/stdc++.h>
using namespace std;

int graph_size;

struct Edge
{
    int src;
    int nbr;
    int wt;

    Edge(int src, int nbr, int wt)
    {
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};

void hamiltonian(vector<Edge> graph[], int src, unordered_set<int> &visited, string psf, int osrc)
{
    if (visited.size() == graph_size - 1)
    {
        cout << psf;

        bool closingEdgeFound = false;
        for (Edge e : graph[src])
        {
            if (e.nbr == osrc)
            {
                closingEdgeFound = true;
                break;
            }
        }

        if (closingEdgeFound)
            cout << "*\n";
        else
            cout << ".\n";

        return;
    }

    visited.insert(src);

    for (Edge e : graph[src])
    {
        if (visited.find(e.nbr) == visited.end())
        {
            hamiltonian(graph, e.nbr, visited, psf + to_string(e.nbr), osrc);
        }
    }

    visited.erase(src);
}

int main()
{
    int vtces;
    cin >> vtces;
    graph_size = vtces;

    vector<Edge> graph[vtces];

    int edges;
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;

        graph[v1].push_back(Edge(v1, v2, wt));
        graph[v2].push_back(Edge(v2, v1, wt));
    }

    int src;
    cin >> src;

    unordered_set<int> visited;
    hamiltonian(graph, src, visited, to_string(src), src);

    return 0;
}