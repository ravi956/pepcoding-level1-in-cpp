#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int src;
    int nbr;

    Edge(int src, int nbr)
    {
        this->src = src;
        this->nbr = nbr;
    }
};

void topologicalSort(vector<Edge> graph[], int src, bool visited[], stack<int> &st)
{
    visited[src] = true;
    for (Edge e : graph[src])
    {
        if (visited[e.nbr] == false)
        {
            topologicalSort(graph, e.nbr, visited, st);
        }
    }
    st.push(src);
}

int main()
{
    int vtces;
    cin >> vtces;

    vector<Edge> graph[vtces];

    int edges;
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(Edge(v1, v2));
    }

    // Topological sort :- A permutation of vertices for a directed acyclic graph is called
    // topological sort if for all the directed edges uv, u appears before v in the graph.

    bool visited[vtces] = {false};
    stack<int> st;

    for (int v = 0; v < vtces; v++)
    {
        if (visited[v] == false)
        {
            topologicalSort(graph, v, visited, st);
        }
    }

    while (st.size() > 0)
    {
        cout << st.top() << "\n";
        st.pop();
    }

    return 0;
}
