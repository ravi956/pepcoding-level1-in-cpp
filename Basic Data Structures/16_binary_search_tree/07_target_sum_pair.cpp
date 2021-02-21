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

bool find(Node *node, int data)
{
    if (node == NULL)
        return false;

    if (data < node->data)
        return find(node->left, data);
    else if (data > node->data)
        return find(node->right, data);
    else
        return true;
}

void travelAndPrint(Node *root, Node *node, int tar)
{
    if (node == NULL)
        return;

    travelAndPrint(root, node->left, tar);

    int comp = tar - node->data;
    if (node->data < comp && find(root, comp))
        cout << node->data << " " << comp << "\n";

    travelAndPrint(root, node->right, tar);
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

    int data;
    cin >> data;

    Node *root = construct(arr);
    travelAndPrint(root, root, data);

    return 0;
}