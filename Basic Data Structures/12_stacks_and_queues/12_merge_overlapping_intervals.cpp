#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int st, et;
        cin >> st >> et;

        v.push_back({st, et});
    }

    sort(v.begin(), v.end());

    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            st.push(v[i]);
        }
        else
        {
            if (v[i].first > st.top().second)
            {
                st.push(v[i]);
            }
            else
            {
                st.top().second = max(st.top().second, v[i].second);
            }
        }
    }

    stack<pair<int, int>> rs;
    while (st.size() > 0)
    {
        rs.push(st.top());
        st.pop();
    }

    while (rs.size() > 0)
    {
        int start = rs.top().first;
        int end = rs.top().second;
        cout << start << " " << end << "\n";
        rs.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}