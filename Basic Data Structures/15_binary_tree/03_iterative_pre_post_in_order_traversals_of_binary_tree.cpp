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

struct Pair
{
    Node *node;
    int state;

    Pair(Node *node, int state)
    {
        this->node = node;
        this->state = state;
    }
};

Node *construct(vector<int> &arr)
{
    Node *root = new Node(arr[0], NULL, NULL);
    Pair *rtp = new Pair(root, 1);

    stack<Pair *> st;
    st.push(rtp);

    int idx = 0;
    while (st.size() > 0)
    {
        Pair *top = st.top();
        if (top->state == 1)
        {
            idx++;
            if (arr[idx] != -1)
            {
                top->node->left = new Node(arr[idx], NULL, NULL);
                st.push(new Pair(top->node->left, 1));
            }
            else
            {
                top->node->left = NULL;
            }
            top->state++;
        }
        else if (top->state == 2)
        {
            idx++;
            if (arr[idx] != -1)
            {
                top->node->right = new Node(arr[idx], NULL, NULL);
                st.push(new Pair(top->node->right, 1));
            }
            else
            {
                top->node->right = NULL;
            }
            top->state++;
        }
        else
        {
            st.pop();
        }
    }
    return root;
}

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

void iterativePrePostInTraversal(Node *node)
{
    // write your code here
    string pre = "", in = "", post = "";
    stack<Pair *> st;
    st.push(new Pair(node, -1));

    while (st.size() > 0)
    {
        Pair *curr = st.top();
        st.pop();
        if (curr->state == -1)
        {
            pre += to_string(curr->node->data) + " ";
            curr->state++;
            st.push(curr);
            if (curr->node->left != NULL)
            {
                st.push(new Pair(curr->node->left, -1));
            }
        }
        else if (curr->state == 0)
        {
            in += to_string(curr->node->data) + " ";
            curr->state++;
            st.push(curr);
            if (curr->node->right != NULL)
            {
                st.push(new Pair(curr->node->right, -1));
            }
        }
        else
        {
            post += to_string(curr->node->data) + " ";
        }
    }
    cout << pre << "\n"
         << in << "\n"
         << post << "\n";
}

int main()
{
    int n;
    cin >> n;
    string str;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str == "n")
            arr[i] = -1;
        else
        {
            int temp = stoi(str);
            arr[i] = temp;
        }
    }

    Node *root = construct(arr);
    iterativePrePostInTraversal(root);
}