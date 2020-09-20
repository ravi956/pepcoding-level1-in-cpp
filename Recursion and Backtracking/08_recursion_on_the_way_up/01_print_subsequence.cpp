#include <bits/stdc++.h>
using namespace std;

void printSS(string input, string output)
{
    if (input.length() == 0)
    {
        cout << output << endl;
        return;
    }

    char ch = input[0];
    string newInput = input.substr(1);
    printSS(newInput, output + ch);
    printSS(newInput, output + "");
}

int main()
{
    string str;
    cin >> str;
    printSS(str, "");
    return 0;
}