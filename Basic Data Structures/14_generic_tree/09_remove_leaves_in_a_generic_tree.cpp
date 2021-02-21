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

void levelOrderLinewiseZigzag(Node *node)
{
    stack<Node *> ms;
    stack<Node *> cs;
    ms.push(node);
    bool flag = 1;

    while (ms.size() > 0)
    {
        Node *curr = ms.top();
        ms.pop();
        cout << curr->data << " ";

        if (flag)
        {
            for (Node *child : curr->children)
            {
                cs.push(child);
            }
        }
        else
        {
            for (int i = curr->children.size() - 1; i >= 0; i--)
            {
                cs.push(curr->children[i]);
            }
        }

        if (ms.size() == 0)
        {
            swap(ms, cs);
            flag = !flag;
            cout << endl;
        }
    }
}

void mirror(Node *node)
{
    reverse(node->children.begin(), node->children.end());

    for (Node *child : node->children)
    {
        mirror(child);
    }
}

void removeLeaves(Node *node)
{
    for (auto it = node->children.begin(); it != node->children.end(); it++)
    {
        // can also be done by replacing child with (*it) and without creating the child variable
        Node *child = *it;
        if (child->children.size() == 0)
        {
            node->children.erase(it);
            it--;
        }
        else
            removeLeaves(child);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Node *root = construct(arr);
    removeLeaves(root);
    display(root);

    return 0;
}