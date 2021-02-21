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

    void addAt(int idx, int val)
    {
        if (idx > size)
        {
            cout << "Invalid arguments\n";
        }
        else if (idx == 0)
        {
            addFirst(val);
        }
        else if (idx == size)
        {
            addLast(val);
        }
        else
        {
            Node *ptr = head;
            Node *newNode = new Node();
            newNode->data = val;
            int i = 0;
            while (i + 1 < idx)
            {
                ptr = ptr->next;
                i++;
            }
            newNode->next = ptr->next;
            ptr->next = newNode;
            size++;
        }
    }

    void removeLast()
    {
        if (size == 0)
        {
            cout << "List is empty\n";
        }
        else if (size == 1)
        {
            Node *ptr = tail;
            head = tail = NULL;
            delete (ptr);
            size--;
        }
        else
        {
            Node *ptr = head;
            while (ptr->next != tail)
            {
                ptr = ptr->next;
            }
            tail = ptr;
            tail->next = NULL;
            ptr = ptr->next;
            delete (ptr);
            size--;
        }
    }

    void removeAt(int idx)
    {
        if (idx < 0 || idx >= size)
        {
            cout << "Invalid arguments\n";
        }
        else if (idx == 0)
        {
            removeFirst();
        }
        else if (idx == size - 1)
        {
            removeLast();
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < idx - 1; i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            size--;
        }
    }

    void reverseDI()
    {
        int i = 0, j = size - 1;
        while (i < j)
        {
            swap(getNodeAt(i)->data, getNodeAt(j)->data);
            i++;
            j--;
        }
    }

    void reversePI()
    {
        Node *pNode = NULL;
        Node *cNode = head;
        Node *nNode = NULL;

        while (cNode != NULL)
        {
            nNode = cNode->next;
            cNode->next = pNode;
            pNode = cNode;
            cNode = nNode;
        }

        swap(head, tail);
    }

    int kthFromLast(int k)
    {
        Node *fast = head;
        Node *slow = head;

        for (int i = 0; i < k; i++)
            fast = fast->next;

        while (fast != tail)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return slow->data;
    }

    int mid()
    {
        Node *slow = head;
        Node *fast = head;

        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }

    LinkedList mergeTwoSortedLinkedLists(LinkedList l1, LinkedList l2)
    {
        LinkedList l;
        Node *ptr1 = l1.head;
        Node *ptr2 = l2.head;

        while (ptr1 != NULL && ptr2 != NULL)
        {
            if (ptr2->data < ptr1->data)
            {
                l.addLast(ptr2->data);
                ptr2 = ptr2->next;
            }
            else
            {
                l.addLast(ptr1->data);
                ptr1 = ptr1->next;
            }
        }

        while (ptr1 != NULL)
        {
            l.addLast(ptr1->data);
            ptr1 = ptr1->next;
        }

        while (ptr2 != NULL)
        {
            l.addLast(ptr2->data);
            ptr2 = ptr2->next;
        }

        return l;
    }

    Node *midNode(Node *head, Node *tail)
    {
        Node *ptr1 = head;
        Node *ptr2 = head;

        while (ptr2 != tail && ptr2->next != tail)
        {
            ptr2 = ptr2->next->next;
            ptr1 = ptr1->next;
        }

        return ptr1;
    }

    LinkedList mergeSort(Node *head, Node *tail)
    {
        if (head == tail)
        {
            LinkedList temp;
            temp.addLast(head->data);
            return temp;
        }

        Node *mid = midNode(head, tail);
        LinkedList fsh = mergeSort(head, mid);
        LinkedList ssh = mergeSort(mid->next, tail);

        return mergeTwoSortedLinkedLists(fsh, ssh);
    }

    void removeDuplicates()
    {
        LinkedList res;

        while (this->size > 0)
        {
            int val = this->getFirst();
            this->removeFirst();

            if (res.getSize() == 0 || res.getLast() != val)
            {
                res.addLast(val);
            }
        }

        this->head = res.head;
        this->tail = res.tail;
        this->size = res.size;
    }

    void oddEven()
    {
        LinkedList odd;
        LinkedList even;

        while (this->size > 0)
        {
            int val = this->getFirst();
            this->removeFirst();
            if (val % 2 == 1)
            {
                odd.addLast(val);
            }
            else
            {
                even.addLast(val);
            }
        }

        if (odd.size > 0)
        {
            this->head = odd.head;
        }
        else
        {
            this->head = even.head;
        }
        if (even.size > 0)
        {
            this->tail = even.tail;
        }
        else
        {
            this->tail = odd.tail;
        }
        if (odd.size > 0 && even.size > 0)
        {
            odd.tail->next = even.head;
        }
        this->size = odd.size + even.size;
    }

    void kReverse(int k)
    {
        LinkedList prev;

        while (this->size > 0)
        {
            LinkedList curr;

            if (this->size >= k)
            {
                for (int i = 0; i < k; i++)
                {
                    int val = this->getFirst();
                    this->removeFirst();
                    curr.addFirst(val);
                }
            }
            else
            {
                int os = this->size;
                for (int i = 0; i < os; i++)
                {
                    int val = this->getFirst();
                    this->removeFirst();
                    curr.addLast(val);
                }
            }

            if (prev.size == 0)
            {
                prev = curr;
            }
            else
            {
                prev.tail->next = curr.head;
                prev.tail = curr.tail;
                prev.size += curr.size;
            }
        }

        this->head = prev.head;
        this->tail = prev.tail;
        this->size = prev.size;
    }

    void displayReverse()
    {
        displayReverseHelper(head);
        cout << endl;
    }

    void reversePR()
    {
        reversePRHelper(head);

        head->next = NULL;
        Node *temp = NULL;
        temp = head;
        head = tail;
        tail = temp;
    }

    Node *pleft;
    bool IsPalindrome()
    {
        // write your code here
        pleft = head;
        return IsPalindromeHelper(head);
    }

private:
    Node *getNodeAt(int idx)
    {
        Node *temp = head;
        for (int i = 0; i < idx; i++)
        {
            temp = temp->next;
        }
        return temp;
    }

    void displayReverseHelper(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        displayReverseHelper(node->next);
        cout << node->data << " ";
    }

    void reversePRHelper(Node *node)
    {
        if (node == tail)
        {
            return;
        }

        reversePRHelper(node->next);
        node->next->next = node;
    }

    bool IsPalindromeHelper(Node *right)
    {
        // write your code here
        if (right == NULL)
        {
            return true;
        }
        bool rres = IsPalindromeHelper(right->next);
        if (rres == false)
        {
            return false;
        }
        else if (pleft->data != right->data)
        {
            return false;
        }
        else
        {
            pleft = pleft->next;
            return true;
        }
    }
};

int main()
{
    int n1;
    cin >> n1;
    LinkedList l1;
    for (int i = 0; i < n1; i++)
    {
        int d;
        cin >> d;
        l1.addLast(d);
    }

    if (l1.IsPalindrome())
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}