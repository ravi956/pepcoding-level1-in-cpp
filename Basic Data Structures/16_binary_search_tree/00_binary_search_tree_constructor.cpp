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

Node *construct(int arr[], int lo, int hi)
{
    if (lo > hi)
    {
        return NULL;
    }

    int mid = (lo + hi) / 2;

    int data = arr[mid];
    Node *lc = construct(arr, lo, mid - 1);
    Node *rc = construct(arr, mid + 1, hi);

    Node *node = new Node(data, lc, rc);
    return node;
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

int main()
{
    int arr[] = {12, 25, 37, 50, 62, 75, 87};
    Node *root = construct(arr, 0, (sizeof(arr) / sizeof(int)) - 1);
    display(root);
    return 0;
}