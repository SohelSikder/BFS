#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
void insert_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}
void print_linekd_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
Node *deleteDuplicates(Node *&head)
{
    Node *tmp = head;
    if (head == NULL)
        return head;
    while (tmp->next != NULL)
    {
        if (tmp->val == tmp->next->val)
        {
            tmp->next = tmp->next->next;
        }
        else if (tmp->next == NULL)
        {
            break;
        }
        else if (tmp->val != tmp->next->val)
        {
            tmp = tmp->next;
        }
    }
    return head;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        Node *head = NULL;
        Node *tail = NULL;
        int n;
        cin >> n;
        int val;
        for (int i = 0; i < n; i++)
        {
            cin >> val;
            insert_tail(head, tail, val);
        }

        for (Node *i = head; i->next != NULL; i = i->next)
        {
            for (Node *j = i->next; j != NULL; j = j->next)
            {
                if (i->val > j->val)
                {
                    swap(i->val, j->val);
                }
            }
        }
        head = deleteDuplicates(head);

        print_linekd_list(head);
    }

    return 0;
}