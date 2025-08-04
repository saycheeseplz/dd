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
Node *makeNode(int x)
{
    Node *newNode = new Node();
    newNode->next = NULL;
    newNode->data = x;
    return newNode;
}

void pushFront(Node **head, int x)
{
    Node *temp = makeNode(x);
    temp->next = *head;
    *head = temp;
}
void show(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
void sortHead(Node *&head) // Không nhất thiết phải truyền **head*
{
    if (!head || !head->next)
        return; // 0 hoặc 1 node → đã “sorted”

    int n = size(head); // Giả sử size() đã tính đúng

    for (int i = 0; i < n - 1; ++i)
    {                     // n−1 lượt
        Node *cur = head; // reset con trỏ ở mỗi lượt
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (cur->data > cur->next->data)
            {
                std::swap(cur->data, cur->next->data);
            }
            cur = cur->next; // DI CHUYỂN !!
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        pushFront(&head, k);
    }
    sortHead(head);
    show(head);
    return 0;
}