#include <bits/stdc++.h>
using namespace std;

void printHashMap(unordered_map<string, int> &hm)
{
    cout << "{";
    int i = 1;
    int sz = hm.size();
    for (auto x : hm)
    {
        cout << x.first << "=" << x.second;
        if (i < sz)
            cout << ", ";
        i++;
    }
    cout << "}\n";
}

string containsKey(unordered_map<string, int> &hm, string key)
{
    if (hm.find(key) == hm.end())
        return "false";
    else
        return "true";
}

int main()
{
    unordered_map<string, int> hm;

    hm.insert({"India", 135});
    hm.insert({"China", 200});
    // we can simply use [] operator in place of insert
    hm["Pak"] = 30;
    hm["US"] = 20;
    hm["UK"] = 10;

    printHashMap(hm);

    hm["Nigeria"] = 5;
    hm["US"] = 25;

    printHashMap(hm);

    //we use find() for checking if the key exit in the hashmap
    //it returns hm.end() if the key is not present int the hashmap

    cout << containsKey(hm, "India") << endl;
    cout << containsKey(hm, "Utopia") << endl;

    for (auto x : hm)
    {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}