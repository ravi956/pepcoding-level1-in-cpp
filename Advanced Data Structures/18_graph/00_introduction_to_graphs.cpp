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

int main()
{
    int vtces = 7; // 0, 1, 2, 3, 4, 5, 6
    vector<Edge> graph[vtces];

    graph[0].push_back(Edge(0, 3, 40));
    graph[0].push_back(Edge(0, 1, 10));

    graph[1].push_back(Edge(1, 0, 10));
    graph[1].push_back(Edge(1, 2, 10));

    graph[2].push_back(Edge(2, 3, 10));
    graph[2].push_back(Edge(2, 1, 10));

    graph[3].push_back(Edge(3, 0, 40));
    graph[3].push_back(Edge(3, 2, 10));
    graph[3].push_back(Edge(3, 4, 2));

    graph[4].push_back(Edge(4, 3, 2));
    graph[4].push_back(Edge(4, 5, 3));
    graph[4].push_back(Edge(4, 6, 3));

    graph[5].push_back(Edge(5, 4, 3));
    graph[5].push_back(Edge(5, 6, 3));

    graph[6].push_back(Edge(6, 5, 3));
    graph[6].push_back(Edge(6, 4, 8));

    return 0;
}