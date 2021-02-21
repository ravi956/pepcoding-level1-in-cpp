#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string str;
    cin >> str;

    stack<int> st;
    int num = 1;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == 'd')
        {
            st.push(num);
            num++;
        }
        else
        {
            st.push(num);
            num++;

            while (st.size() > 0)
            {
                cout << st.top();
                st.pop();
            }
        }
    }

    st.push(num);
    while (st.size() > 0)
    {
        cout << st.top();
        st.pop();
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