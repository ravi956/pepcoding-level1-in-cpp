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

void IterativePreandPostOrder(Node *node)
{
    // write your code here
    stack<pair<Node *, int>> st;
    string pre = "";
    string post = "";
    st.push({node, -1});

    while (st.size() > 0)
    {
        pair<Node *, int> &_top = st.top();
        if (_top.second == -1)
        {
            pre += to_string(_top.first->data) + " ";
            _top.second++;
        }
        else if (_top.second == _top.first->children.size())
        {
            post += to_string(_top.first->data) + " ";
            st.pop();
        }
        else
        {
            pair<Node *, int> child = make_pair(_top.first->children[_top.second], -1);
            _top.second++;
            st.push(child);
        }
    }

    cout << pre << endl;
    cout << post << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Node *root = construct(arr);
    IterativePreandPostOrder(root);

    return 0;
}