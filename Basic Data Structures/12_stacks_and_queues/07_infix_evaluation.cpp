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

int operation(int val1, int val2, char op)
{
    if (op == '+')
    {
        return val1 + val2;
    }
    else if (op == '-')
    {
        return val1 - val2;
    }
    else if (op == '*')
    {
        return val1 * val2;
    }
    else
    {
        return val1 / val2;
    }
}

void solve()
{
    string exp;
    getline(cin, exp);

    stack<int> opd;
    stack<int> opt;

    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        if (ch == '(')
        {
            opt.push(ch);
        }
        else if (isdigit(ch))
        {
            opd.push(ch - '0');
        }
        else if (ch == ')')
        {
            while (opt.top() != '(')
            {
                int a = opd.top();
                opd.pop();
                int b = opd.top();
                opd.pop();
                char op = opt.top();
                opt.pop();
                int val = operation(b, a, op);
                opd.push(val);
            }
            opt.pop();
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (opt.empty() == false && opt.top() != '(' && precedence(opt.top()) >= precedence(ch))
            {
                int a = opd.top();
                opd.pop();
                int b = opd.top();
                opd.pop();
                char op = opt.top();
                opt.pop();
                int val = operation(b, a, op);
                opd.push(val);
            }
            opt.push(ch);
        }
    }
    while (!opt.empty())
    {
        int a = opd.top();
        opd.pop();
        int b = opd.top();
        opd.pop();
        char op = opt.top();
        opt.pop();
        int val = operation(b, a, op);
        opd.push(val);
    }

    cout << opd.top() << "\n";
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