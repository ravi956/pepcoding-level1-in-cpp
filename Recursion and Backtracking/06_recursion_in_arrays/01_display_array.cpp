#include <iostream>
#include <vector>
using namespace std;

void displayArr(vector<int> v, int idx)
{
    if (idx == v.size())
        return;
    cout << v[idx] << endl;
    displayArr(v, idx + 1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    displayArr(v, 0);
    return 0;
}