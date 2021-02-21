#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string str;
    getline(cin, str);

    stack<char> st;

    int flag = 0;
    for (char c : str)
    {
        if (c == ')')
        {
            if (st.top() != '(')
            {
                while (st.top() != '(' && st.empty() == false)
                {
                    st.pop();
                }
                if (st.empty() == false)
                    st.pop();
            }
            else
            {
                flag = 1;
                break;
            }
        }
        else
        {
            st.push(c);
        }
    }

    if (flag == 0)
        cout << "false\n";
    else
        cout << "true\n";
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