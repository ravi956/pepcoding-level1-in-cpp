#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct LinkedList
{
    Node *head, *tail;
    int size;

    LinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void addLast(int val)
    {
        Node *newNode = new Node();
        newNode->data = val;
        if (size == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
};

void testList(LinkedList list)
{
    Node *ptr = list.head;

    while (ptr != NULL)
    {
        cout << ptr->data << "\n";
        ptr = ptr->next;
    }
    cout << list.size << "\n";

    if (list.size > 0)
        cout << list.tail->data << "\n";
}

int main()
{
    LinkedList list;

    string str;
    cin >> str;

    while (str != "quit")
    {
        int val;
        cin >> val;
        list.addLast(val);
        cin >> str;
    }

    testList(list);
    return 0;
}