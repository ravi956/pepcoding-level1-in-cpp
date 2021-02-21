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

bool areMirror(Node *n1, Node *n2)
{
    // write your code here
    if (n1->children.size() != n2->children.size())
    {
        return false;
    }

    int j = n1->children.size() - 1;
    for (int i = 0; i < n1->children.size(); i++)
    {
        if (areMirror(n1->children[i], n2->children[j - i]) == false)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int n1;
    cin >> n1;
    vector<int> arr1(n1);
    for (int i = 0; i < n1; i++)
        cin >> arr1[i];
    Node *root1 = construct(arr1);

    int n2;
    cin >> n2;
    vector<int> arr2(n2);
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];
    Node *root2 = construct(arr2);

    bool mirror = areMirror(root1, root2);
    if (mirror)
        cout << "true\n";
    else
        cout << "false\n";
    return 0;
}