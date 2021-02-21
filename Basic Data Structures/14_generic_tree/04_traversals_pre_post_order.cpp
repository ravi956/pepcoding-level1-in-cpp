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

int size(Node *node)
{
    int s = 0;

    for (Node *child : node->children)
    {
        s += size(child);
    }

    s += 1;

    return s;
}

int maximum(Node *node)
{
    int m = INT_MIN;
    for (Node *child : node->children)
        m = max(m, maximum(child));

    return max(node->data, m);
}

int height(Node *node)
{
    int max_ch = -1;
    for (Node *child : node->children)
    {
        int ch = height(child);
        max_ch = max(max_ch, ch);
    }

    return 1 + max_ch;
}

void traversals(Node *node)
{
    cout << "Node Pre " << node->data << endl;
    for (Node *child : node->children)
    {
        cout << "Edge Pre " << node->data << "--" << child->data << endl;
        traversals(child);
        cout << "Edge Post " << node->data << "--" << child->data << endl;
    }
    cout << "Node Post " << node->data << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Node *root = construct(arr);
    traversals(root);

    return 0;
}