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
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *getMid(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (!fast && !fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *mid = slow->next;
    slow->next = nullptr;
    return mid;
}
ListNode *merge(ListNode *l1, ListNode *l2)
{
    ListNode dummy(0);
    ListNode *temp = &dummy;
    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            temp->next = l1;
            l1 = l1->next;
        }
        else
        {
            temp->next = l2;
            l2 = l2->next;
        }
    }
    temp->next = l1 ? l1 : l2;
    return dummy.next;
}
ListNode *sortList(ListNode *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    ListNode *mid = getMid(head);
    ListNode *left = sortList(head);
    ListNode *right = sortList(mid);
    return merge(left, right);
}
void show(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    ListNode *node1 = new ListNode(4);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(1);
    ListNode *node5 = new ListNode(5);

    // Nối chúng lại với nhau
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = nullptr; // cuối danh sách
    ListNode *head = sortList(node1);
    show(head);
    return 0;
}