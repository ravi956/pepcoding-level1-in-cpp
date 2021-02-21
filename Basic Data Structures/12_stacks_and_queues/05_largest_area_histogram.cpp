#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // rb -> right boundry -> next smallest element on right
    int rb[n];
    stack<int> st;
    rb[n - 1] = n;
    st.push(n - 1);

    for (int i = n - 2; i >= 0; i--)
    {
        while (st.empty() == false && a[st.top()] >= a[i])
        {
            st.pop();
        }

        rb[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    // lb -> left boundry -> next smallest element on left
    int lb[n];
    while (st.empty() == false)
        st.pop();
    lb[0] = -1;
    st.push(0);

    for (int i = 1; i < n; i++)
    {
        while (st.empty() == false && a[st.top()] >= a[i])
        {
            st.pop();
        }

        lb[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    // area
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        int width = rb[i] - lb[i] - 1;
        int area = a[i] * width;
        maxArea = max(maxArea, area);
    }

    cout << maxArea << "\n";
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