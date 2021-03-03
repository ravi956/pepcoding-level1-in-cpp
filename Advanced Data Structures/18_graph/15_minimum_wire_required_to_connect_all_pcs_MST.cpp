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

struct Pair
{
    int v;
    int av;
    int wt;

    Pair(int v, int av, int wt)
    {
        this->v = v;
        this->av = av;
        this->wt = wt;
    }

    bool operator<(const Pair &p) const
    {
        return this->wt > p.wt;
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
        cin >> v1 >> v2 >> wt;

        graph[v1].push_back(Edge(v1, v2, wt));
        graph[v2].push_back(Edge(v2, v1, wt));
    }

    priority_queue<Pair> pq;
    pq.push(Pair(0, -1, 0));
    bool visited[vtces] = {0};

    while (pq.size() > 0)
    {
        Pair rem = pq.top();
        pq.pop();

        if (visited[rem.v] == true)
        {
            continue;
        }

        visited[rem.v] = true;

        if (rem.av != -1)
            cout << "[" << rem.v << "-" << rem.av << "@" << rem.wt << "]\n";

        for (Edge e : graph[rem.v])
        {
            if (visited[e.nbr] == false)
            {
                pq.push(Pair(e.nbr, rem.v, e.wt));
            }
        }
    }

    return 0;
}