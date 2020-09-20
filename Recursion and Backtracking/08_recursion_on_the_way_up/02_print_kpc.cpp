#include <bits/stdc++.h>
using namespace std;

vector<string> key = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string ans)
{

    if (ques.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = ques[0];
    string s = key[ch - '0'];
    string ros = ques.substr(1);
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        printKPC(ros, ans + c);
    }
}

int main()
{
    string str;
    cin >> str;
    printKPC(str, "");
    return 0;
}