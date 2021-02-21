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

    int getSize()
    {
        return size;
    }

    void display()
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << "\n";
    }

    void removeFirst()
    {
        if (size == 0)
        {
            cout << "List is empty\n";
        }
        else if (size == 1)
        {
            Node *temp = head;
            head = tail = NULL;
            delete (temp);
            size--;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            delete (temp);
            size--;
        }
    }

    int getFirst()
    {
        if (size == 0)
        {
            cout << "List is empty\n";
            return -1;
        }
        else
        {
            return head->data;
        }
    }

    int getLast()
    {
        if (size == 0)
        {
            cout << "List is empty\n";
            return -1;
        }
        else
        {
            return tail->data;
        }
    }

    int getAt(int idx)
    {
        if (size == 0)
        {
            cout << "List is empty\n";
            return -1;
        }
        else if (idx >= size)
        {
            cout << "Invalid arguments\n";
            return -1;
        }
        else
        {
            int i = 0;
            Node *ptr = head;
            while (i < idx)
            {
                ptr = ptr->next;
                i++;
            }
            return ptr->data;
        }
    }

    void addFirst(int val)
    {
        Node *newNode = new Node();
        newNode->data = val;

        if (size == 0)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
};

int main()
{
    LinkedList list;

    string str;
    cin >> str;

    while (str != "quit")
    {
        if (str == "addLast")
        {
            int val;
            cin >> val;
            list.addLast(val);
        }
        else if (str == "size")
            cout << list.getSize() << "\n";
        else if (str == "display")
            list.display();
        else if (str == "removeFirst")
            list.removeFirst();
        else if (str == "getFirst")
        {
            int val = list.getFirst();
            if (val != -1)
                cout << val << "\n";
        }
        else if (str == "getLast")
        {
            int val = list.getLast();
            if (val != 1)
                cout << val << "\n";
        }
        else if (str == "getAt")
        {
            int idx;
            cin >> idx;
            int val = list.getAt(idx);
            if (val != -1)
                cout << val << "\n";
        }
        else if (str == "addFirst")
        {
            int val;
            cin >> val;
            list.addFirst(val);
        }
        cin >> str;
    }

    return 0;
}