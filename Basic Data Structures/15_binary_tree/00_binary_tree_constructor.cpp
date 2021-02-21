#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

typedef pair<Node *, int> Pair;

void display(Node *node)
{
    if (node == NULL)
        return;

    string str = "";
    str += (node->left == NULL) ? "." : to_string(node->left->data);
    str += " <- " + to_string(node->data) + " -> ";
    str += (node->right == NULL) ? "." : to_string(node->right->data);
    cout << str << "\n";

    display(node->left);
    display(node->right);
}

int main()
{
    vector<int> arr = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};

    Node *root = new Node(arr[0], NULL, NULL);
    Pair rtp = make_pair(root, 1);

    stack<Pair> st;
    st.push(rtp);

    int idx = 0;
    while (st.size() > 0)
    {
        Pair &top = st.top();
        if (top.second == 1)
        {
            idx++;
            if (arr[idx] != -1)
            {
                top.first->left = new Node(arr[idx], NULL, NULL);
                st.push({top.first->left, 1});
            }
            else
            {
                top.first->left = NULL;
            }
            top.second++;
        }
        else if (top.second == 2)
        {
            idx++;
            if (arr[idx] != -1)
            {
                top.first->right = new Node(arr[idx], NULL, NULL);
                st.push({top.first->right, 1});
            }
            else
            {
                top.first->right = NULL;
            }
            top.second++;
        }
        else
        {
            st.pop();
        }
    }

    display(root);
}