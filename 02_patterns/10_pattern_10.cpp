#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int pos1 = n / 2 + 1, pos2 = n / 2 + 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == pos1 || j == pos2)
                cout << "*\t";
            else
                cout << "\t";
        }
        if (i <= n / 2)
        {
            pos1--;
            pos2++;
        }
        else
        {
            pos1++;
            pos2--;
        }
        cout << endl;
    }
    return 0;
}
