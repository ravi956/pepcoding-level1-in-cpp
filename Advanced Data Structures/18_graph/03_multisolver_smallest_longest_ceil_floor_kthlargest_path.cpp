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
    int wsf;
    string psf;

    Pair(int wsf, string psf)
    {
        this->wsf = wsf;
        this->psf = psf;
    }

    bool operator<(const Pair &p) const
    {
        return this->wsf > p.wsf;
    }
};

string spath, lpath, cpath, fpath;
int spathwt = INT_MAX;
int lpathwt = INT_MIN;
int cpathwt = INT_MAX;
int fpathwt = INT_MIN;

priority_queue<Pair> pq;

void multisolver(vector<Edge> graph[], int src, int dest, vector<bool> &visited, int criteria, int k, string psf, int wsf)
{
    if (src == dest)
    {
        if (wsf < spathwt)
        {
            spathwt = wsf;
            spath = psf;
        }
        if (wsf > lpathwt)
        {
            lpathwt = wsf;
            lpath = psf;
        }
        if (wsf > criteria && wsf < cpathwt)
        {
            cpathwt = wsf;
            cpath = psf;
        }
        if (wsf < criteria && wsf > fpathwt)
        {
            fpathwt = wsf;
            fpath = psf;
        }

        if (pq.size() < k)
        {
            pq.push(Pair(wsf, psf));
        }
        else
        {
            if (wsf > pq.top().wsf)
            {
                pq.pop();
                pq.push(Pair(wsf, psf));
            }
        }
        return;
    }

    visited[src] = true;
    for (Edge e : graph[src])
    {
        if (visited[e.nbr] == false)
        {
            multisolver(graph, e.nbr, dest, visited, criteria, k, psf + to_string(e.nbr), wsf + e.wt);
        }
    }
    visited[src] = false;
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

    int src, dest;
    cin >> src >> dest;

    int criteria, k;
    cin >> criteria >> k;

    vector<bool> visited(vtces, false);
    multisolver(graph, src, dest, visited, criteria, k, to_string(src), 0);

    cout << "Smallest Path = " << spath << "@" << spathwt << endl;
    cout << "Largest Path = " << lpath << "@" << lpathwt << endl;
    cout << "Just Larger Path than " << criteria << " = " << cpath << "@" << cpathwt << endl;
    cout << "Just Smaller Path than " << criteria << " = " << fpath + "@" << fpathwt << endl;
    cout << k << "th largest path = " << pq.top().psf << "@" << pq.top().wsf << endl;

    return 0;
}