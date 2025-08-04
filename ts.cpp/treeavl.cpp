#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
void build(Node *&t, int x)
{
    if (t == NULL)
    {
        Node *temp = new Node();
        temp->data = x;
        temp->left = NULL;
        temp->right = NULL;
        t = temp;
    }
    else if (t->data > x)
    {
        build(t->left, x);
    }
    else
    {
        build(t->right, x);
    }
}
void turnright(Node *&t)
{
    if (!t || !t->left)
    {
        return;
    }
    Node *a = t->left;
    Node *b = a->right;
    t->left = b;
    a->right = t;
    t = a;
}
void turnleft(Node *&t)
{
    Node *a = t->right;
    Node *b = a->left;
    t->right = b;
    a->left = t;
    t = a;
}
int hight(Node *t)
{
    if (t == NULL)
    {
        return -1;
    }
    return 1 + max(hight(t->left), hight(t->right));
}
bool checkAVL(Node *t)
{
    if (t == NULL)
    {
        return true;
    }

    if (abs(hight(t->left) - hight(t->right)) > 1)
    {
        return false;
    }
    return checkAVL(t->left) && checkAVL(t->right);
}
void update(Node *&t)
{
    if (t == NULL)
    {
        return;
    }
    update(t->left);
    update(t->right);
    if (hight(t->left) - hight(t->right) > 1)
    {
        if (hight(t->left->left) < hight(t->left->right))
        {
            turnleft(t->left);
        }
        turnright(t);
    }
    else if (hight(t->left) - hight(t->right) < -1)
    {
        if (hight(t->right->left) > hight(t->right->right))
        {
            turnright(t->right);
        }
        turnleft(t);
    }
}
int countidx(Node *t, int value)
{
    if (t == NULL)
    {
        return 0;
    }
    if (t->data == value)
    {
        return 1 + countidx(t->left, value) + countidx(t->right, value);
    }
    return countidx(t->left, value) + countidx(t->right, value);
}
int main()
{
    int n;
    cin >> n;
    Node *t = NULL;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        build(t, k);
    }
    int idx;
    cin >> idx;
    while (!checkAVL(t))
    {
        update(t);
    }
    cout << countidx(t, idx) << endl;
}