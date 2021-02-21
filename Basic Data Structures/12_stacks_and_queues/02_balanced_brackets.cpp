#include <bits/stdc++.h>
using namespace std;

bool compare(char c1, char c2)
{
    return ((c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}') || (c1 == '(' && c2 == ')'));
}

void solve()
{
    string str;
    getline(cin, str);

    stack<char> st;

    char c;
    for (char c : str)
    {

        if (c == '(' || c == '{' || c == '[')
            st.push(c);

        else if (c == ')' || c == '}' || c == ']')
        {
            if (st.empty())
            {
                cout << "false";
                return;
            }
            else
            {
                if (compare(st.top(), c) == false)
                {
                    cout << "false";
                    return;
                }
                else
                {
                    st.pop();
                }
            }
        }
    }
    if (st.empty())
        cout << "true";
    else
        cout << "false";
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