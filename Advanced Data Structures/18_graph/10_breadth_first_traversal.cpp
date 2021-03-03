#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int src, nbr;

    Edge(int src, int nbr)
    {
        this->src = src;
        this->nbr = nbr;
    }
};

struct Pair
{
    int v;
    string psf;

    Pair(int v, string psf)
    {
        this->v = v;
        this->psf = psf;
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

    int src;
    cin >> src;

    queue<Pair> q;
    q.push(Pair(src, to_string(src)));
    vector<bool> visited(vtces, false);

    while (q.size() > 0)
    {
        // r m* w a*
        Pair rem = q.front();
        q.pop();

        if (visited[rem.v] == true)
        {
            continue;
        }
        visited[rem.v] = true;

        cout << rem.v << '@' << rem.psf << '\n';

        for (Edge e : graph[rem.v])
        {
            if (visited[e.nbr] == false)
            {
                q.push(Pair(e.nbr, rem.psf + to_string(e.nbr)));
            }
        }
    }

    return 0;
}