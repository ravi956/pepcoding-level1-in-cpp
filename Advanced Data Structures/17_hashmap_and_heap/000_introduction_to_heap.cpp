#include <bits/stdc++.h>
using namespace std;

int main()
{
    //By default priority queue in c++ -> max heap
    //But in java, it is min heap queue by default

    priority_queue<int> pq; // max heap
    // priority_queue<int,vector<int>,greater<>> pq; //min heap

    vector<int> ranks = {22, 99, 3, 11, 88, 4, 1};

    for (int val : ranks)
    {
        pq.push(val);
    }

    while (pq.size() > 0)
    {
        cout << pq.top() << endl;
        pq.pop();
    }

    return 0;
}