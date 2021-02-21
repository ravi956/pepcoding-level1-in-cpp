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
    // write your code here
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

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int data;
    cin >> data;

    Node *root = construct(arr);
    vector<int> path = nodeToRootPath(root, data);
    cout << '[';
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];
        if (i != path.size() - 1)
            cout << ", ";
    }
    cout << ']';
    return 0;
}