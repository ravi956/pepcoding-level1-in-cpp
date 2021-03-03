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

void clubMemberCount(vector<Edge> graph[], int src, vector<bool> &visited, int &count)
{
    visited[src] = true;
    count++;
    for (Edge e : graph[src])
    {
        if (visited[e.nbr] == false)
        {
            clubMemberCount(graph, e.nbr, visited, count);
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<Edge> graph[n];

    for (int i = 0; i < k; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        graph[v1].push_back(Edge(v1, v2));
        graph[v2].push_back(Edge(v2, v1));
    }

    vector<int> clubs;

    vector<bool> visited(n, false);
    for (int v = 0; v < n; v++)
    {
        if (visited[v] == false)
        {
            int count = 0;
            clubMemberCount(graph, v, visited, count);
            clubs.push_back(count);
        }
    }

    int result = 0;

    for (int i = 0; i < clubs.size() - 1; i++)
    {
        for (int j = i + 1; j < clubs.size(); j++)
        {
            result += clubs[i] * clubs[j];
        }
    }

    cout << result << "\n";

    return 0;
}