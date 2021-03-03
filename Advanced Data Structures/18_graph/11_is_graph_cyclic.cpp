#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int src, nbr, wt;

    Edge(int src, int nbr, int wt)
    {
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};

bool isGraphCyclic(vector<Edge> graph[], int vtces)
{
    queue<int> q;
    vector<bool> visited(vtces, false);

    for (int v = 0; v < vtces; v++)
    {
        if (visited[v] == false)
        {
            q.push(v);

            while (q.size() > 0)
            {
                // r m* w a*
                int rem = q.front();
                q.pop();

                if (visited[rem] == true)
                {
                    return true;
                }
                visited[rem] = true;

                for (Edge e : graph[rem])
                {
                    if (visited[e.nbr] == false)
                    {
                        q.push(e.nbr);
                    }
                }
            }
        }
    }
    return false;
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
        cin >> v1 >> v2 >> wt; // wt is here just for matching the input pattern of pepcoding , it is of no use

        graph[v1].push_back(Edge(v1, v2, wt));
        graph[v2].push_back(Edge(v2, v1, wt));
    }

    bool cyclic = isGraphCyclic(graph, vtces);
    if (cyclic)
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}