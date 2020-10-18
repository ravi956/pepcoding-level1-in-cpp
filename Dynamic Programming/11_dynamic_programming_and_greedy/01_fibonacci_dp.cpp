#include <iostream>
using namespace std;

int fibMemoized(int n, int *qb)
{
    if (n == 0 || n == 1)
        return n;

    if (qb[n] != 0)
        return qb[n];

    int fibnm1 = fibMemoized(n - 1, qb);
    int fibnm2 = fibMemoized(n - 2, qb);
    int fibn = fibnm1 + fibnm2;

    qb[n] = fibn;
    return fibn;
}

int main()
{
    int n;
    cin >> n;
    int qb[n + 1] = {0};
    int fibn = fibMemoized(n, qb);
    cout << fibn << endl;
    return 0;
}