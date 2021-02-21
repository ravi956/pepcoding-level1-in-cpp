#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> k;

    stack<int> st;
    int nge[n];

    st.push(n - 1);
    nge[n - 1] = n;

    for (int i = n - 2; i >= 0; i--)
    {
        while (st.empty() == false && arr[st.top()] <= arr[i])
        {
            st.pop();
        }

        nge[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    int j = 0;

    for (int i = 0; i <= n - k; i++)
    {

        if (j < i)
        {
            j = i;
        }
        while (nge[j] < i + k)
        {
            j = nge[j];
        }

        cout << arr[j] << "\n";
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