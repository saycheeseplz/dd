#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *makeNode(int x)
{
    Node *newNode = new Node();
    newNode->next = NULL;
    newNode->data = x;
    return newNode;
}
void show(Node *head)
{
    if (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
void pushBack(Node **head, int x)
{
    Node *temp = makeNode(x);
    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    Node *tail = *head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = temp;
}
int size(Node *head)
{
    int idx = 0;
    while (head != NULL)
    {
        idx++;
        head = head->next;
    }
    return idx;
}
void pushFront(Node **head, int x)
{
    Node *temp = makeNode(x);
    temp->next = *head;
    *head = temp;
}
void pushMid(Node **head, int k, int x)
{
    int n = size(*head);
    if (k < 1 || k > n + 1)
    {
        return;
    }
    if (k == 1)
    {
        pushFront(head, x);
        return;
    }
    Node *temp = makeNode(x);
    Node *tail = *head;
    for (int i = 1; i < k - 1; i++)
    {
        tail = tail->next;
    }
    temp->next = tail->next;
    tail->next = temp;
}
int main()
{
    int n;
    cin >> n;
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        pushBack(&head, k);
    }
    int m, k;
    cin >> m >> k;
    pushMid(&head, m, k);
    show(head);
}