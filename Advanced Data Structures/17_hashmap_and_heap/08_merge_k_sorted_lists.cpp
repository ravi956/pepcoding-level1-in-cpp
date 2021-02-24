#include <bits/stdc++.h>
using namespace std;

struct Pair
{
    int li;
    int di;
    int val;

    Pair(int li, int di, int val)
    {
        this->li = li;
        this->di = di;
        this->val = val;
    }
};

struct CompareVal
{
    bool operator()(Pair &p1, Pair &p2)
    {
        return p1.val > p2.val;
    }
};

vector<int> mergeKSortedLists(vector<vector<int>> &lists)
{
    vector<int> rv;

    priority_queue<Pair, vector<Pair>, CompareVal> pq;
    for (int i = 0; i < lists.size(); i++)
    {
        Pair p(i, 0, lists[i][0]);
        pq.push(p);
    }

    while (pq.size() > 0)
    {
        Pair p = pq.top();
        pq.pop();
        rv.push_back(p.val);
        p.di++;

        if (p.di < lists[p.li].size())
        {
            p.val = lists[p.li][p.di];
            pq.push(p);
        }
    }
    return rv;
}

int main()
{
    int k;
    cin >> k;

    vector<vector<int>> lists(k);

    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n;

        vector<int> list(n);
        for (int j = 0; j < n; j++)
            cin >> list[j];

        lists[i] = list;
    }

    vector<int> mlist = mergeKSortedLists(lists);
    for (int val : mlist)
        cout << val << " ";
    cout << endl;

    return 0;
}