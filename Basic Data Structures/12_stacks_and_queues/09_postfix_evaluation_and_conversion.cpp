#include <bits/stdc++.h>
using namespace std;

int operation(int val1, int val2, char ch)
{
    if (ch == '+')
        return val1 + val2;
    else if (ch == '-')
        return val1 - val2;
    else if (ch == '*')
        return val1 * val2;
    else
        return val1 / val2;
}

void solve()
{
    string exp;
    getline(cin, exp);

    stack<int> post;
    stack<string> infix;
    stack<string> prefix;
    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        if (isdigit(ch))
        {
            post.push(ch - '0');
            string s = "";
            s += ch;
            infix.push(s);
            prefix.push(s);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            int val2 = post.top();
            post.pop();
            int val1 = post.top();
            post.pop();
            int val = operation(val1, val2, ch);
            post.push(val);

            string s2 = infix.top();
            infix.pop();
            string s1 = infix.top();
            infix.pop();
            string s = '(' + s1 + ch + s2 + ')';
            infix.push(s);

            s2 = prefix.top();
            prefix.pop();
            s1 = prefix.top();
            prefix.pop();
            s = ch + s1 + s2;
            prefix.push(s);
        }
    }

    cout << post.top() << "\n";
    cout << infix.top() << "\n";
    cout << prefix.top() << "\n";
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