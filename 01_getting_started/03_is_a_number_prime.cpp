#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int flag = 1;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            cout << "prime";
        else
            cout << "not prime";
    }
    return 0;
}