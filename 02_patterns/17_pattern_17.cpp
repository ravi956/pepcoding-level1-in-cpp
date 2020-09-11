#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int star = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n / 2; j++)
        {
            if (i != n / 2 + 1)
                cout << "\t";
            else
                cout << "*\t";
        }
        for (int j = 1; j <= star; j++)
            cout << "*\t";
        if (i <= n / 2)
            star++;
        else
            star--;
        cout << endl;
    }
    return 0;
}