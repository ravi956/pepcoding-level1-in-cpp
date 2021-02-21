#include <bits/stdc++.h>
using namespace std;

int precedence(char optor)
{
    if (optor == '+' || optor == '-')
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

void solve()
{
    string exp;
    getline(cin, exp);

    stack<string> post;
    stack<string> pre;
    stack<char> ops;

    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        if (ch == '(')
        {
            ops.push(ch);
        }
        else if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            string s = "";
            s += ch;
            post.push(s);
            pre.push(s);
        }
        else if (ch == ')')
        {
            while (ops.top() != '(')
            {
                char op = ops.top();
                ops.pop();

                string postv2 = post.top();
                post.pop();
                string postv1 = post.top();
                post.pop();
                string postv = postv1 + postv2 + op;
                post.push(postv);

                string prev2 = pre.top();
                pre.pop();
                string prev1 = pre.top();
                pre.pop();
                string prev = op + prev1 + prev2;
                pre.push(prev);
            }
            ops.pop();
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (ops.empty() == false && ops.top() != '(' && precedence(ops.top()) >= precedence(ch))
            {
                char op = ops.top();
                ops.pop();

                string postv2 = post.top();
                post.pop();
                string postv1 = post.top();
                post.pop();
                string postv = postv1 + postv2 + op;
                post.push(postv);

                string prev2 = pre.top();
                pre.pop();
                string prev1 = pre.top();
                pre.pop();
                string prev = op + prev1 + prev2;
                pre.push(prev);
            }
            ops.push(ch);
        }
    }

    while (ops.empty() == false)
    {
        char op = ops.top();
        ops.pop();

        string postv2 = post.top();
        post.pop();
        string postv1 = post.top();
        post.pop();
        string postv = postv1 + postv2 + op;
        post.push(postv);

        string prev2 = pre.top();
        pre.pop();
        string prev1 = pre.top();
        pre.pop();
        string prev = op + prev1 + prev2;
        pre.push(prev);
    }

    cout << post.top() << "\n";
    cout << pre.top();
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