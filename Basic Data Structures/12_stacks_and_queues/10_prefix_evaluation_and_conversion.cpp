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

    stack<int> pre;
    stack<string> infix;
    stack<string> postfix;
    for (int i = exp.length(); i >= 0; i--)
    {
        char ch = exp[i];

        if (isdigit(ch))
        {
            pre.push(ch - '0');
            string s = "";
            s += ch;
            infix.push(s);
            postfix.push(s);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            int val1 = pre.top();
            pre.pop();
            int val2 = pre.top();
            pre.pop();
            int val = operation(val1, val2, ch);
            pre.push(val);

            string s1 = infix.top();
            infix.pop();
            string s2 = infix.top();
            infix.pop();
            string s = '(' + s1 + ch + s2 + ')';
            infix.push(s);

            s1 = postfix.top();
            postfix.pop();
            s2 = postfix.top();
            postfix.pop();
            s = s1 + s2 + ch;
            postfix.push(s);
        }
    }

    cout << pre.top() << "\n";
    cout << infix.top() << "\n";
    cout << postfix.top() << "\n";
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