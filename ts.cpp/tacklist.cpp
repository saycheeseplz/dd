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
void pop(Node **head)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    delete temp;
}
void push(Node **head, int x)
{
    if (*head == NULL)
    {
        *head = makeNode(x);
    }
    Node *temp = makeNode(x);
    temp->next = *head;
    *head = temp;
}
bool empty(Node **head)
{
    if (head == NULL)
    {
        return true;
    }
    return false;
}
int top(Node **head)
{
    if (*head == NULL)
    {
        return NULL;
    }
    return (*head)->data;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    Node *st = NULL;
    for (int i = 0; i < 10; i++)
    {
        push(&st, i);
    }
    cout << top(&st);
    return 0;
}