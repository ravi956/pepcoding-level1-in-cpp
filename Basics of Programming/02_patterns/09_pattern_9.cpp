#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int space1 = 0;
    int space2 = n - 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= space1; j++)
            cout << "\t";
        cout << "*\t";
        for (int j = 1; j <= space2; j++)
            cout << "\t";
        if (i != ((n + 1) / 2))
            cout << "*\t";
        if (i <= n / 2)
        {
            space1++;
            space2 -= 2;
        }
        else
        {
            space1--;
            space2 += 2;
        }
        cout << endl;
    }
    return 0;
}