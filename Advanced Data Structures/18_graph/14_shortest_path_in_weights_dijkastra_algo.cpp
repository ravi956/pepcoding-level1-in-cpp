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
    string psf;
    int wsf;

    Pair(int v, string psf, int wsf)
    {
        this->v = v;
        this->psf = psf;
        this->wsf = wsf;
    }

    bool operator<(const Pair &p) const
    {
        return this->wsf > p.wsf;
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

    int src;
    cin >> src;

    priority_queue<Pair> pq;
    pq.push(Pair(src, to_string(src), 0));
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
        cout << rem.v << " via " << rem.psf + " @ " << rem.wsf << "\n";

        for (Edge e : graph[rem.v])
        {
            if (visited[e.nbr] == false)
            {
                pq.push(Pair(e.nbr, rem.psf + to_string(e.nbr), rem.wsf + e.wt));
            }
        }
    }

    return 0;
}