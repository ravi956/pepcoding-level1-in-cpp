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
    string psf; // this is not required
    int level;

    Pair(int v, string psf, int level)
    {
        this->v = v;
        this->psf = psf;
        this->level = level;
    }
};

bool checkComponentForBipartiteness(vector<Edge> graph[], int src, vector<int> &visited)
{
    queue<Pair> q;
    q.push(Pair(src, to_string(src), 0));

    while (q.size() > 0)
    {
        Pair rem = q.front();
        q.pop();

        if (visited[rem.v] != -1)
        {
            if (rem.level != visited[rem.v])
            {
                return false;
            }
        }
        else
        {
            visited[rem.v] = rem.level;
        }

        for (Edge e : graph[rem.v])
        {
            if (visited[e.nbr] == -1)
            {
                q.push(Pair(e.nbr, rem.psf + to_string(e.nbr), rem.level + 1));
            }
        }
    }

    return true;
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

    /*
	A graph is said to be bipartite if it is possible to divide vertices into 2
	mutually exclusive sets such that all edges are across sets. All non-cyclic
	graphs are bipartite. In Cyclic graph, if there is any cycle of odd no. of
	vertices then the graph is non-bipartite otherwise the graph is bipartite.
	*/

    vector<int> visited(vtces, -1);
    for (int v = 0; v < vtces; v++)
    {
        if (visited[v] == -1)
        {
            bool isCompBipartite = checkComponentForBipartiteness(graph, v, visited);
            if (isCompBipartite == false)
            {
                cout << "false\n";
                return 0;
            }
        }
    }

    cout << "true\n";
    return 0;
}