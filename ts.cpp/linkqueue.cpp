/*
Author : @wuan
Link :
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define endl '\n'
struct Node
{
    int data;
    Node *next;
};
Node *makeNode(int x)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
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
int Back(Node *head)
{
    return head->data;
}
int Front(Node *head)
{
    while (head->next != 0)
    {
        head = head->next;
    }
    return head->data;
}
void push(Node **head, int x)
{
    Node *temp = makeNode(x);
    temp->next = *head;
    *head = temp;
}
void pop(Node **head)
{
    Node *temp = *head;
    while (temp->next->next = NULL)
    {
        temp = temp->next;
    }
    Node *last = temp->next;
    temp->next = NULL;
    delete last;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    Node *head = NULL;
    for (int i = 0; i < 10; i++)
    {
        push(&head, i);
    }
    pop(&head);
    for (int i = 0; i < 9; i++)
    {
        cout << Front(head) << " ";
        // Back(head);
    }
    return 0;
}