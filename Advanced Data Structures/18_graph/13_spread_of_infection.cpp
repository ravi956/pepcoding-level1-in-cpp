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

struct Pair
{
    int v;
    int time;

    Pair(int v, int time)
    {
        this->v = v;
        this->time = time;
    }
};

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
        cin >> v1 >> v2 >> wt; // wt is here just for matching the input pattern of pepcoding , it is of no use

        graph[v1].push_back(Edge(v1, v2));
        graph[v2].push_back(Edge(v2, v1));
    }

    int src, t;
    cin >> src >> t;

    queue<Pair> q;
    q.push(Pair(src, 1));
    int visited[vtces] = {0};
    int count = 0;

    while (q.size() > 0)
    {
        Pair rem = q.front();
        q.pop();

        if (visited[rem.v] > 0)
        {
            continue;
        }
        visited[rem.v] = rem.time;
        if (rem.time > t)
        {
            break;
        }
        count++;

        for (Edge e : graph[rem.v])
        {
            if (visited[e.nbr] == 0)
            {
                q.push(Pair(e.nbr, rem.time + 1));
            }
        }
    }

    cout << count << "\n";

    return 0;
}