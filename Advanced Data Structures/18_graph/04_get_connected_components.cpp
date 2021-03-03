#include <bits/stdc++.h>
using namespace std;

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

void drawTreeAndGenerateComp(vector<Edge> graph[], int src, vector<int> &comp, vector<bool> &visited)
{
    visited[src] = true;
    comp.push_back(src);
    for (Edge e : graph[src])
    {
        if (visited[e.nbr] == false)
        {
            drawTreeAndGenerateComp(graph, e.nbr, comp, visited);
        }
    }
}

void print(vector<vector<int>> &v)
{
    cout << '[';
    for (int i = 0; i < v.size(); i++)
    {
        cout << '[';
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j];
            if (j != v[i].size() - 1)
                cout << ", ";
        }
        cout << ']';
        if (i != v.size() - 1)
            cout << ", ";
    }
    cout << ']';
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
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;

        graph[v1].push_back(Edge(v1, v2, wt));
        graph[v2].push_back(Edge(v2, v1, wt));
    }

    vector<vector<int>> comps;

    vector<bool> visited(vtces, false);
    for (int v = 0; v < vtces; v++)
    {
        if (visited[v] == false)
        {
            vector<int> comp;
            drawTreeAndGenerateComp(graph, v, comp, visited);
            comps.push_back(comp);
        }
    }

    print(comps);

    return 0;
}