#include <iostream>
#include <vector>
using namespace std;

void displayArrReverse(vector<int> v, int idx)
{
    if (idx == v.size())
        return;
    displayArrReverse(v, idx + 1);
    cout << v[idx] << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    displayArrReverse(v, 0);
    return 0;
}