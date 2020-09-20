#include <bits/stdc++.h>
using namespace std;

void printEncodings(string ques, string asf)
{
    if (ques.length() == 0)
    {
        cout << asf << endl;
        return;
    }
    else if (ques.length() == 1)
    {
        char ch = ques[0];
        if (ch == '0')
        {
            return;
        }
        else
        {
            int chv = ch - '0';
            char code = 'a' + chv - 1;
            asf = asf + code;
            cout << asf << endl;
        }
    }
    else
    {
        char ch = ques[0];
        string roq = ques.substr(1);

        if (ch == '0')
        {
            return;
        }
        else
        {
            int chv = ch - '0';
            char code = 'a' + chv - 1;
            printEncodings(roq, asf + code);
        }

        string ch12 = ques.substr(0, 2);
        string roq12 = ques.substr(2);

        int ch12v = stoi(ch12);
        if (ch12v <= 26)
        {
            char code = 'a' + ch12v - 1;
            printEncodings(roq12, asf + code);
        }
    }
}
int main()
{
    string str;
    cin >> str;
    printEncodings(str, "");
    return 0;
}