#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    vector<Node *> children;
};

void display(Node *node)
{
    string str = to_string(node->data) + " -> ";
    for (Node *child : node->children)
        str += to_string(child->data) + ", ";
    str += ".";

    cout << str << endl;

    for (Node *child : node->children)
        display(child);
}

Node *construct(vector<int> &arr)
{
    Node *root = NULL;
    stack<Node *> st;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == -1)
        {
            st.pop();
        }
        else
        {
            Node *t = new Node();
            t->data = arr[i];

            if (st.size() > 0)
            {
                st.top()->children.push_back(t);
            }
            else
            {
                root = t;
            }
            st.push(t);
        }
    }
    return root;
}

vector<int> nodeToRootPath(Node *node, int data)
{
    vector<int> path;
    if (node->data == data)
    {
        path.push_back(node->data);
        return path;
    }

    for (Node *child : node->children)
    {
        path = nodeToRootPath(child, data);
        if (path.size() > 0)
            break;
    }

    if (path.size() > 0)
    {
        path.push_back(node->data);
    }

    return path;
}

int lca(Node *node, int d1, int d2)
{
    // write your code here
    vector<int> path1 = nodeToRootPath(node, d1);
    vector<int> path2 = nodeToRootPath(node, d2);
    int i = path1.size() - 1;
    int j = path2.size() - 1;

    while (i >= 0 && j >= 0 && path1[i] == path2[j])
    {
        i--;
        j--;
    }
    return path1[i + 1];
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int d1, d2;
    cin >> d1 >> d2;

    Node *root = construct(arr);
    int LCA = lca(root, d1, d2);
    cout << LCA << "\n";
    return 0;
}