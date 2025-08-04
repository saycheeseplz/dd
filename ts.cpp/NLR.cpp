#include <iostream>
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
    else if (t->data >= x)
    {
        build(t->left, x);
    }
    else
    {
        build(t->right, x);
    }
}
int countleaf(Node *t)
{
    if (t == NULL)
    {
        return 0;
    }
    if (t->left == NULL && t->right == NULL)
    {
        return 1;
    }
    return countleaf(t->left) + countleaf(t->right);
}
int main()
{
    int n;
    Node *t = NULL;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        build(t, k);
    }
    cout << countleaf(t);
    return 0;
}